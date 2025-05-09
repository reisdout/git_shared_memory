cmake_minimum_required(VERSION 3.10.0)
project(inteligence_app VERSION 0.1.0 LANGUAGES C CXX)



include_directories(. ./libpcap/pcap)

#link_directories(${CMAKE_SOURCE_DIR}/lib)

find_library(PCAP_LIB NAMES pcap PATHS ${CMAKE_SOURCE_DIR}/libpcap)


add_executable(inteligence_app main.cpp)

target_link_libraries(${PROJECT_NAME} ${PCAP_LIB})

