cmake_minimum_required(VERSION 3.19)
project(Covid19Graph-India)
set(CMAKE_CXX_STANDARD 20)
include(FetchContent)

FetchContent_Declare(json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        GIT_TAG v3.7.3)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
    FetchContent_Populate(json)
    add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

add_executable(Covid19Graph-India node.h graph.h main.cpp node.h)

target_link_libraries(Covid19Graph-India PRIVATE nlohmann_json::nlohmann_json)