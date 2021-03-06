/*****************************************************************************

 @(#) File: src/kernel/aixcompat.c

 -----------------------------------------------------------------------------

 Copyright (c) 2008-2015  Monavacon Limited <http://www.monavacon.com/>
 Copyright (c) 2001-2008  OpenSS7 Corporation <http://www.openss7.com/>
 Copyright (c) 1997-2001  Brian F. G. Bidulock <bidulock@openss7.org>

 All Rights Reserved.

 This program is free software: you can redistribute it and/or modify it under
 the terms of the GNU Affero General Public License as published by the Free
 Software Foundation, version 3 of the license.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
 details.

 You should have received a copy of the GNU Affero General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>, or
 write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA
 02139, USA.

 -----------------------------------------------------------------------------

 U.S. GOVERNMENT RESTRICTED RIGHTS.  If you are licensing this Software on
 behalf of the U.S. Government ("Government"), the following provisions apply
 to you.  If the Software is supplied by the Department of Defense ("DoD"), it
 is classified as "Commercial Computer Software" under paragraph 252.227-7014
 of the DoD Supplement to the Federal Acquisition Regulations ("DFARS") (or any
 successor regulations) and the Government is acquiring only the license rights
 granted herein (the license rights customarily provided to non-Government
 users).  If the Software is supplied to any unit or agency of the Government
 other than DoD, it is classified as "Restricted Computer Software" and the
 Government's rights in the Software are defined in paragraph 52.227-19 of the
 Federal Acquisition Regulations ("FAR") (or any successor regulations) or, in
 the cases of NASA, in paragraph 18.52.227-86 of the NASA Supplement to the FAR
 (or any successor regulations).

 -----------------------------------------------------------------------------

 Commercial licensing and support of this software is available from OpenSS7
 Corporation at a fee.  See http://www.openss7.com/

 *****************************************************************************/

static char const ident[] = "src/kernel/aixcompat.c (" PACKAGE_ENVR ") " PACKAGE_DATE;

/* 
 *  This is my solution for those who don't want to inline GPL'ed functions or
 *  who don't use optimizations when compiling or specifies
 *  -fnoinline-functions or something of the like.  This file implements all
 *  of the extern inlines from the header files by just including the header
 *  files with the functions declared 'inline' instead of 'extern inline'.
 *
 *  There are implemented here in a separate object, out of the way of the
 *  modules that don't use them.
 */

#define __AIX_EXTERN_INLINE __inline__ streamscall __unlikely
#define __AIX_EXTERN streamscall

#define _AIX_SOURCE

#include "sys/os7/compat.h"

#define AIXCOMP_DESCRIP		"AIX 5L Version 5.1 Compatibility for Linx Fast-STREAMS"
#define AIXCOMP_EXTRA		"Part of hUNIX SYSTEM V RELEASE 4.2 FAST STREAMS FOR LINUX"
#define AIXCOMP_COPYRIGHT	"Copyright (c) 2008-2015  Monavacon Limited.  All Rights Reserved."
#define AIXCOMP_REVISION	"OpenSS7 src/kernel/aixcompat.c (" PACKAGE_ENVR ") " PACKAGE_DATE
#define AIXCOMP_DEVICE		"AIX 5L Version 5.1 Compatibility"
#define AIXCOMP_CONTACT		"Brian Bidulock <bidulock@openss7.org>"
#define AIXCOMP_LICENSE		"GPL"
#define AIXCOMP_BANNER		AIXCOMP_DESCRIP		"\n" \
				AIXCOMP_EXTRA		"\n" \
				AIXCOMP_COPYRIGHT	"\n" \
				AIXCOMP_REVISION	"\n" \
				AIXCOMP_DEVICE		"\n" \
				AIXCOMP_CONTACT		"\n"
#define AIXCOMP_SPLASH		AIXCOMP_DEVICE		" - " \
				AIXCOMP_REVISION	"\n"

#ifdef CONFIG_STREAMS_COMPAT_AIX_MODULE
MODULE_AUTHOR(AIXCOMP_CONTACT);
MODULE_DESCRIPTION(AIXCOMP_DESCRIP);
MODULE_SUPPORTED_DEVICE(AIXCOMP_DEVICE);
MODULE_LICENSE(AIXCOMP_LICENSE);
#if defined MODULE_ALIAS
MODULE_ALIAS("streams-aixcompat");
#endif
#ifdef MODULE_VERSION
MODULE_VERSION(PACKAGE_ENVR);
#endif
#endif

