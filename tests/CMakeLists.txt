cmake_minimum_required(VERSION 3.20)

project(foxl_tests
	DESCRIPTION "Tests for Fred's vOXel Library."
	VERSION 0.1
	LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)

FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG v1.16.0
)

FetchContent_MakeAvailable(googletest)

include(GoogleTest)

add_executable(tests ./001_storage.cpp)
target_link_libraries(tests foxl_base GTest::gtest GTest::gtest_main)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
	message(STATUS "Compiler supports coverage reporting")
	target_compile_options(tests PRIVATE -g --coverage)
	target_link_options(tests PRIVATE --coverage)
endif()
gtest_discover_tests(tests)
