cmake_minimum_required(VERSION 3.3)
project(clion_practice)

# include boost
# good reference: https://stackoverflow.com/questions/6646405/how-do-you-add-boost-libraries-in-cmakelists-txt
find_package( Boost REQUIRED COMPONENTS program_options )
include_directories( ${Boost_INCLUDE_DIRS} )
include_directories(inc)

# import subdirs
add_subdirectory(src)
add_subdirectory(test)

# set up testing (http://www.cmake.org/Wiki/CMake/Testing_With_CTest)
enable_testing()
add_test(main_tests build/bin/clion_tests)

# set up build target (https://stackoverflow.com/questions/4964319/cmake-with-standard-directory-layout-linux)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/build/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/build/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/build/lib)


# set up executable
set(SOURCE_FILES src/main.cpp inc/catch.h inc/main.h)
set(TEST_SOURCES test/tests.cpp test/tests.h test/test_runner.cpp test/test_runner.h)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y")
add_executable(clion_practice ${SOURCE_FILES})
add_executable(clion_tests ${TEST_SOURCES})
target_link_libraries( clion_practice ${Boost_PROGRAM_OPTIONS_LIBRARY} )

