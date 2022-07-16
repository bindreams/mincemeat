cmake_minimum_required(VERSION 3.23.0)
project(mincemeat VERSION 0.1.0)

include(cmake/warnings.cmake)
include(cmake/packaging.cmake)

option(MINCEMEAT_TESTS "Build tests for mincemeat" OFF)
option(MINCEMEAT_EXAMPLES "Build examples for mincemeat" OFF)

add_library(mincemeat INTERFACE)
add_library(mincemeat::mincemeat ALIAS mincemeat)
file(GLOB_RECURSE mincemeat_HEADERS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} CONFIGURE_DEPENDS "src/*.hpp")
target_sources(mincemeat INTERFACE FILE_SET HEADERS BASE_DIRS src FILES ${mincemeat_HEADERS})
target_include_directories(mincemeat INTERFACE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
	$<INSTALL_INTERFACE:include>
)
target_compile_features(mincemeat INTERFACE cxx_std_20)
target_package(mincemeat)

if(MINCEMEAT_TESTS)
	add_executable(mincemeat_tests "tests/main.cpp")
	target_compile_warnings(mincemeat_tests treat_as_errors gnu_all gnu_extra ms_1)
	target_link_libraries(mincemeat_tests PRIVATE mincemeat)

	install(TARGETS mincemeat_tests)
endif()

if(MINCEMEAT_EXAMPLES)
	add_executable(mincemeat_example1 "examples/example1.cpp")
	target_link_libraries(mincemeat_example1 PRIVATE mincemeat)

	install(TARGETS mincemeat_example1)
endif()
