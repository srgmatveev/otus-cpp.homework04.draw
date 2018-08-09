cmake_minimum_required(VERSION 3.9)
set(VERSION_MAJOR 0)
set(VERSION_MINOR 0)
set(VERSION_PATCH 1)
if($ENV{TRAVIS_BUILD_NUMBER})
    set(VERSION_PATCH $ENV{TRAVIS_BUILD_NUMBER})
endif()

set(USE_X11 1) # использовать ли X11 1 - Да, 0 - Нет
IF(USE_X11)
project(draw-x VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
SET(MY_PROJECT_NAME draw-x)
ELSE()
    project(draw VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})
    SET(MY_PROJECT_NAME draw)
ENDIF()


IF( USE_X11 )
MESSAGE ( STATUS "Searching for X11..." )
FIND_PACKAGE( X11 REQUIRED)
IF ( X11_FOUND )
    INCLUDE_DIRECTORIES ( ${X11_INCLUDE_DIR} )
    LINK_LIBRARIES ( ${X11_LIBRARIES} )
    MESSAGE ( STATUS " X11_INCLUDE_DIR: " ${X11_INCLUDE_DIR} )
    MESSAGE ( STATUS " X11_LIBRARIES: " ${X11_LIBRARIES} )
    add_definitions(-DUSE_X11)
ENDIF ( X11_FOUND )
ENDIF ( USE_X11 )



set(SRC_DIR "./src")
include_directories(${SRC_DIR})

set(SOURCE_FILES main.cpp)
add_executable(${MY_PROJECT_NAME} ${SOURCE_FILES})

set_target_properties(${MY_PROJECT_NAME}  PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
        )

add_subdirectory(tests)
enable_testing()
add_test(gtest_valid_version ./tests/unit_tests/Unit_Tests_run)

install(TARGETS ${MY_PROJECT_NAME} RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT srgmatveev@gmail.com)

include (CPack)

# Doxygen Build
option(BUILD_DOC "Build Documentation" ON)

find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR ${CMAKE_CURRENT_BINARY_DIR}/build/docs)
    if(NOT EXISTS ${BUILD_DOC_DIR})
        file(MAKE_DIRECTORY ${BUILD_DOC_DIR})
    endif()

    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

    message("Doxygen buld started")
    add_custom_target(Doxygen ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)