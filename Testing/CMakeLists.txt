cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(Testing)

# find all source files
file(GLOB_RECURSE SOURCES
	../Physicc/tests/*.cpp
)

set(SOURCES ${SOURCES} "main.cpp")

# add the executable
add_executable(Test ${SOURCES})
if (WIN32)
    if (MSVC)
        set_property(TARGET Test PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")
	endif()
endif()

# include gtest headers
target_include_directories(Test PUBLIC googletest/googletest/include/)

# add googletest
add_subdirectory(googletest)
target_link_libraries(Test gtest_main)

# include physicc
target_include_directories(Test PUBLIC ../Physicc/include/)
target_include_directories(Test PUBLIC ../shared/libs/glm/)

target_link_libraries(Test Physicc)

# Set Gtest options
SET(BUILD_GMOCK OFF)
set(INSTALL_GTEST OFF)
