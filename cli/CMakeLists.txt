cmake_minimum_required(VERSION 3.1.0)
project(IrisCompareCli)

# with out -std=c++11 or -std=c++17 cxxopts gets errors
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    message("-- System: Mac OS")
    find_package(OpenCV 3.4 REQUIRED PATHS /usr/local/opt/opencv@3)
elseif (CMAKE_SYSTEM_NAME MATCHES "Linux")
    message("-- System: Linux")
    find_package(OpenCV 3.4 REQUIRED)
endif()

# spdlog lib.
find_package(spdlog REQUIRED)

message("-- OCV version: " ${OpenCV_VERSION} )
message("-- OCV include: " ${OpenCV_INCLUDE_DIRS})
message("-- OCV libs: " ${OpenCV_LIBS})

if (${OpenCV_VERSION} VERSION_LESS 3.4)
    message(FATAL_ERROR "OpenCV version is not compatible : ${OpenCV_VERSION}")
endif()

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
    /usr/local/alphablocks/include
)

file(GLOB IRIS_COMPARE_SRC include/*.h include/*.hpp src/*.cpp)

find_package(OpenCV 3.4 REQUIRED)
link_directories(
   /usr/local/lib
   ${OpenCV_LIBRARY_DIRS}
   /usr/local/alphablocks/lib
)
set(LIBRARIES
    IrisAnalysisLib
    IrisLib
)
add_executable(${PROJECT_NAME} ${IRIS_COMPARE_SRC})
target_link_libraries(${PROJECT_NAME}
    ${OpenCV_LIBS}
    spdlog::spdlog_header_only
    ${LIBRARIES}
)
