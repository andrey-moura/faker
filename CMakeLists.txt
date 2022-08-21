#Require a minimum version
cmake_minimum_required(VERSION 3.10)

project(uva-faker)

# Minimun C++ version
set(CMAKE_CXX_STANDARD 20)

add_library(uva-faker
	${CMAKE_CURRENT_LIST_DIR}/src/faker.cpp
)

include_directories(${CMAKE_CURRENT_LIST_DIR})

# Tests

# Create tests for current project
cspec_configure("uva-faker" ${CMAKE_CURRENT_LIST_DIR} "uva-faker")