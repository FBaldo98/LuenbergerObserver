cmake_minimum_required (VERSION 3.0)
project (LuenbergerObserver)

set (CMAKE_C_FLAGS "-std=c99 ${CMAKE_C_FLAGS}")

set (CMAKE_BUILD_TYPE Debug)

include_directories("${PROJECT_SOURCE_DIR}/src/utils" "${PROJECT_SOURCE_DIR}/src/luenberger")

set(SOURCES src/main.c src/utils/matrix.c src/luenberger/luenberger_observer.c)

add_executable(LuenbergerObserver ${SOURCES})