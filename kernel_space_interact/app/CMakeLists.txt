cmake_minimum_required(VERSION 3.10.0)
project(kernel_ineteraction VERSION 0.1.0 LANGUAGES C CXX)


find_path(LIBUV_INCLUDE_DIR NAMES uv.h)

# Find libuv library
#find_library(LIBUV uv)
find_library(LIBUV_LIBRARIES NAMES uv libuv)

#target_include_directories(shared_memeory PRIVATE ${LIBUV_INCLUDE_DIRS})
include_directories(. ./)

add_executable(kernel_ineteraction kernel_interact_app.c)

target_include_directories(kernel_ineteraction PRIVATE ${LIBUV_INCLUDE_DIR})

target_link_libraries(kernel_ineteraction ${LIBUV_LIBRARIES})

