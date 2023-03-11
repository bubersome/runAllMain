cmake_minimum_required(VERSION 3.20)
project(MyProject)

set(CMAKE_CXX_STANDARD 14)

# 搜索所有的 main 文件
file(GLOB_RECURSE MAIN_FILES "${CMAKE_SOURCE_DIR}/*.cpp")

# 为每个 main 文件生成可执行文件
foreach(MAIN_FILE ${MAIN_FILES})
    # 获取文件名和目录名
    get_filename_component(BASE_NAME ${MAIN_FILE} NAME_WE)
    get_filename_component(DIR_NAME ${MAIN_FILE} DIRECTORY)

    # 创建 build 目录，用于存放编译产生的文件
    set(BUILD_DIR "${DIR_NAME}/build")
    file(MAKE_DIRECTORY ${BUILD_DIR})

    # 为当前 main 文件生成可执行文件
    add_executable(${BASE_NAME} ${MAIN_FILE})
    set_target_properties(${BASE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})
endforeach()
