cmake_minimum_required(VERSION 2.8.3)
project(tinyIMU_relay)

find_package(catkin REQUIRED COMPONENTS
  tiny_msgs
  roscpp
  sensor_msgs
)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES alt_sim
  CATKIN_DEPENDS roscpp sensor_msgs tiny_msgs
#  DEPENDS system_lib
)

include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(tinyIMU_relay 
  src/tinyIMURelay_node.cpp 
  src/tinyIMURelay.cpp 
  include/tinyIMURelay/tinyIMURelay.h)
add_dependencies(tinyIMU_relay tiny_msgs_generate_messages_cpp)

target_link_libraries(tinyIMU_relay
  ${catkin_LIBRARIES}
)