/* 
 *  MI_OPEN_COMM, MI_CLOSE_COMM, MI_NEXT_PTR, MI_PREV_PTR and MI_BUFCALL
 *  -------------------------------------------------------------------------
 *  implemented in mspcompat.c
 */

/* 
 *  WANTIO
 *  -------------------------------------------------------------------------
 */
__AIX_EXTERN int
wantio(queue_t *q, struct wantio *w)
{
	queue_t *wq = WR(q);
	struct stdata *sd = ((struct queinfo *) (wq - 1))->qu_str;

	if (w) {
		// qget(wq);
		sd->sd_directio = w;
	} else {
		sd->sd_directio = w;
		// qput(&wq);
	}
	return (0);
}

EXPORT_SYMBOL(wantio);		/* aix/ddi.h */

/* 
 *  WANTMSG
 *  -------------------------------------------------------------------------
 */
__AIX_EXTERN_INLINE int wantmsg(queue_t *q, int streamscall (*func) (mblk_t *));

EXPORT_SYMBOL(wantmsg);		/* aix/ddi.h */

/* 
 *  STR_INSTALL
 *  -------------------------------------------------------------------------
 */
__AIX_EXTERN int
str_install_AIX(int cmd, strconf_t * sc)
{
	if (!sc)
		return (EINVAL);
	switch (cmd) {
	case STR_LOAD_DEV:
		{
			struct cdevsw *cdev;
			int err;

#ifdef MAX_CHRDEV
			if (0 >= sc->sc_major || sc->sc_major >= MAX_CHRDEV)
#else
			if (sc->sc_major != MAJOR(MKDEV(sc->sc_major, 0)))
#endif
				return (EINVAL);
			/* We don't do old-style opens */
			if (!(sc->sc_open_stylesc_flags & STR_NEW_OPEN))
				return (ENOSYS);
			if (!(cdev = kmem_zalloc(sizeof(*cdev), KM_NOSLEEP)))
				return (ENOMEM);
			cdev->d_name = sc->sc_name;
			cdev->d_str = sc->sc_str;
			/* build flags */
			cdev->d_flag = 0;
			if (sc->sc_open_stylesc_flags & STR_MPSAFE) {
				cdev->d_flag |= D_MP;
			}
			if (sc->sc_open_stylesc_flags & STR_PERSTREAM) {
				cdev->d_flag |= D_UP;
			}
			if (sc->sc_open_stylesc_flags & STR_Q_NOTTOSPEC) {
				cdev->d_flag |= D_BLKING;
			}
			if (sc->sc_open_stylesc_flags & STR_QSAFETY) {
				cdev->d_flag |= D_SAFE;
			}
			if (sc->sc_open_stylesc_flags & STR_NEWCLONING) {
				cdev->d_flag |= D_CLONE;
			}
			switch ((cdev->d_sqlvl = sc->sc_sqlevel)) {
			case SQLVL_NOP:
				cdev->d_flag |= D_MP;
				break;
				/* Note that because AIX supports mps_become_writer(), that it must 
				   have an outer perimeter when SQLVL_QUEUE or SQLVL_QUEUEPAIR is
				   set.  mps_become_writer() is like qwriter() for the outer
				   perimeter. */
			case SQLVL_QUEUE:
				cdev->d_flag |= D_MTPERQ | D_MTOUTPERIM;
				break;
			case SQLVL_QUEUEPAIR:
				cdev->d_flag |= D_MTQPAIR | D_MTOUTPERIM;
				break;
			case SQLVL_DEFAULT:
				cdev->d_sqlvl = SQLVL_MODULE;
			case SQLVL_MODULE:
				cdev->d_flag |= D_MTPERMOD;
				break;
			case SQLVL_ELSEWHERE:
				cdev->d_sqinfo = sc->sc_sqinfo;
				break;
			case SQLVL_GLOBAL:
				/* This is true global synchronization, reducing all modules
				   performing sycnrhonization to single threaded. */
				break;
			}
			if ((err = register_strdev(cdev, sc->sc_major)) < 0)
				kmem_free(cdev, sizeof(*cdev));
			return (-err);
		}
	case STR_UNLOAD_DEV:
		{
			struct cdevsw *cdev;
			int err;

			if (0 >= sc->sc_major || sc->sc_major >= MAX_STRDEV)
				return (EINVAL);
			if ((cdev = sdev_get(sc->sc_major)) == NULL)
				return (ENOENT);
			printd(("%s: %s: got device\n", __FUNCTION__, cdev->d_name));
			printd(("%s: %s: putting device\n", __FUNCTION__, cdev->d_name));
			sdev_put(cdev);
			if ((err = unregister_strdev(cdev, sc->sc_major)) == 0)
				kmem_free(cdev, sizeof(*cdev));
			return (-err);
		}
	case STR_LOAD_MOD:
		{
			struct fmodsw *fmod;
			int err;

			if (!sc->sc_str || !sc->sc_str->st_rdinit
			    || !sc->sc_str->st_rdinit->qi_minfo)
				return (EINVAL);
			if (0 >= sc->sc_major || sc->sc_major >= MAX_STRDEV)
				return (EINVAL);
			/* We don't do old-style opens */
			if (!(sc->sc_open_stylesc_flags & STR_NEW_OPEN))
				return (ENOSYS);
			if (!(fmod = kmem_zalloc(sizeof(*fmod), KM_NOSLEEP)))
				return (ENOMEM);
			fmod->f_name = sc->sc_name;
			fmod->f_str = sc->sc_str;
			/* build flags */
			fmod->f_flag = 0;
			if (sc->sc_open_stylesc_flags & STR_MPSAFE) {
				fmod->f_flag |= D_MP;
			}
			if (sc->sc_open_stylesc_flags & STR_PERSTREAM) {
				fmod->f_flag |= D_UP;
			}
			if (sc->sc_open_stylesc_flags & STR_Q_NOTTOSPEC) {
				fmod->f_flag |= D_BLKING;
			}
			if (sc->sc_open_stylesc_flags & STR_QSAFETY) {
				fmod->f_flag |= D_SAFE;
			}
			if (sc->sc_open_stylesc_flags & STR_NEWCLONING) {
				fmod->f_flag |= D_CLONE;
			}
			switch ((fmod->f_sqlvl = sc->sc_sqlevel)) {
			case SQLVL_NOP:
				fmod->f_flag |= D_MP;
				break;
				/* Note that because AIX supports mps_become_writer(), that it must 
				   have an outer perimeter when SQLVL_QUEUE or SQLVL_QUEUEPAIR is
				   set.  mps_become_writer() is like qwriter() for the outer
				   perimeter. */
			case SQLVL_QUEUE:
				fmod->f_flag |= D_MTPERQ | D_MTOUTPERIM;
				break;
			case SQLVL_QUEUEPAIR:
				fmod->f_flag |= D_MTQPAIR | D_MTOUTPERIM;
				break;
			case SQLVL_DEFAULT:
				fmod->f_sqlvl = SQLVL_MODULE;
			case SQLVL_MODULE:
				fmod->f_flag |= D_MTPERMOD;
				break;
			case SQLVL_ELSEWHERE:
				fmod->f_sqinfo = sc->sc_sqinfo;
				break;
			case SQLVL_GLOBAL:
				/* This is true global synchronization, reducing all modules
				   performing sycnrhonization to single threaded. */
				break;
			}
			if ((err = register_strmod(fmod)) < 0)
				kmem_free(fmod, sizeof(*fmod));
			return (-err);
		}
	case STR_UNLOAD_MOD:
		{
			struct fmodsw *fmod;
			int err;

			if (!(fmod = fmod_str(sc->sc_str)))
				return (ENOENT);
			if ((err = unregister_strmod(fmod)) == 0)
				kmem_free(fmod, sizeof(fmod));
			return (-err);
		}
	}
	return (EINVAL);
}

EXPORT_SYMBOL(str_install_AIX);	/* strconf.h */

#ifdef CONFIG_STREAMS_COMPAT_AIX_MODULE
static
#endif
int __init
aixcomp_init(void)
{
#ifdef CONFIG_STREAMS_COMPAT_AIX_MODULE
	printk(KERN_INFO AIXCOMP_BANNER);
#else
	printk(KERN_INFO AIXCOMP_SPLASH);
#endif
	return (0);
}

#ifdef CONFIG_STREAMS_COMPAT_AIX_MODULE
static
#endif
void __exit
aixcomp_exit(void)
{
	return;
}

#ifdef CONFIG_STREAMS_COMPAT_AIX_MODULE
module_init(aixcomp_init);
module_exit(aixcomp_exit);
#endif
