
include(FetchContent)

# Adding modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH})

function(nanopb_fetch)
    if(NANOPB_PATH)
        message(INFO "NANOPB_PATH specified, skipping fetch")
    endif()

    FetchContent_Declare(
        nanopb
        GIT_REPOSITORY  https://github.com/SwarmUS/nanopb
        GIT_TAG        07fe03e09cb20973b48802b5a4c21a10b15ae166
        GIT_PROGRESS   TRUE
    )
    set(NANOPB nanopb)
    string(TOLOWER ${NANOPB} NANOPB_L)

    FetchContent_GetProperties(${NANOPB} POPULATED NANOPB_POPULATED)
    if(NOT NANOPB_POPULATED)
        message("Cloning nanopb library")
        set(FETCHCONTENT_QUIET FALSE) # To see progress
        FetchContent_Populate(${NANOPB})
    endif()
    add_subdirectory(${${NANOPB_L}_SOURCE_DIR} ${${NANOPB_L}_BINARY_DIR})

    list(APPEND CMAKE_MODULE_PATH ${${NANOPB_L}_SOURCE_DIR}/extra)
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} PARENT_SCOPE)
    set(NANOPB_PATH ${${NANOPB_L}_SOURCE_DIR} PARENT_SCOPE)

endfunction()
