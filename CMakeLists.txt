cmake_minimum_required(VERSION 3.15)
project(testci)

include_directories(include)

add_subdirectory(${testci_SOURCE_DIR}/thirdparty)

add_subdirectory(${testci_SOURCE_DIR}/tests)