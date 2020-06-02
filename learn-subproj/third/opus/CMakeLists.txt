project(opus)

add_library(${PROJECT_NAME} SHARED ${PROJECT_SOURCE_DIR}/src/Opus.cpp)

target_include_directories(${PROJECT_NAME}
    PUBLIC
     ${PROJECT_SOURCE_DIR}/include)