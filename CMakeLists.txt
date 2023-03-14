cmake_minimum_required(VERSION 3.15)
project(testci)

include_directories(include)

if (MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
else ()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -std=c++17")
endif ()

add_subdirectory(${testci_SOURCE_DIR}/thirdparty)

add_subdirectory(${testci_SOURCE_DIR}/tests)
