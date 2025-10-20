cmake_minimum_required(VERSION 4.1)
project(monitor)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

include_directories(include)
file(GLOB SOURCES "src/common/*.cpp")

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
	file(GLOB MACOS_SOURCES "src/macos/*.cpp")
	list(APPEND SOURCES ${MACOS_SOURCES})
	message(STATUS "MACOS files was added.")
else()
	file(GLOB LINUX_SOURCES "src/linux/*.cpp")
	list(APPEND SOURCES ${LINUX_SOURCES})
	message(STATUS "Linux files was added.")
endif()

add_executable(monitor ${SOURCES})

set_property(TARGET monitor PROPERTY CXX_STANDARD 17)
target_link_libraries(monitor ${CURSES_LIBRARIES})
# TODO: Run -Werror in CI.
target_compile_options(monitor PRIVATE -Wall -Wextra)
