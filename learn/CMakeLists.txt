cmake_minimum_required(VERSION 3.5)

project(learn_cmake)


################################
# create opus library
################################
add_library(opus STATIC third/opus/src/Opus.cpp)

target_include_directories(opus 
                        PUBLIC 
                            ${PROJECT_SOURCE_DIR}/third/opus/include)

################################
# create executable
################################

# RelWithDebInfo(code optimize) or DEBUG
set(CMAKE_BUILD_TYPE RelWithDebInfo)

set(SOURCES 
        src/HelloCmake.cpp
        main.cpp
)

# target 
add_executable(target_main ${SOURCES})

# target name
target_include_directories(target_main 
                        PRIVATE 
                            ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(target_main 
                    PRIVATE
                        opus)
