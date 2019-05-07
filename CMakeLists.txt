cmake_minimum_required (VERSION 2.6)
project (LuenbergerObserver)

include_directories("${PROJECT_SOURCE_DIR}/src/utils" "${PROJECT_SOURCE_DIR}/src/luenberger")

set(SOURCES src/main.c src/utils/matrix.c src/luenberger/luenberger_observer.c)

add_executable(LuenbergerObserver ${SOURCES})