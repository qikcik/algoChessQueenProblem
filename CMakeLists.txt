cmake_minimum_required(VERSION 3.24)
project(project)

set(CMAKE_CXX_STANDARD 23)

#Lib
include_directories(${CMAKE_CURRENT_LIST_DIR}/public)

file(
    GLOB_RECURSE sources
    LIST_DIRECTORIES true
    CONFIGURE_DEPENDS true
    "private/*.cpp"
)

add_library(
        ${CMAKE_PROJECT_NAME}_lib
        STATIC
        ${sources}
)

add_executable(
        ${CMAKE_PROJECT_NAME}_exe
        ${sources}
        main.cpp
)

#Tests Include

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # For Windows: Prevent overriding the parent project's compiler/linker settings
FetchContent_MakeAvailable(googletest)

enable_testing()

file(
    GLOB_RECURSE sources
    LIST_DIRECTORIES true
    CONFIGURE_DEPENDS true
    "tests/*.cpp"
)

#Test target
add_executable(
    ${CMAKE_PROJECT_NAME}_tests
    ${sources}
)
target_link_libraries(
    ${CMAKE_PROJECT_NAME}_tests
    ${CMAKE_PROJECT_NAME}_lib
    GTest::gtest_main
    GTest::gmock_main
)

#Discover Test
include(GoogleTest)
gtest_discover_tests(${CMAKE_PROJECT_NAME}_tests)