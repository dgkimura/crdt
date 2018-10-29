cmake_minimum_required(VERSION 3.4)
project(crdt.src)

set(SOURCES
    counter.cpp
)

add_library(crdt SHARED ${SOURCES})

include_directories(${CMAKE_SOURCE_DIR}/include)

set_property(TARGET crdt PROPERTY CXX_STANDARD 11)
