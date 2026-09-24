cmake_minimum_required(VERSION 3.10)
include_guard()

if (NOT TARGET reed)
    add_library(reed SHARED
        "${CMAKE_CURRENT_LIST_DIR}/02reed.c"
    )
    target_include_directories(reed PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}"
    )
endif()

install(TARGETS reed LIBRARY DESTINATION "${INSTALL_PREFIX}/lib")
install(FILES reed.h DESTINATION "${INSTALL_PREFIX}/include")
install(FILES pithy.txt DESTINATION "${INSTALL_PREFIX}/bin")
