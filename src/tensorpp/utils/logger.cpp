#include <tensorpp/utils/logger.hpp>

// internal headers
#include <tensorpp/tensorpp_internal.hpp>

namespace tensorpp {

    namespace utils {

        Logger::Logger(const char *loggername, LogLevel loglevel) :
            _name(loggername), // name of the logger
            _level(loglevel) // current logging level
        {
            // ...
        }
        
        short Logger::operator()(const char *content, LogLevel level)
        {
        	std::time_t now = std::time(nullptr);
        	std::string loglevel_str;

			switch (level)
			{
				case LogLevel::Debug:
					loglevel_str = "Debug"; break;
				case LogLevel::Info:
					loglevel_str = "Info"; break;
				case LogLevel::Warn:
					loglevel_str = "Warn"; break;
				case LogLevel::Fatal:
					loglevel_str = "Fatal"; break;
				case LogLevel::Error:
					loglevel_str = "Error"; break;
			}

            fmt::print("[{loggername}: {loglevel}][{timestamp:%T}]: {content}\n", 
            	"loggername"_a = _name,
            	"loglevel"_a = loglevel_str,
            	"timestamp"_a = *std::localtime(&now),
            	"content"_a = content
            );
        }
    
    }

	namespace utils {	utils::Logger logger = utils::Logger("utils");    }

}
