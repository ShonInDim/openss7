/*****************************************************************************

 @(#) $Id$

 -----------------------------------------------------------------------------

 Copyright (c) 2008-2009  Monavacon Limited <http://www.monavacon.com/>
 Copyright (c) 2001-2008  OpenSS7 Corporation <http://www.openss7.com/>
 Copyright (c) 1997-2001  Brian F. G. Bidulock <bidulock@openss7.org>

 All Rights Reserved.

 This program is free software; you can redistribute it and/or modify it under
 the terms of the GNU Affero General Public License as published by the Free
 Software Foundation; version 3 of the License.

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

 Last Modified $Date$ by $Author$

 -----------------------------------------------------------------------------

 $Log$
 *****************************************************************************/

#ifndef __LOCAL_STREXTMIB_H__
#define __LOCAL_STREXTMIB_H__

#ident "@(#) $RCSfile$ $Name$($Revision$) Copyright (c) 2008-2009 Monavacon Limited."

/*
 * This file was generated by mib2c and is intended for use as a mib module
 * for the ucd-snmp snmpd agent.
 */

#undef MASTER
extern const char sa_program[];
extern int sa_fclose;			/* default close files between requests */
extern int sa_changed;			/* indication to reread MIB configuration */
extern int sa_stats_refresh;		/* indications that statistics, the mib or its tables need to be refreshed */
extern int sa_request;			/* request number for per-request actions */

/* our storage structure(s) */
struct strExtMIB_data {
	uint strExtMIB_request;
	ulong strExtStrlogRecordNextIndex;	/* ReadOnly */
	ulong strNlogargs;		/* ReadWrite */
	ulong strExtLogMsgSize;		/* ReadWrite */
	long strExtConsoleLog;		/* ReadWrite */
	long strExtErrorLog;		/* ReadWrite */
	long strExtTraceLog;		/* ReadWrite */
};
struct strExtStrlogRecordTable_data {
	uint strExtStrlogRecordTable_request;
	uint strExtStrlogRecordTable_refs;
	ulong strExtStrlogRecordIndex;	/* NoAccess */
	long strExtStrlogRecordSeqNo;	/* ReadOnly */
	uint8_t *strExtStrlogRecordDateAndTime;	/* ReadOnly */
	size_t strExtStrlogRecordDateAndTimeLen;
	long strExtStrlogRecordTimeStamp;	/* ReadOnly */
	ulong strExtStrlogRecordMid;	/* Create */
	ulong strExtStrlogRecordSid;	/* Create */
	ulong strExtStrlogRecordLevel;	/* Create */
	uint8_t *strExtStrlogRecordFlags;	/* Create */
	size_t strExtStrlogRecordFlagsLen;
	uint8_t *strExtStrlogRecordMsgString;	/* Create */
	size_t strExtStrlogRecordMsgStringLen;
	long strExtStrlogRecordRowStatus;	/* Create */
};
struct strExtTraceTable_data {
	uint strExtTraceTable_request;
	uint strExtTraceTable_refs;
	ulong strExtTraceId;		/* NoAccess */
	long strExtTraceMid;		/* Create */
	long strExtTraceSid;		/* Create */
	long strExtTraceLevel;		/* Create */
	long strExtTraceRowStatus;	/* Create */
};

/* storage declarations */
extern struct strExtMIB_data *strExtMIBStorage;
extern struct header_complex_index *strExtStrlogRecordTableStorage;
extern struct header_complex_index *strExtTraceTableStorage;

/* enum definitions from the covered mib sections */

#define STREXTSTRLOGRECORDFLAGS_SLERROR          0
#define STREXTSTRLOGRECORDFLAGS_SLTRACE          1
#define STREXTSTRLOGRECORDFLAGS_SLNOTIFY         2
#define STREXTSTRLOGRECORDFLAGS_SLCONSOLE        3
#define STREXTSTRLOGRECORDFLAGS_SLFATAL          4
#define STREXTSTRLOGRECORDFLAGS_SLWARN           5
#define STREXTSTRLOGRECORDFLAGS_SLNOTE           6
#define STREXTSTRLOGRECORDFLAGS_SLNOPUTBUF       7

#define STREXTCONSOLELOG_TRUE                    1
#define STREXTCONSOLELOG_FALSE                   2

#define STREXTERRORLOG_TRUE                      1
#define STREXTERRORLOG_FALSE                     2

