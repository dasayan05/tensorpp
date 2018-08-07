# This directory contains sources for the additional binaries to be
# shipped with Tensor++; may be some command line tools or applications

# creates a binary target with name 'binary_name'
# compiling 'binary_sources'; also links Tensor++
macro (make_binary binary_name binary_sources)
	# binary_name: name of the binary
	# binary_sources: list of sources to be compiled
	
	add_executable(${binary_name} ${binary_sources})
	target_link_libraries(${binary_name} PRIVATE ${NAME_OF_PROJECT})
	
endmacro ()

# list of all the binary targets

# 1. 'info': provides meta information about Tensor++
make_binary(info
	sample.cpp)