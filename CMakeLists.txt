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
    CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++14 -g3 -O0"
)

set (
    CMAKE_CXX_STANDARD 14
)

# Directorys
set (
    SOURCES_DIR ./srcs
)

set (
    SOURCES_SHARK_SHELL
    ${SOURCES_DIR}/Main.cpp
    ${SOURCES_DIR}/SharkShell.cpp
    ${SOURCES_DIR}/SharkAlias.cpp
    ${SOURCES_DIR}/SharkEnv.cpp
    ${SOURCES_DIR}/SharkRc.cpp
    ${SOURCES_DIR}/SharkParser.cpp
    ${SOURCES_DIR}/SharkExec.cpp
    ${SOURCES_DIR}/SharkBuiltIn.cpp
)

include_directories(
  includes
)

include_directories(
  ${CURSES_INCLUDE_DIR}
)


add_executable (
    SharkShell
    ${SOURCES_SHARK_SHELL}
)
