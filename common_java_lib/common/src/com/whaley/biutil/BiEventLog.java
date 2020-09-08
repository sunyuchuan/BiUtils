package com.whaley.biutil;

/**
 * Created by wanglei on 2016/7/28.
 */
public class BiEventLog extends BiLog {
    public BiEventLog(String caseId)
    {
	super("event");
	PutHeader("eventId", caseId);
    }
}
