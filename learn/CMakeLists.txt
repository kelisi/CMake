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
# create shared amr library （Alias Name）
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
# set(CMAKE_BUILD_TYPE RelWithDebInfo)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message("Setting build type to 'RelWithDebInfo' as none was specified.")
  set(CMAKE_BUILD_TYPE RelWithDebInfo CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release"
    "MinSizeRel" "RelWithDebInfo")
endif()

# set global compile flag
# set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DCODEC_OPUS -DCODEC_AMR" CACHE STRING "Set C++ Compiler Flags" FORCE)

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

# target compile flags
target_compile_definitions(target_main
    PRIVATE CODEC_OPUS
)

target_link_libraries(target_main 
                    PRIVATE
                        opus
                    PRIVATE
                        codec::amr)
