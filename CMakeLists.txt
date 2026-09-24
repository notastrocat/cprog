cmake_minimum_required(VERSION 3.10)

# FORCE Clang (Must happen BEFORE the project() line)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

project(tiny-c-projects C CXX)
set(INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install")

add_subdirectory(greetings)
add_subdirectory(randsay)

add_executable(tiny-c-projects main.c)

target_link_libraries(tiny-c-projects greetings)
target_link_libraries(tiny-c-projects randsay)

install(TARGETS tiny-c-projects RUNTIME DESTINATION "${INSTALL_PREFIX}/bin")
