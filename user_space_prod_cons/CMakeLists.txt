cmake_minimum_required(VERSION 3.10.0)
project(shared_memeory VERSION 0.1.0 LANGUAGES C CXX)


find_path(LIBUV_INCLUDE_DIR NAMES uv.h)

# Find libuv library
#find_library(LIBUV uv)
find_library(LIBUV_LIBRARIES NAMES uv libuv)

#target_include_directories(shared_memeory PRIVATE ${LIBUV_INCLUDE_DIRS})



add_executable(cc_inteligence cc_inteligence.c)
target_include_directories(cc_inteligence PRIVATE ${LIBUV_INCLUDE_DIR})
target_link_libraries(cc_inteligence ${LIBUV_LIBRARIES})


add_executable(inteligent_cc inteligent_cc.c)
target_include_directories(inteligent_cc PRIVATE ${LIBUV_INCLUDE_DIR})
target_link_libraries(inteligent_cc ${LIBUV_LIBRARIES})


# Link libuv to the second binary
#target_link_libraries(shared_memeory PRIVATE ${LIBUV})
#target_compile_options(shared_memeory PRIVATE -g)