/*****************************************************************************

 @(#) $RCSfile: ss7OmMIB.c,v $ $Name:  $($Revision: 0.9.2.11 $) $Date: 2009-01-19 13:31:51 $

 -----------------------------------------------------------------------------

 Copyright (c) 2008-2009  Monavacon Limited <http://www.monavacon.com/>
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

 -----------------------------------------------------------------------------

 Last Modified $Date: 2009-01-19 13:31:51 $ by $Author: brian $

 -----------------------------------------------------------------------------

 $Log: ss7OmMIB.c,v $
 Revision 0.9.2.11  2009-01-19 13:31:51  brian
 - updating standalone agents

 Revision 0.9.2.10  2009-01-16 20:45:01  brian
 - updating mibs and agents

 Revision 0.9.2.9  2009-01-14 14:30:07  brian
 - working up agents

 Revision 0.9.2.8  2009-01-10 17:09:22  brian
 - updated agents

 Revision 0.9.2.7  2009-01-04 13:16:06  brian
 - updated agents

 Revision 0.9.2.6  2009-01-03 10:51:07  brian
 - updated agent

 Revision 0.9.2.5  2009-01-02 15:46:44  brian
 - corrections

 Revision 0.9.2.4  2009-01-02 15:04:16  brian
 - updated agents

 Revision 0.9.2.3  2008-12-31 16:04:47  brian
 - updated mibs

 Revision 0.9.2.2  2008-12-24 13:08:26  brian
 - building ss7confd

 *****************************************************************************/

#ident "@(#) $RCSfile: ss7OmMIB.c,v $ $Name:  $($Revision: 0.9.2.11 $) $Date: 2009-01-19 13:31:51 $"

static char const ident[] = "$RCSfile: ss7OmMIB.c,v $ $Name:  $($Revision: 0.9.2.11 $) $Date: 2009-01-19 13:31:51 $";

/* This file was generated by mib2c and is intended for use as
   a mib module for the ucd-snmp snmpd agent. */
#include <ucd-snmp/ucd-snmp-config.h>
#include <ucd-snmp/ucd-snmp-includes.h>
#include <ucd-snmp/ucd-snmp-agent-includes.h>
#include <ucd-snmp/agent_trap.h>
#include <ucd-snmp/callback.h>
#include <ucd-snmp/snmp-tc.h>
#include <ucd-snmp/default_store.h>
#include <ucd-snmp/snmp_alarm.h>
/* The following header files are mangled in most recent net-snmp releases so
 * the versions from UCD-SNMP 4.2.5 are included here.  */
#if defined HAVE_LIBNETSNMP
#else				/* defined HAVE_LIBNETSNMP */
#endif				/* defined HAVE_LIBNETSNMP */
/* These are messed up on both. */
#include "ds_agent.h"
#ifdef HAVE_UCD_SNMP_UTIL_FUNCS_H
#include <ucd-snmp/util_funcs.h>
/* Many recent net-snmp UCD compatible headers do not declare header_generic. */
int header_generic(struct variable *, oid *, size_t *, int, size_t *, WriteMethod **);
#else				/* HAVE_UCD_SNMP_UTIL_FUNCS_H */
#include "util_funcs.h"
#endif				/* HAVE_UCD_SNMP_UTIL_FUNCS_H */
#ifdef HAVE_UCD_SNMP_HEADER_COMPLEX_H
#include <ucd-snmp/header_complex.h>
#else				/* HAVE_UCD_SNMP_HEADER_COMPLEX_H */
#include "header_complex.h"
#endif				/* HAVE_UCD_SNMP_HEADER_COMPLEX_H */
/* This one is the other way around: it is just fine for net-snmp, but
 * ucd-snmp does not provide the header file at all.  */
