include(FetchContent)

function(get_sources DIRECTORY)
	include(${CMAKE_CURRENT_SOURCE_DIR}/impl/${DIRECTORY}/sources.cmake)
	set(FOXL_PROCESSED_SOURCES "")
	foreach(SOURCE IN LISTS FOXL_SOURCES)
		list(APPEND FOXL_PROCESSED_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/impl/${DIRECTORY}/${SOURCE})
	endforeach()
	set(FOXL_SOURCES ${FOXL_PROCESSED_SOURCES} PARENT_SCOPE)
endfunction()

get_sources(base)
add_library(foxl_base ${FOXL_SOURCES})
target_include_directories(foxl_base PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include/
)

find_package(glm QUIET)

if(NOT glm_FOUND)
	FetchContent_Declare(
		glm
		GIT_REPOSITORY https://github.com/g-truc/glm.git
		GIT_TAG master
	)

	FetchContent_MakeAvailable(glm)
else()
	add_library(glm INTERFACE)
	target_link_libraries(glm INTERFACE glm::glm)
endif()

target_link_libraries(foxl_base glm::glm fmt::fmt)

unset(FOXL_SOURCES)
