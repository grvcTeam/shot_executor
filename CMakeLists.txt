cmake_minimum_required(VERSION 2.8.3)
project(shot_executor)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++17)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  tf
  roslaunch
  std_msgs
  std_srvs
  nav_msgs
  geometry_msgs
  mavros_msgs
)
find_package(PythonLibs 2.7)
find_package(Eigen3 REQUIRED)

add_message_files(
  FILES
  DesiredShot.msg
)

add_service_files(
  FILES
  ShootingAction.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
  nav_msgs
)

catkin_package(
 INCLUDE_DIRS include
  LIBRARIES shot_executor_library
  CATKIN_DEPENDS roscpp rospy tf std_msgs std_srvs 
)



include_directories(
  include
  LIBRARIES shot_executor_library

  ${catkin_INCLUDE_DIRS}
  ${PYTHON_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIR}

)

## Declare a C++ library
add_library(shot_executor_library
  src/shot_executor.cpp
)

add_executable(shot_executor_node src/main.cpp src/shot_executor_UAL.cpp)

target_link_libraries(shot_executor_node shot_executor_library
${catkin_LIBRARIES} ${EXTRALIB_BIN} ${PYTHON_LIBRARIES} ${Eigen3_LIBRARIES})

add_dependencies(shot_executor_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