#ifdef HAVE_UCD_SNMP_MIB_MODULES_H
#include <ucd-snmp/mib_modules.h>
#else				/* HAVE_UCD_SNMP_MIB_MODULES_H */
#ifdef HAVE_NET_SNMP_AGENT_MIB_MODULES_H
#include <net-snmp/agent/mib_modules.h>
#else				/* HAVE_NET_SNMP_AGENT_MIB_MODULES_H */
#include "mib_modules.h"
#endif				/* HAVE_NET_SNMP_AGENT_MIB_MODULES_H */
#endif				/* HAVE_UCD_SNMP_MIB_MODULES_H */
#include <stdint.h>
#include <signal.h>
#include <sys/stat.h>		/* for struct stat, fstat() */
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>		/* for getpwuid() getpwnam() */
#include <grp.h>		/* for getgrgid() getgrnam() */
#include <libgen.h>		/* for basename() */
#include <fcntl.h>		/* for O_CREAT */
#include <sys/sysctl.h>		/* for sysctl */
#include <errno.h>
#include <string.h>
#ifdef _GNU_SOURCE
#include <getopt.h>
#endif
#include "ss7OmMIB.h"
#define MY_FACILITY(__pri)	(LOG_DAEMON|(__pri))
#if defined MODULE
#if defined MASTER
const char sa_program[] = "ss7OmMIB";
int sa_fclose = 1;			/* default close files between requests */
int sa_changed = 1;			/* indication to reread MIB configuration */
int sa_stats_refresh = 1;		/* indications that statistics, the mib or its tables need to be refreshed */
int sa_request = 1;			/* request number for per-request actions */
int sa_dump = 0;			/* default packet dump */
int sa_debug = 0;			/* default no debug */
#endif				/* defined MASTER */
#endif				/* defined MODULE */
static int my_fd = -1;			/* file descriptor for this MIB's use */
static int my_readfd = -1;		/* file descriptor for autonomnous events */
volatile int ss7OmMIB_refresh = 1;

/*
 * ss7OmMIB_variables_oid: object identifier for ss7OmMIB
 * This is the top level oid that we want to register under.  This is essentially a prefix, with the
 * suffix appearing in the variable below.
 */
oid ss7OmMIB_variables_oid[10] = { 1, 3, 6, 1, 4, 1, 29591, 17, 752, 0 };

/*
 * Oids for use in notifications defined in this MIB.
 */
oid mtpRestarting_oid[12] = { 1, 3, 6, 1, 4, 1, 29591, 17, 752, 0, 0, 1 };
oid ss7OnOccEvent_oid[12] = { 1, 3, 6, 1, 4, 1, 29591, 17, 752, 0, 0, 2 };

/*
 * Oids accessible only for notify defined in this MIB.
 */
oid pointCode_oid[13] = { 1, 3, 6, 1, 4, 1, 29591, 17, 752, 0, 1, 3, 1 };

/*
 * Other oids defined in this MIB.
 */

static oid zeroDotZero_oid[2] = { 0, 0 };
static oid snmpTrapOID_oid[11] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0 };

/*
 * variable4 ss7OmMIB_variables: tree for ss7OmMIB
 * This variable defines function callbacks and type return information for the ss7OmMIB mib section
 */
struct variable4 ss7OmMIB_variables[] = {
	/* magic number, variable type, ro/rw, callback fn, L, oidsuffix */

};

/* (L = length of the oidsuffix) */
struct ss7OmMIB_data *ss7OmMIBStorage = NULL;

/* global storage of our data, saved in and configured by header_complex() */

void (*ss7OmMIBold_signal_handler) (int) = NULL;	/* save old signal handler just in case */
void ss7OmMIB_loop_handler(int);
void ss7OmMIB_fd_handler(int, void *);

