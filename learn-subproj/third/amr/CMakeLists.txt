project(amr)

add_library(${PROJECT_NAME}
             STATIC
                 ${PROJECT_SOURCE_DIR}/src/Amr.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC
     ${PROJECT_SOURCE_DIR}/include)