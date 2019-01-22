#include <tensorpp/utils/logger.hpp>

namespace tensorpp {

    /*
     * This is a logger registry.
     * Everytime a new sub-namespace is created, better to
     * have a seperate logger object registered here.
     * TODO: Create a convenient macro for registering loggers
     */
	namespace utils {	utils::Logger logger = utils::Logger("utils");    }

}
