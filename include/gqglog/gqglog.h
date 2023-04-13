#ifndef __GQ_GLOG_H__
#define __GQ_GLOG_H__

// ==== 头文件 ====
#include <iostream>
#include <string>

// GLOG 
#include <glog/logging.h> 

// ==== 宏定义 ====
// 日志输出时自动带上当前类名和函数名
#define CLOG(severity) LOG(severity) << "[" << CLASS_NAME << "::" << __FUNCTION__ << "] "
// FUTURE_TODO 试试这个获取类名的方式： https://www.csdn.net/tags/MtTaEgxsOTg0ODY5LWJsb2cO0O0O.html
// 日志输出时自动带上当前函数名
#define FLOG(severity) LOG(severity) << "[::" << __FUNCTION__ << "] "

// vscode 下好看，没有别的用途；代价是稍微花一些编译时间
#define TRACE   TRACE
#define DEBUG   DEBUG 
#define INFO    INFO 
#define NOTE    NOTE 
#define NOTICE  NOTICE 
#define WARNING WARNING 
#define ERROR   ERROR 
#define FATAL   FATAL 


// ==== 类型定义 ====

enum class GLogLevel : int
{
    TRACE       = google::GLOG_TRACE,
    DEBUG       = google::GLOG_DEBUG,
    INFO        = google::GLOG_INFO,
    NOTE        = google::GLOG_NOTE,
    NOTICE      = google::GLOG_NOTICE,
    WARNING     = google::GLOG_WARNING,
    ERROR       = google::GLOG_ERROR,
    FATAL       = google::GLOG_FATAL
};      // enum class GLogLevel : int

// ==== 函数原型 ====

class GQGLOGManager
{

public:

    /**
     * @brief 构造函数
     * 
     */
    GQGLOGManager(){}

    /**
     * @brief 析构函数
     * 
     */
    ~GQGLOGManager(){}

public:

    /**
     * @brief 初始化 GLOG
     * @details 和有参数版本不同的是，这个版本的初始化函数不保存日志文件
     */
    static void InitGLog(const GLogLevel level = GLogLevel::TRACE);


    /**
     * @brief 初始化 GLOG 库
     * @param[in] strLogRootPath 日志文件的保存路径
     */
    static void InitGLog(const std::string strLogRootPath, const GLogLevel level = GLogLevel::TRACE);

    /**
     * @brief 运行时修改输出的最低日志等级
     * @param[in] level 输出的最低日志等级
     */
    static void SetMinLogLevel(const GLogLevel level);

    /**
     * @brief 反初始化 GLOG
     * @param[in] bQuiet 是否保持静默，也就是在终端不要输出任何信息。默认为 false
     */
    static void DeinitGLog(bool bQuiet = false);

private:

    static std::string CLASS_NAME;         /// 当前类名

};          // class GQGLOGManager


#endif      // MACRO __GQ_GLOG_H__

