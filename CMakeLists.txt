cmake_minimum_required(VERSION 3.25)
project(ufm_client_cli)

# for creating the generated rest client library, static
set(BUILD_SHARED_LIBS
    OFF
    CACHE BOOL "Create shared libs by defualt"
)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # for debug

# generate the ufm rest client, using the server api file (ufm_rest_server_api.yaml)
set(UFM_SERVER_REST_API_FILE ufm_rest_server_api.yaml)
set(UFM_CLIENT_GENERATED_FOLDER "${CMAKE_BINARY_DIR}/ufm_client_generated")
set(GENERATE_REST_CLIENT
    openapi-generator
    generate
    -i
    ${UFM_SERVER_REST_API_FILE}
    -g
    c
    -o
    ${UFM_CLIENT_GENERATED_FOLDER}
)
execute_process(
  COMMAND ${GENERATE_REST_CLIENT} #
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} #
                    COMMAND_ERROR_IS_FATAL ANY #
)
add_subdirectory(${UFM_CLIENT_GENERATED_FOLDER})

# ufm rest client cli - here it just send a demo sharp_am telemetry
add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ufm_rest_api)

# install cli & library
include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
