cmake_minimum_required(VERSION 3.15)
project(lab2 LANGUAGES CXX)

include(cmake/StandardProjectSettings.cmake)
include(cmake/Catch.cmake)
# Link this 'library' to set the c++ standard / compile-time options requested
add_library(default INTERFACE)
target_compile_features(default INTERFACE cxx_std_20)

include(cmake/CompilerWarnings.cmake)
set_project_warnings(default)

enable_testing()
add_subdirectory(catch2)

add_executable(main main.cpp cardioid.cpp)
add_executable(card_test test.cpp cardioid.cpp)

target_link_libraries(card_test PUBLIC Catch2::Catch2 default)
catch_discover_tests(card_test TEST_PREFIX words::)
