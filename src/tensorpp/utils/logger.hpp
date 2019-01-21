#ifndef __TENSORPP_LOGGER__
#define __TENSORPP_LOGGER__

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
            Logger(const char* loggername, LogLevel = LogLevel::Info);
            
            short operator() (const char*, LogLevel);
            
		};

	}
	
	namespace utils { extern utils::Logger logger; }

}

#endif // __TENSORPP_LOGGER__