/**
 * @fn void init_ss7OmMIB(void)
 * @brief ss7OmMIB initialization routine.
 *
 * This is called when the agent starts up.  At a minimum, registration of the MIB variables
 * structure (ss7OmMIB_variables) should take place here.  By default the function also
 * registers the configuration handler and configuration store callbacks.
 *
 * Additional registrations that may be considered here are calls to regsiter_readfd(),
 * register_writefd() and register_exceptfd() for hooking into the snmpd event loop, but only when
 * used as a loadable module.  By default this function establishes a single file descriptor to
 * read, or upon which to handle exceptions.  Note that the snmpd only supports a maximum of 32
 * extneral file descriptors, so these should be used sparingly.
 *
 * When running as a loadable module, it is also necessary to hook into the snmpd event loop so that
 * the current request number can be deteremined.  This is accomplished by using a trick of the
 * external_signal_scheduled and external_signal_handler mechanism which is called on each event
 * loop when external_signal_scheduled is non-zero.  This is used to increment the sa_request value
 * on each snmpd event loop interation so that calls to MIB tree functions can determine whether
 * they belong to a fresh request or not (primarily for cacheing and possibly to clean up non-polled
 * file descriptors).
 */
void
init_ss7OmMIB(void)
{
	(void) my_fd;
	(void) zeroDotZero_oid;
	(void) snmpTrapOID_oid;
	DEBUGMSGTL(("ss7OmMIB", "init_ss7OmMIB: initializing...  "));
	/* register ourselves with the agent to handle our mib tree */
	REGISTER_MIB("ss7OmMIB", ss7OmMIB_variables, variable4, ss7OmMIB_variables_oid);
	snmp_register_callback(SNMP_CALLBACK_LIBRARY, SNMP_CALLBACK_SHUTDOWN, term_ss7OmMIB, NULL);
	/* register our config handler(s) to deal with registrations */
	snmpd_register_config_handler("ss7OmMIB", parse_ss7OmMIB, NULL, "HELP STRING");
	/* we need to be called back later to store our data */
	snmp_register_callback(SNMP_CALLBACK_LIBRARY, SNMP_CALLBACK_STORE_DATA, store_ss7OmMIB, NULL);
	/* place any other initialization junk you need here */
	if (my_readfd >= 0) {
		register_readfd(my_readfd, ss7OmMIB_fd_handler, (void *) 0);
		register_exceptfd(my_readfd, ss7OmMIB_fd_handler, (void *) 1);
	}
	ss7OmMIBold_signal_handler = external_signal_handler[SIGCHLD];
	external_signal_handler[SIGCHLD] = &ss7OmMIB_loop_handler;
	external_signal_scheduled[SIGCHLD] = 1;
	DEBUGMSGTL(("ss7OmMIB", "done.\n"));
}

/**
 * @fn void deinit_ss7OmMIB(void)
 * @brief deinitialization routine.
 *
 * This is called before the agent is unloaded.  At a minimum, deregistration of the MIB variables
 * structure (ss7OmMIB_variables) should take place here.  By default, the function also
 * deregisters the the configuration file handlers for the MIB variables and table rows.
 *
 * Additional deregistrations that may be required here are calls to unregister_readfd(),
 * unregister_writefd() and unregsiter_exceptfd() for unhooking from the snmpd event loop, but only
 * when used as a loadable module.  By default if a read file descriptor exists, it is unregistered.
 */
void
deinit_ss7OmMIB(void)
{
	DEBUGMSGTL(("ss7OmMIB", "deinit_ss7OmMIB: deinitializating...  "));
	external_signal_handler[SIGCHLD] = ss7OmMIBold_signal_handler;
	if (my_readfd >= 0) {
		unregister_exceptfd(my_readfd);
		unregister_readfd(my_readfd);
		close(my_readfd);
		my_readfd = -1;
	}
	unregister_mib(ss7OmMIB_variables_oid, sizeof(ss7OmMIB_variables_oid) / sizeof(oid));
	snmpd_unregister_config_handler("ss7OmMIB");
	/* place any other de-initialization junk you need here */
	DEBUGMSGTL(("ss7OmMIB", "done.\n"));
}

int
term_ss7OmMIB(int majorID, int minorID, void *serverarg, void *clientarg)
{
	DEBUGMSGTL(("ss7OmMIB", "term_ss7OmMIB: terminating...  "));
	deinit_ss7OmMIB();
	DEBUGMSGTL(("ss7OmMIB", "done.\n"));
	return 0;
}

