package com.whaley.biutil;

/**
 * Created by wanglei on 2016/7/29.
 */
public interface IBiLogUploader {
    // Refer to http://wiki.moretv.cn/wiki/pj/backend/bi/middleware-bi-api
    public static final int LOG_URL = 28;
    public static final int STRATEGY_DEFAULT = 1;
    public static final int STRATEGY_NO_CACHE = 2;
    public static final int STRATEGY_UPLOAD_NOW = 3;

    // Defined by System Group to specify whether to upload depends on system
    // configuration.
    public static final int STRATEGY_SYSTEM_MASK = 0xf0000000;
    public static final int STRATEGY_UPLOAD_USER = 0x10000000;
    public static final int STRATEGY_UPLOAD_USERDEBUG = 0x20000000;
    public static final int STRATEGY_UPLOAD_ENG = 0x40000000;

    public void Submit(IBiLog biLog);
    public void Submit(IBiLog biLog, int strategy);
}
