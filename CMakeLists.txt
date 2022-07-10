cmake_minimum_required(VERSION 3.17.0)
project(zh_hash VERSION 0.1.0)

add_executable(application "examples/example1.cpp")
target_include_directories(application PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_compile_features(application PRIVATE cxx_std_20)
target_compile_options(application PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>:-Wall -Werror>
    $<$<CXX_COMPILER_ID:MSVC>:/WX /W4>
)
set_target_properties(application PROPERTIES
	MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
)

install(TARGETS application)
