#include <iostream>
#include <log4cxx/logger.h>    
#include <log4cxx/logstring.h> 
#include <log4cxx/propertyconfigurator.h> 

using namespace log4cxx;

int main() 
{ 
        using namespace log4cxx; 

        // 读取配置文件 
        PropertyConfigurator::configure("conf.property"); 

        // 建立两个logger 
        LoggerPtr logger1 = Logger::getLogger("TraceYourMama"); 
        LoggerPtr logger2 = Logger::getLogger("Patch"); 

        LOG4CXX_TRACE(logger1, "logger1"<<" trace1"); 
        LOG4CXX_WARN(logger1, "logger1"<<"warn"); 
        LOG4CXX_DEBUG(logger1, "logger1"<<"debug"); 
        LOG4CXX_ASSERT(logger1, false, "logger1"<<"assert"); 
        LOG4CXX_FATAL(logger1, "logger1"<<"fatal"); 

        LOG4CXX_TRACE(logger2, "logger2"<<"trace2"); 
        LOG4CXX_ERROR(logger2, "logger2"<<"error"); 

        return 0; 
}
