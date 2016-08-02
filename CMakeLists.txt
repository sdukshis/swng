cmake_minimum_required(VERSION 2.8)

project(swng CXX)

option(BUILD_TESTS "build unittests" ON)

include(conanbuildinfo.cmake)
conan_basic_setup()

if(UNIX)
    add_definitions(
        -Wall
        -std=c++11
    )
endif()

file(GLOB ${PROJECT_NAME}_SOURCES
    src/*.cpp
)

file(GLOB ${PROJECT_NAME}_HEADERS
    src/*.h
)

add_executable(${PROJECT_NAME}
    ${${PROJECT_NAME}_SOURCES}
    ${${PROJECT_NAME}_HEADERS}
)

target_link_libraries(
    ${PROJECT_NAME}
    ${CONAN_LIBS}
)

if (BUILD_TESTS)
    enable_testing()
    file(GLOB ${PROJECT_NAME}_TEST_SOURCES
        src/misc.cpp
        tests/*.cpp
    )
    add_executable(test_${PROJECT_NAME}
        ${${PROJECT_NAME}_TEST_SOURCES}
        ${${PROJECT_NAME}_HEADERS}
    )

    target_link_libraries(
        test_${PROJECT_NAME}
        ${CONAN_LIBS}
    )

    add_test(test_${PROJECT_NAME} bin/test_${PROJECT_NAME})
endif()