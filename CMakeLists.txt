cmake_minimum_required(VERSION 3.20)

project(foxl
	DESCRIPTION "Fred's vOXel Library."
	VERSION 0.1
	LANGUAGES C CXX
)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(extern/fmt)

include(${CMAKE_CURRENT_SOURCE_DIR}/impl/modules.cmake)

option(TESTING "Enable testing")
if(TESTING)
	enable_testing()
	add_subdirectory(tests)
endif()
