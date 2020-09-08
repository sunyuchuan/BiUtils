package com.whaley.biutil;

import java.util.UUID;

/**
 * Created by wanglei on 2016/7/28.
 */
public class BiLogPair implements IBiLogPair {
    IBiLog[] LogPair = new BiStartEndLog[2];
    String Uuid = UUID.randomUUID().toString();
    public BiLogPair(String caseId) {
        LogPair[0] = new BiStartEndLog(caseId, Uuid, "start");
        LogPair[1] = new BiStartEndLog(caseId, Uuid, "end");
    }
    public IBiLog StartLog() {
        return LogPair[0];
    }
    public IBiLog EndLog() {
        return LogPair[1];
    }
}
