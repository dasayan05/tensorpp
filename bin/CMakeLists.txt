# This directory contains sources for the
# additional binaries to be shipped with
# Tensor++; may be some command line tools
#
# TODO: make binary target creation easier

# add two such lines for every executable binary
#       add_executable(<name of binary> <list of sources>)
#       target_link_libraries(<name of binary> PRIVATE ${NAME_OF_PROJECT})

# 'sample ' binary
add_executable(info sample.cpp)
target_link_libraries(info PRIVATE ${NAME_OF_PROJECT})