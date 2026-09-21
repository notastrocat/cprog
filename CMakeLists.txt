cmake_minimum_required(VERSION 3.10)

# FORCE Clang (Must happen BEFORE the project() line)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

project(tiny-c-projects C CXX)
set(INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install")

add_executable(tiny-c-projects 01greet.c)
install(TARGETS tiny-c-projects RUNTIME DESTINATION "${INSTALL_PREFIX}/bin")
