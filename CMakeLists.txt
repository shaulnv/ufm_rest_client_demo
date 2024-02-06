cmake_minimum_required(VERSION 3.25)
project(openopi-generated-client)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.cpp)
add_subdirectory(generated)
target_link_libraries(${PROJECT_NAME} PRIVATE ufm_rest_api)