project(target_main)

add_subdirectory(third/amr)
add_subdirectory(third/opus)

add_executable(${PROJECT_NAME} 
    src/main.cpp
    src/tool.c)

target_compile_definitions(${PROJECT_NAME} PRIVATE CODEC_OPUS CODEC_AMR)

target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME}
                    PRIVATE 
                        opus
                    PRIVATE
                        amr)