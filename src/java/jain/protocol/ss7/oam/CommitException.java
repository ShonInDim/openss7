/* ***************************************************************************

 @(#) $RCSfile$ $Name$($Revision$) $Date$

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

 Last Modified $Date$ by $Author$

 -----------------------------------------------------------------------------

 $Log$
 *****************************************************************************/

package jain.protocol.ss7.oam;

import jain.*;
import jain.protocol.ss7.*;

import java.lang.Object;
import java.lang.Throwable;
import java.lang.Exception;

/**
  * This Exception is thrown by a JAIN OAM Managed MBean if the commit() command
  * has been invoked and not all of the operations were successfully comitted.
  *
  * @version 1.1
  * @author Colm Hayden
  */
public class CommitException extends SS7Exception {
    /**
      * Constructs a new CommitException.
      */
    public CommitException() {
        super();
    }
    /**
      * Adds an entry to the log file of this CommitException.
      * @param success  Either:
      * <li>SUCCESS - the operation successfully completed.
      * <li>FAILED - the operation failed
      * <li>UNKNOWN - could not determine whether the operation was successful or not.
      * @param mBeanObjectName  The ObjectName of the MBean.
      * @param operation  The opertion that was to be committed.
      * @exception java.lang.NullPointerException  If any of the Objects
      * supplied as parameters are null.
      */
    public void addEntry(int success, java.lang.String mBeanObjectName, java.lang.String operation)
        throws java.lang.NullPointerException {
        if (success == null || mBeanObjectName == null || operation == null)
            throw java.lang.NullPointerException();
        m_success = success;
        m_mBeanObjectName = mBeanObjectName;
        m_operation = operation;
    }
    /**
      * Returns a log of the operations.
      * @return a log in the format:
      * 
      * <code>
      * 1 : [MBeanObjectName] : [operationRequested] : [SUCCESS | FAILED | UNKNOWN] ; <br>
      * 2 : [MBeanObjectName] : [operationRequested] : [SUCCESS | FAILED | UNKNOWN] ; <br>
      * ..... .... .... .... .... <br>
      * N : [MBeanObjectName] : [operationRequested] : [SUCCESS | FAILED | UNKNOWN] ; <br> <br>
      * Eg. <br>
      * 1 : com.aepona.jain.protocol.ss7.oam.mtp3:type=OBJECT_TYPE_RO UTE,id=23 : setDestinationPointCode : SUCCESS ; <br>
      * 2 : com.aepona.jain.protocol.ss7.oam.mtp3:type=OBJECT_TYPE_RO UTE,id=24 : setPriority : FAILED ; <br>
      * 3 : com.aepona.jain.protocol.ss7.oam.mtp3:type=OBJECT_TYPE_LI NK_SET,id=4 : setDestinationPointCode : UNKNOWN ; <br>
      * 4 : com.aepona.jain.protocol.ss7.oam.mtp3:type=OBJECT_TYPE_LI NK_SET,id=6 : addLink : SUCCESS ; <br>
      * </code>
      */
    public java.lang.String getLog() {
    }
}

// vim: sw=4 et tw=0 com=srO\:/**,mb\:*,ex\:*/,srO\:/*,mb\:*,ex\:*/,b\:TRANS,\://,b\:#,\:%,\:XCOMM,n\:>,fb\:-