/**
 * @fn struct ss7OmMIB_data *ss7OmMIB_create(void)
 * @brief create a fresh data structure representing scalars in ss7OmMIB.
 *
 * Creates a new ss7OmMIB_data structure by allocating dynamic memory for the structure and
 * initializing the default values of scalars in ss7OmMIB.
 */
struct ss7OmMIB_data *
ss7OmMIB_create(void)
{
	struct ss7OmMIB_data *StorageNew = SNMP_MALLOC_STRUCT(ss7OmMIB_data);

	DEBUGMSGTL(("ss7OmMIB", "ss7OmMIB_create: creating scalars...  "));
	if (StorageNew != NULL) {
		/* XXX: fill in default scalar values here into StorageNew */

	}
	DEBUGMSGTL(("ss7OmMIB", "done.\n"));
	return (StorageNew);
}

/**
 * @fn int ss7OmMIB_destroy(struct ss7OmMIB_data **thedata)
 * @param thedata pointer to the data structure in ss7OmMIB.
 * @brief delete a scalars structure from ss7OmMIB.
 *
 * Frees scalars that were previously removed from ss7OmMIB.  Note that the strings associated
 * with octet strings, object identifiers and bit strings still attached to the structure will also
 * be freed.  The pointer that was passed in @param thedata will be set to NULL if it is not already
 * NULL.
 */
int
ss7OmMIB_destroy(struct ss7OmMIB_data **thedata)
{
	struct ss7OmMIB_data *StorageDel;

	DEBUGMSGTL(("ss7OmMIB", "ss7OmMIB_destroy: deleting scalars...  "));
	if ((StorageDel = *thedata) != NULL) {
		SNMP_FREE(StorageDel);
		*thedata = StorageDel;
	}
	DEBUGMSGTL(("ss7OmMIB", "done.\n"));
	return SNMPERR_SUCCESS;
}

/**
 * @fn int ss7OmMIB_add(struct ss7OmMIB_data *thedata)
 * @param thedata the structure representing ss7OmMIB scalars.
 * @brief adds node to the ss7OmMIB scalar data set.
 *
 * Adds a scalar structure to the ss7OmMIB data set.  Note that this function is necessary even
 * when the scalar values are not peristent.
 */
int
ss7OmMIB_add(struct ss7OmMIB_data *thedata)
{
	DEBUGMSGTL(("ss7OmMIB", "ss7OmMIB_add: adding data...  "));
	if (thedata)
		ss7OmMIBStorage = thedata;
	DEBUGMSGTL(("ss7OmMIB", "done.\n"));
	return SNMPERR_SUCCESS;
}

/**
 * @fn void parse_ss7OmMIB(const char *token, char *line)
 * @param token token used within the configuration file.
 * @param line line from configuration file matching the token.
 * @brief parse configuration file for ss7OmMIB entries.
 *
 * This callback is called by UCD-SNMP when it prases a configuration file and finds a configuration
 * file line for the registsred token (in this case ss7OmMIB).  This routine is invoked by
 * UCD-SNMP to read the values of scalars in the MIB from the configuration file.  Note that this
 * procedure may exist regardless of the persistence of the MIB.  If there are no configured entries
 * in the configuration MIB, this function will simply not be called.
 */
void
parse_ss7OmMIB(const char *token, char *line)
{
	size_t tmpsize;
	struct ss7OmMIB_data *StorageTmp = ss7OmMIB_create();

	DEBUGMSGTL(("ss7OmMIB", "parse_ss7OmMIB: parsing config...  "));
	if (StorageTmp == NULL) {
		config_perror("malloc failure");
		return;
	}
	/* XXX: remove individual scalars that are not persistent */
	ss7OmMIB_add(StorageTmp);
	(void) tmpsize;
	DEBUGMSGTL(("ss7OmMIB", "done.\n"));
}

/*
 * store_ss7OmMIB(): stores .conf file entries needed to configure the mib.
 */
