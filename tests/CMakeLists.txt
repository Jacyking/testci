set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/tests)
project(test_testci)
add_executable(${PROJECT_NAME}
        test_testci.cpp
        main.cpp
        )

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} ${MYSQL_LIBRARY} doctest)
