

cmake_minimum_required(VERSION 3.8)
project(failsafe_bridge_cpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(mavros_msgs REQUIRED)

add_executable(failsafe_bridge_node
  src/failsafe_bridge_node.cpp
)

ament_target_dependencies(failsafe_bridge_node
  rclcpp
  sensor_msgs
  mavros_msgs
)

install(TARGETS
  failsafe_bridge_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
