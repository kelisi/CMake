cmake_minimum_required(VERSION 3.5)

project(learn_cmake)


################################
# create static opus library
################################
add_library(opus STATIC third/opus/src/Opus.cpp)

# PUBLIC: used for this library && target who links this lib
# PRIVATE: used for this library
# INTERFACE: used for target who links this lib
target_include_directories(opus 
                        PUBLIC 
                            ${PROJECT_SOURCE_DIR}/third/opus/include)

################################
# create shared amr library
################################
add_library(amr SHARED third/amr/src/Amr.cpp)
add_library(codec::amr ALIAS amr)

target_include_directories(amr
                        PUBLIC
                            ${PROJECT_SOURCE_DIR}/third/amr/include)

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
                        opus
                    PRIVATE
                        codec::amr)
