/*
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *  Copyrights:
 *
 *  Copyright - 1999 Sun Microsystems, Inc. All rights reserved.
 *  901 San Antonio Road, Palo Alto, California 94043, U.S.A.
 *
 *  This product and related documentation are protected by copyright and
 *  distributed under licenses restricting its use, copying, distribution, and
 *  decompilation. No part of this product or related documentation may be
 *  reproduced in any form by any means without prior written authorization of
 *  Sun and its licensors, if any.
 *
 *  RESTRICTED RIGHTS LEGEND: Use, duplication, or disclosure by the United
 *  States Government is subject to the restrictions set forth in DFARS
 *  252.227-7013 (c)(1)(ii) and FAR 52.227-19.
 *
 *  The product described in this manual may be protected by one or more U.S.
 *  patents, foreign patents, or pending applications.
 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *  Author:
 *
 *  Mahindra British Telecom
 *  155 , Bombay - Pune Road 
 *  Pimpri ,
 *  Pune - 411 018.
 *
 *  Module Name   : JAIN INAP API
 *  File Name     : ResultIndEvent.java
 *  Approver      : Jain Inap Edit Group
 *  Version       : 1.0
 *
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 */


package javax.jain.ss7.inap.event;

import java.util.*;
import java.lang.*;
import javax.jain.ss7.inap.exception.*;
import javax.jain.ss7.inap.constants.*;

/**
 This Class contains information related to the Result Component being received
 */	
 
public class ResultIndEvent extends ComponentIndEvent
			implements java.io.Serializable
{

	private int invokeID;

	private java.lang.Object message;
	private boolean isMessage = false ;


/**
Constructs a new ResultIndEvent. 
*/

	public ResultIndEvent(Object source,int invokeID , boolean lastResultType)
	{
		super(source);
		if (lastResultType)
			componentIndPrimitiveType=ComponentIndPrimitiveType.R_RESULT_L;
		else
			componentIndPrimitiveType=ComponentIndPrimitiveType.R_RESULT_NL;
		setInvokeID(invokeID);
	}

	public ResultIndEvent(Object source,int invokeID , boolean lastResultType , java.lang.Object message)
	{
		super(source);
		if (lastResultType)
			componentIndPrimitiveType=ComponentIndPrimitiveType.R_RESULT_L;
		else
			componentIndPrimitiveType=ComponentIndPrimitiveType.R_RESULT_NL;
		setInvokeID(invokeID);
		setMessage(message);
	}


/**
Gets the type of component primitive .
*/
	public ComponentIndPrimitiveType getComponentIndPrimitiveType()
	{
		return componentIndPrimitiveType;
	}


//---------------------------------------------	

/**
Sets the Invoke ID.
*/
	public void setInvokeID(int invokeID)
	{
		this.invokeID = invokeID;
	}
	

/**
Gets the Invoke ID.
*/
	public int getInvokeID()
	{
		return invokeID;
	}



//---------------------------------------------	

/**
Sets the message i.e, Operation to be sent.
*/
	public void setMessage(java.lang.Object message)
	{
		this.message = message;
		isMessage = true;
	}

/**
Gets the message i.e, Operation to be sent.
*/
	public java.lang.Object getMessage()
	{
		return message;
	}

/*
Indicates if the Message conditional parameter is present .
Returns: TRUE if present, FALSE otherwise.
*/
    public boolean isMessagePresent()
    {
        return isMessage;
    }
//---------------------------------------------	



}