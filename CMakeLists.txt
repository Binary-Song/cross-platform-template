cmake_minimum_required(VERSION 3.0.0)
project(${PROJECT_NAME} VERSION 0.1.0)

include(CTest)
enable_testing()

add_compile_definitions(PROJECT_NAME="${PROJECT_NAME}")
add_compile_definitions(BUILD="${BUILD}")
add_compile_definitions(LINUX=1)
add_compile_definitions(WINDOWS=2)

#定义PLATFORM宏,值为LINUX或WINDOWS(如果是GNU编译器，则说明在LINUX平台，否则在WINDOWS平台)。
if(CMAKE_COMPILER_IS_GNUCXX)
    add_compile_definitions(PLATFORM=LINUX)
else()
    add_compile_definitions(PLATFORM=WINDOWS)
endif()

#如果是DEBUG模式，就定义DEBUG宏
if("${VARIANT}" STREQUAL "Debug")
    add_compile_definitions(DEBUG)
endif()

aux_source_directory(src SRC)
add_executable(${PROJECT_NAME}  ${SRC})

target_include_directories(${PROJECT_NAME}  PUBLIC include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
