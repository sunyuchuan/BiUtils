package com.whaley.biutil;

/**
 * Created by wanglei on 2016/7/28.
 */
public class BiLogFactory {
    public static IBiLog CreateLog(String caseId)
    {
        return new BiEventLog(caseId);
    }

    public static IBiLogPair CreateLogPair(String caseId)
    {
        return new BiLogPair(caseId);
    }


}
