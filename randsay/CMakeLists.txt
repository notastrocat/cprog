cmake_minimum_required(VERSION 3.10)
include_guard()

if (NOT TARGET randsay)
    add_library(randsay SHARED
        "${CMAKE_CURRENT_LIST_DIR}/randsay.c"
    )
    target_include_directories(randsay PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}"
    )
endif()

install(TARGETS randsay LIBRARY DESTINATION "${INSTALL_PREFIX}/lib")
install(FILES randsay.h DESTINATION "${INSTALL_PREFIX}/include")
install(FILES pithy.txt DESTINATION "${INSTALL_PREFIX}/bin")
