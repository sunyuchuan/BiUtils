package com.whaley.biutil;

/**
 * Created by wanglei on 2016/7/29.
 */
public class BiStartEndLog extends BiLog {
    protected String Uuid;
    protected String Status;
    public BiStartEndLog(String caseId, String uuid, String status) {
        super("start_end");
	PutHeader("status", status);
	PutHeader("actionId", caseId);
	PutHeader("uuid", uuid);
    }
}
