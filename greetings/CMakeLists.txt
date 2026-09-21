cmake_minimum_required(VERSION 3.10)
include_guard()

if (NOT TARGET greetings)
    add_library(greetings SHARED
        "${CMAKE_CURRENT_LIST_DIR}/greet.c"
    )
    target_include_directories(greetings PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}"
    )
endif()

install(TARGETS greetings LIBRARY DESTINATION "${INSTALL_PREFIX}/lib")
install(FILES greet.h DESTINATION "${INSTALL_PREFIX}/include")