#define STREXTTRACELOG_TRUE                      1
#define STREXTTRACELOG_FALSE                     2

#define STREXTSTRLOGFLAGS_SLERROR                0
#define STREXTSTRLOGFLAGS_SLTRACE                1
#define STREXTSTRLOGFLAGS_SLNOTIFY               2
#define STREXTSTRLOGFLAGS_SLCONSOLE              3
#define STREXTSTRLOGFLAGS_SLFATAL                4
#define STREXTSTRLOGFLAGS_SLWARN                 5
#define STREXTSTRLOGFLAGS_SLNOTE                 6
#define STREXTSTRLOGFLAGS_SLNOPUTBUF             7

/* notifications */
extern oid strStrlogRecord_oid[11];

/* scalars accessible only for notify */
extern oid strExtStrlogIndex_oid[13];
extern oid strExtStrlogSeqNo_oid[13];
extern oid strExtStrlogDateAndTime_oid[13];
extern oid strExtStrlogTimeStamp_oid[13];
extern oid strExtStrlogMid_oid[13];
extern oid strExtStrlogSid_oid[13];
extern oid strExtStrlogLevel_oid[13];
extern oid strExtStrlogFlags_oid[13];
extern oid strExtStrlogFmtString_oid[13];
extern oid strExtStrlogInteger_oid[13];
extern oid strExtStrlogUnsigned_oid[13];
extern oid strExtStrlogString_oid[13];
extern oid strExtStrlogInteger64_oid[13];
extern oid strExtStrlogUnsigned64_oid[13];
extern oid strExtStrlogInteger128_oid[13];
extern oid strExtStrlogUnsigned128_oid[13];

/* object id definitions */

/* function prototypes */
/* trap function prototypes */
extern void send_strStrlogRecord_v2trap(struct variable_list *);

/* variable function prototypes */
void init_strExtMIB(void);
void deinit_strExtMIB(void);
int term_strExtMIB(int majorID, int minorID, void *serverarg, void *clientarg);
FindVarMethod var_strExtMIB;
void parse_strExtMIB(const char *, char *);
SNMPCallback store_strExtMIB;
void refresh_strExtMIB(int);
FindVarMethod var_strExtStrlogRecordTable;
struct strExtStrlogRecordTable_data *strExtStrlogRecordTable_create(void);
struct strExtStrlogRecordTable_data *strExtStrlogRecordTable_duplicate(struct strExtStrlogRecordTable_data *);
int strExtStrlogRecordTable_destroy(struct strExtStrlogRecordTable_data **);
int strExtStrlogRecordTable_add(struct strExtStrlogRecordTable_data *);
int strExtStrlogRecordTable_del(struct strExtStrlogRecordTable_data *);
void parse_strExtStrlogRecordTable(const char *, char *);
SNMPCallback store_strExtStrlogRecordTable;
void refresh_strExtStrlogRecordTable(int);
FindVarMethod var_strExtTraceTable;
struct strExtTraceTable_data *strExtTraceTable_create(void);
struct strExtTraceTable_data *strExtTraceTable_duplicate(struct strExtTraceTable_data *);
int strExtTraceTable_destroy(struct strExtTraceTable_data **);
int strExtTraceTable_add(struct strExtTraceTable_data *);
int strExtTraceTable_del(struct strExtTraceTable_data *);
void parse_strExtTraceTable(const char *, char *);
SNMPCallback store_strExtTraceTable;
void refresh_strExtTraceTable(int);

WriteMethod write_strExtStrlogRecordMid;
WriteMethod write_strExtStrlogRecordSid;
WriteMethod write_strExtStrlogRecordLevel;
WriteMethod write_strExtStrlogRecordFlags;
WriteMethod write_strExtStrlogRecordMsgString;
WriteMethod write_strExtStrlogRecordRowStatus;
WriteMethod write_strExtTraceMid;
WriteMethod write_strExtTraceSid;
WriteMethod write_strExtTraceLevel;
WriteMethod write_strExtTraceRowStatus;
WriteMethod write_strNlogargs;
WriteMethod write_strExtLogMsgSize;
WriteMethod write_strExtConsoleLog;
WriteMethod write_strExtErrorLog;
WriteMethod write_strExtTraceLog;
#endif				/* __LOCAL_STREXTMIB_H__ */