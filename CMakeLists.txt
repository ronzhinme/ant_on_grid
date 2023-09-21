cmake_minimum_required(VERSION 3.5)

project(ant_on_grid LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ant_on_grid main.cpp)

include(GNUInstallDirs)
install(TARGETS ant_on_grid
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