int
store_ss7OmMIB(int majorID, int minorID, void *serverarg, void *clientarg)
{
	char line[SNMP_MAXBUF];
	char *cptr;
	size_t tmpsize;
	struct ss7OmMIB_data *StorageTmp;

	DEBUGMSGTL(("ss7OmMIB", "store_ss7OmMIB: storing data...  "));
	refresh_ss7OmMIB(1);
	if ((StorageTmp = ss7OmMIBStorage) == NULL) {
		DEBUGMSGTL(("ss7OmMIB", "error.\n"));
		return SNMPERR_GENERR;
	}
	(void) tmpsize;
	/* XXX: comment entire section if no scalars are persistent */
	{
		memset(line, 0, sizeof(line));
		strcat(line, "ss7OmMIB ");
		cptr = line + strlen(line);
		/* XXX: remove individual scalars that are not persistent */
		snmpd_store_config(line);
	}
	DEBUGMSGTL(("ss7OmMIB", "done.\n"));
	return SNMPERR_SUCCESS;
}

/**
 * @fn void refresh_ss7OmMIB(int force)
 * @param force forced refresh when non-zero.
 * @brief refresh the scalar values of ss7OmMIB.
 *
 * Normally the values retrieved from the operating system are cached.  When the agent receives a
 * SIGPOLL from an open STREAMS configuration or administrative driver Stream, the STREAMS subsystem
 * indicates to the agent that the cache has been invalidated and that it should reread scalars and
 * tables from the STREAMS subsystem.  This function is used when the agent starts for the first
 * time, or after a SIGPOLL has been received (and a scalar has been requested).
 */
void
refresh_ss7OmMIB(int force)
{
	if (ss7OmMIBStorage == NULL) {
		struct ss7OmMIB_data *StorageNew;

		if ((StorageNew = ss7OmMIB_create()) == NULL)
			return;
		ss7OmMIBStorage = StorageNew;
		ss7OmMIB_refresh = 1;
	}
	if (!force && ss7OmMIB_refresh == 0)
		return;
	DEBUGMSGTL(("ss7OmMIB", "refresh_ss7OmMIB: refreshing...  "));
	/* XXX: Update scalars as required here... */
	ss7OmMIB_refresh = 0;
	DEBUGMSGTL(("ss7OmMIB", "done.\n"));
}

/**
 * @fn u_char * var_ss7OmMIB(struct variable *vp, oid *name, size_t *length, int exact, size_t *var_len, WriteMethod **write_method)
 * @param vp a pointer to the entry in the variables table for the requested variable.
 * @param name the object identifier for which to find.
 * @param length the length of the object identifier.
 * @param exact whether the name is exact.
 * @param var_len a pointer to the length of the representation of the object.
 * @param write_method a pointer to a write method for the object.
 * @brief locate variables in ss7OmMIB.
 *
 * This function returns a pointer to a memory area that is static across the request that contains
 * the UCD-SNMP representation of the scalar (so that it may be used to read from for a GET,
 * GET-NEXT or GET-BULK request).  This returned pointer may be NULL, in which case the function is
 * telling UCD-SNMP that the scalar does not exist for reading; however, if write_method is
 * overwritten with a non-NULL value, the function is telling UCD-SNMP that the scalar exists for
 * writing.  Write-only objects can be effected in this way.
 */
u_char *
var_ss7OmMIB(struct variable *vp, oid * name, size_t *length, int exact, size_t *var_len, WriteMethod ** write_method)
{
	struct ss7OmMIB_data *StorageTmp;
	u_char *rval;

	DEBUGMSGTL(("ss7OmMIB", "var_ss7OmMIB: lookup up varbind...  "));
	if (header_generic(vp, name, length, exact, var_len, write_method) == MATCH_FAILED)
		return NULL;
	/* Refresh the MIB values if required. */
	refresh_ss7OmMIB(0);
	if ((StorageTmp = ss7OmMIBStorage) == NULL) {
		DEBUGMSGTL(("ss7OmMIB", "no datastructure.\n"));
		return NULL;
	}
	*write_method = NULL;
	*var_len = 0;
	rval = NULL;
	/* This is where we do the value assignments for the mib results. */
	switch (vp->magic) {
	default:
		ERROR_MSG("");
	}
	if (rval)
		DEBUGMSGTL(("ss7OmMIB", "found.\n"));
	else
		DEBUGMSGTL(("ss7OmMIB", "not found.\n"));
	return (rval);
}

