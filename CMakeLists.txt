# Specify the minimum version for CMake
cmake_minimum_required(VERSION 2.8)

# Project's name
project(cartesian-genetic-programming-cpp)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

#Bring the headers, such as Student.h into the project
include_directories(include)

file(GLOB SOURCES "src/*.cc")
file(GLOB SPECS "test/*.cc")
file(GLOB INCLUDES "include/*.h")

add_executable(cgp ${SOURCES} main.cpp)

########
# TEST #
#######
# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in ${CMAKE_BINARY_DIR}/libs/googletest/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/libs/googletest )
if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/libs/googletest )
if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/libs/googletest-src
    ${CMAKE_BINARY_DIR}/libs/googletest-build)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include")
endif()

# For make-based builds, defines make target named test.
# For Visual Studio builds, defines Visual Studio project named RUN_TESTS.
enable_testing()

# Extra linking for the project.
add_executable(unit-tests ${SOURCES} ${SPECS})

target_link_libraries(unit-tests gtest_main gtest pthread)

add_test(
    NAME test
    COMMAND ./bin/unit-tests
)

## DOXYGEN ##
# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(doc ALL
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen" VERBATIM
        )
endif(DOXYGEN_FOUND)

add_custom_target(lint ALL
    python ${CMAKE_SOURCE_DIR}/cpplint.py ${SOURCES} ${INCLUDES}
    COMMENT "Running cpplint..." VERBATIM
    )

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)
SET(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "-g -O0 -Wall -W -fprofile-arcs -ftest-coverage")
SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")


include(CodeCoverage)
# setup_target_for_coverage(${PROJECT_NAME}_coverage unit-tests coverage)

add_custom_target(coverage
    COMMAND lcov --zerocounters --directory ${PROJECT_BINARY_DIR}
    COMMAND lcov --capture --initial --directory ${PROJECT_BINARY_DIR} --output-file ${PROJECT_BINARY_DIR}/build/reports/coverage
    COMMAND ${PROJECT_BINARY_DIR}/bin/unit-tests
    COMMAND lcov --no-checksum --directory ${PROJECT_BINARY_DIR} --capture --output-file ${PROJECT_BINARY_DIR}/build/reports/coverage.info
    COMMAND lcov --remove ${PROJECT_BINARY_DIR}/build/reports/coverage.info "*gtest*" "*c++*" -o ${PROJECT_BINARY_DIR}/build/reports/coverage.info
    COMMAND genhtml ${PROJECT_BINARY_DIR}/build/reports/coverage.info -o ${PROJECT_BINARY_DIR}/build/reports

    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_custom_target(check
    COMMAND make lint
    COMMAND make coverage
)
