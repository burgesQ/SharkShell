# SharkShell ASKIP

cmake_minimum_required (
    VERSION 3.5
)

# Project Name
project (
    SharkShell
)

# Relaese Type & Nb
set (
    CMAKE_BUILD_TYPE Release
)
set (
    SHARK_SHELL_VERSION_MAJOR 1
)
set (
    SHARK_SHELL_VERSION_MAJOR 0
)

# C++ Flags
# C++ 14
set (
    CMAKE_CXX_FLAGS "-Wall -std=c++14 -g3 -O0"
)
set (
    CMAKE_CXX_STANDARD 14
)

find_package(Curses REQUIRED)

# Directorys
set (
    SOURCES_DIR ./srcs
)

set (
    SOURCES_SHARK_SHELL
    ${SOURCES_DIR}/Main.cpp
    ${SOURCES_DIR}/Ncurses.cpp
)

include_directories(
    ${CURSES_INCLUDE_DIR}
)

include_directories(
    includes
)

add_executable (
    SharkShell
    ${SOURCES_SHARK_SHELL}
)

target_link_libraries (
    SharkShell
    ${CURSES_LIBRARIES}
)
