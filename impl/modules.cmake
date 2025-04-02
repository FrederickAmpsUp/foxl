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

unset(FOXL_SOURCES)