void
send_mtpRestarting_v2trap(struct variable_list *vars)
{
	struct variable_list trap;

	DEBUGMSGTL(("ss7OmMIB", "send_mtpRestarting_v2trap: sending trap...  "));
	trap.next_variable = vars;
	trap.name = snmpTrapOID_oid;
	trap.name_length = sizeof(snmpTrapOID_oid) / sizeof(oid);
	trap.type = ASN_OBJECT_ID;
	trap.val.objid = mtpRestarting_oid;
	trap.val_len = sizeof(mtpRestarting_oid);
	trap.index = 0;
	send_v2trap(&trap);
	DEBUGMSGTL(("ss7OmMIB", "done.\n"));
}

void
send_ss7OnOccEvent_v2trap(struct variable_list *vars)
{
	struct variable_list trap;

	DEBUGMSGTL(("ss7OmMIB", "send_ss7OnOccEvent_v2trap: sending trap...  "));
	trap.next_variable = vars;
	trap.name = snmpTrapOID_oid;
	trap.name_length = sizeof(snmpTrapOID_oid) / sizeof(oid);
	trap.type = ASN_OBJECT_ID;
	trap.val.objid = ss7OnOccEvent_oid;
	trap.val_len = sizeof(ss7OnOccEvent_oid);
	trap.index = 0;
	send_v2trap(&trap);
	DEBUGMSGTL(("ss7OmMIB", "done.\n"));
}

/**
 * @fn void ss7OmMIB_loop_handler(int dummy)
 * @param sig signal number
 * @brief handle event loop interation.
 *
 * This function is registered so that, when operating as a module, snmpd will call it one per event
 * loop interation.  This function is called before the next requst is processed and after the
 * previous request is processed.  Two things are done here:  1) The file descriptor that is used to
 * synchronize the agent with (pseudo-)device drivers is closed.  (Another approach, instead of
 * closing each time, would be to restart a timer each time that a request is made (loop is
 * performed) and if it expires, close the file descriptor).  2) The request number is incremented.
 * Although a request is not generated for each loop of the snmp event loop, it is true that a new
 * request cannot be generated without performing a loop.  Therefore, the sa_request is not the
 * request number but it is a temporally unique identifier for a request.
 */
void
ss7OmMIB_loop_handler(int sig)
{
	DEBUGMSGTL(("ss7OmMIB", "ss7OmMIB_loop_handler: executing loop handler...  "));
	/* close files after each request */
	if (sa_fclose) {
		if (my_fd >= 0) {
			close(my_fd);
			my_fd = -1;
		}
	}
#if defined MASTER
	/* prepare for next request */
	sa_request++;
#endif				/* defined MASTER */
	if (external_signal_scheduled[sig] == 0)
		external_signal_scheduled[sig]--;
	if (ss7OmMIBold_signal_handler != NULL)
		(*ss7OmMIBold_signal_handler) (sig);
	DEBUGMSGTL(("ss7OmMIB", "done.\n"));
}

/**
 * @fn void ss7OmMIB_fd_handler(int fd, void *dummy)
 * @param fd file descriptor to read.
 * @param dummy client data passed to registration function (always NULL).
 * @brief handle read event on file descriptor.
 *
 * This read file descriptor handler is normally used for (pseudo-)device drivers that generate
 * statistical collection interval events, alarm events, or other operational measurement events, by
 * placing a message on the read queue of the "event handling" Stream.  Normally this routine
 * would adjust counts in some table or scalars, generate SNMP traps representing on-occurence
 * events, first and interval events, and alarm indications.
 */
void
ss7OmMIB_fd_handler(int fd, void *dummy)
{
	DEBUGMSGTL(("ss7OmMIB", "ss7OmMIB_fd_handler: executing fd handler...  "));
	/* XXX: place actions to handle my_fd here... */
	DEBUGMSGTL(("ss7OmMIB", "done.\n"));
	return;
}