#include "gqglog/gqglog.h"


// 静态成员变量的初始化
std::string GQGLOGManager::CLASS_NAME = std::string("GQGLOGManager");

// 初始化 GLOG -- 仅终端输出版本
void GQGLOGManager::InitGLog(const GLogLevel level)
{
    // 初始化
    google::InitGoogleLogging("");
    // 输出终端时使能颜色标记
    FLAGS_colorlogtostderr = true;
    // 大于该等级的日志信息均输出到屏幕上 GLOG_LECEL
    google::SetStderrLogging(static_cast<int>(level));


}

// 初始化 GLOG -- 设置输出文件的版本
void GQGLOGManager::InitGLog(const std::string strLogRootPath, const GLogLevel level)
{
    // step 0 初始化GLog写入的根地址
    std::string strLogRootPathUsed = strLogRootPath;
    if(strLogRootPathUsed[strLogRootPathUsed.length() - 1] != '/')
        strLogRootPathUsed = strLogRootPathUsed + "/";
    google::InitGoogleLogging(strLogRootPathUsed.c_str());

    // step 1 设置不同重要等级的日志的文件名格式
    google::SetLogDestination(google::GLOG_FATAL,   (strLogRootPathUsed + "fatal_"  ).c_str());      // 设置 google::FATAL 级别的日志存储路径和文件名前缀
    google::SetLogDestination(google::GLOG_ERROR,   (strLogRootPathUsed + "error_"  ).c_str());      // 设置 google::ERROR 级别的日志存储路径和文件名前缀
    google::SetLogDestination(google::GLOG_WARNING, (strLogRootPathUsed + "warning_").c_str());      // 设置 google::WARNING 级别的日志存储路径和文件名前缀
    google::SetLogDestination(google::GLOG_NOTICE,  (strLogRootPathUsed + "notice_" ).c_str());      // 设置 google::NOTICE 级别的日志存储路径和文件名前缀
    google::SetLogDestination(google::GLOG_NOTE,    (strLogRootPathUsed + "note_"   ).c_str());      // 设置 google::NOTE 级别的日志存储路径和文件名前缀
    google::SetLogDestination(google::GLOG_INFO,    (strLogRootPathUsed + "info_"   ).c_str());      // 设置 google::INFO 级别的日志存储路径和文件名前缀
    google::SetLogDestination(google::GLOG_DEBUG,   (strLogRootPathUsed + "debug_"  ).c_str());      // 设置 google::DEBUG 级别的日志存储路径和文件名前缀
    google::SetLogDestination(google::GLOG_TRACE,   (strLogRootPathUsed + "trace_"  ).c_str());      // 设置 google::DEBUG 级别的日志存储路径和文件名前缀


    // step 2 其他选项
    // 磁盘满时终止写入
    FLAGS_stop_logging_if_full_disk = true;
    // 输出终端时使能颜色标记
    FLAGS_colorlogtostderr = true;
    // 大于该等级的日志信息均输出到屏幕上
    google::SetStderrLogging(static_cast<int>(level));


    CLOG(NOTE) << "GLog enabled. System is going to bring up. Log at: " << strLogRootPathUsed;

    // DEBUG
    // LOG(TRACE)      << "TRACE";
    // LOG(DEBUG)      << "DEBUG";
    // LOG(INFO)       << "INFO";
    // LOG(NOTE)       << "NOTE";
    // LOG(NOTICE)     << "NOTICE";
    // LOG(WARNING)    << "WARNING";
    // LOG(ERROR)      << "ERROR";
    // LOG(FATAL)      << "FATAL";

    return ;
}

// 运行时设置输出日志的最低等级
void GQGLOGManager::SetMinLogLevel(const GLogLevel level)
{
    google::SetStderrLogging(static_cast<int>(level));

    return ;
}

// 反初始化 GLOG
void GQGLOGManager::DeinitGLog(bool bQuiet)
{
    if(!bQuiet)
    {
        CLOG(NOTE) << "GLog disabled.";
    }

    google::ShutdownGoogleLogging();
}


