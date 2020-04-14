cmake_minimum_required(VERSION 3.0.1)

project(coinpricecp)

# Compile main target.
add_executable(coinpricecpp src/main.cpp)

# Include libraries
add_subdirectory(vendors/cpr)
include_directories(${CPR_INCLUDE_DIRS})
target_link_libraries(coinpricecpp ${CPR_LIBRARIES})


