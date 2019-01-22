#ifndef __TENSORPP_LOGGER__
#define __TENSORPP_LOGGER__

// Without this, the function templates won't work
// TODO: need to redo this later
#include <fmt/time.h>
using namespace fmt::literals;

// standard library includes
#include <string>

namespace tensorpp {

	namespace utils {
    
        // Not 'enum class' because the integers associated
        // are required for level comparison
        enum LogLevel {
            Debug,  // debugging info
            Info,   // milestones etc.
            Warn,   // wanring
            Error,  // logical error
            Fatal   // serious trouble
        };

		/* The main logger class of Tensor++, which
		 * depends on the 'fmt' library for formatting
		 * purpose. */
		class Logger
		{
            
		private:
			std::string _name = "base";
            LogLevel _level;
            
		public:
		    
            // constructor of Logger class
            Logger(const char* loggername, LogLevel defaultlevel = LogLevel::Info)
            	: _level(defaultlevel), _name(loggername) {	}
            
            template<typename ...Args>
            short operator() (LogLevel level, const char* onlymsg, Args&&... args) {
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

				std::string prefix = fmt::format("[{loggername}: {loglevel}][{timestamp:%T}]",
					"loggername"_a = _name,
					"loglevel"_a = loglevel_str,
					"timestamp"_a = *std::localtime(&now));
				std::string content = fmt::format(onlymsg, std::forward<Args>(args)...);

				fmt::print("{prefix}: {content}\n",
					"prefix"_a = prefix.c_str(),
					"content"_a = content.c_str()
				);
            }
            
		};

	}
	
	namespace utils { extern utils::Logger logger; }

}

#endif // __TENSORPP_LOGGER__
