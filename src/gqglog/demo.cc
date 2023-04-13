/**
 * @file demo.cc
 * @author guoqing (1337841346@qq.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-13
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <string>
#include <memory>


#include "gqglog/gqglog.h"

#include <chrono>
#include <thread>


class DemoClass
{

public:

    DemoClass()
        :CLASS_NAME("DemoClass")
    {
        CLOG(INFO) << "Construction function.";
    }

    ~DemoClass()
    {
        CLOG(INFO) << "De-construction function.";
    }

public:

    void function(void)
    {
        CLOG(INFO) << "A function.";
    }

private:

    std::string CLASS_NAME;         /// 类别名称，用于日志输出

};          // class DemoClass


class AnotherDemoClass
{

public:

    AnotherDemoClass()
        :CLASS_NAME("AnotherDemoClass")
    {
        CLOG(INFO) << "Construction function.";
    }

    ~AnotherDemoClass()
    {
        CLOG(INFO) << "De-construction function.";
    }

public:

    void function(void)
    {
        CLOG(INFO) << "A function.";
    }

private:

    std::string CLASS_NAME;         /// 类别名称，用于日志输出

};          // class AnotherDemoClass


/**
 * @brief 演示用函数
 * 
 */
void DemoFunction(void)
{
    FLOG(TRACE)      << "TRACE";
    FLOG(DEBUG)      << "DEBUG";
    FLOG(INFO)       << "INFO";
    FLOG(NOTE)       << "NOTE";
    FLOG(NOTICE)     << "NOTICE";
    FLOG(WARNING)    << "WARNING";
    FLOG(ERROR)      << "ERROR";
    // LOG(FATAL)      << "FATAL";
}

int main(int argc, char* argv[])
{

    GQGLOGManager::InitGLog(std::string("./"));


    // 正常的、非类别信息的输出

    LOG(TRACE)      << "TRACE";
    LOG(DEBUG)      << "DEBUG";
    LOG(INFO)       << "INFO";
    LOG(NOTE)       << "NOTE";
    LOG(NOTICE)     << "NOTICE";
    LOG(WARNING)    << "WARNING";
    LOG(ERROR)      << "ERROR";
    // LOG(FATAL)      << "FATAL";

    // std::this_thread::sleep_for(std::chrono::seconds(1));

    // bool bCondition ;

    int a = 123;
    int b = 567;

    LOG_IF(NOTE, a < b) << "a > b";

    // google::SetStderrLogging(google::GLOG_NOTICE);
    GQGLOGManager::SetMinLogLevel(GLogLevel::WARNING);

    LOG(TRACE)      << "TRACE";
    LOG(DEBUG)      << "DEBUG";
    LOG(INFO)       << "INFO";
    LOG(NOTE)       << "NOTE";
    LOG(NOTICE)     << "NOTICE";
    LOG(WARNING)    << "WARNING";
    LOG(ERROR)      << "ERROR";
    
    // 带有当前函数信息的输出

    FLOG(TRACE)      << "TRACE";
    FLOG(DEBUG)      << "DEBUG";
    FLOG(INFO)       << "INFO";
    FLOG(NOTE)       << "NOTE";
    FLOG(NOTICE)     << "NOTICE";
    FLOG(WARNING)    << "WARNING";
    FLOG(ERROR)      << "ERROR";
    // // LOG(FATAL)      << "FATAL";

    // 另外一组带有当前函数信息的输出
    // DemoFunction();


    // 带有类别和函数信息的输出

    DemoClass aa;
    aa.function();

    // // 另外一个类
    // std::shared_ptr<AnotherDemoClass> spb = std::make_shared<AnotherDemoClass>();
    // spb->function();
    // // 销毁
    // spb.reset();



    GQGLOGManager::DeinitGLog();

    return 0;
}

