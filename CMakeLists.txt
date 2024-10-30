cmake_minimum_required(VERSION 3.9)
project(ready_controller)
set(CMAKE_VERBOSE_MAKEFILE ON)
# Set CMAKE_BUILD_TYPE
set(CMAKE_BUILD_TYPE Release)
# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()
# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()
if(ALIAS_ROS1_CLASS_LOADER)
    add_definitions(-Dclass_loader=ros1_class_loader)
endif()
## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
  CATKIN_DEPENDS
  roscpp
  std_msgs
  INCLUDE_DIRS include
)
###########
## Build ##
###########
## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  include
  ${PROJECT_SOURCE_DIR}
  ${Boost_INCLUDE_DIRS}
  ${catkin_INCLUDE_DIRS}
  "include/ready_controller"
)
set (CMAKE_SKIP_BUILD_RPATH false)
set (CMAKE_BUILD_WITH_INSTALL_RPATH true)
set (CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set (CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
## Get list of .c files in project source directory
file(GLOB ${PROJECT_NAME}_C_SOURCES RELATIVE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/*.c)
## Get list of .cpp files in project source directory
file(GLOB ${PROJECT_NAME}_CPP_SOURCES RELATIVE ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/*.cpp)
# Declare executable - Node
add_executable(ready_controller
  src/slros_generic_param.cpp
  src/main.cpp
  src/ready_controller.cpp
  src/ready_controller_data.cpp
  src/rosnodeinterface.cpp
  src/rtGetInf.cpp
  src/rtGetNaN.cpp
  src/rt_nonfinite.cpp
  src/slros_busmsg_conversion.cpp
  src/slros_initialize.cpp
)
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
#target_compile_options(ready_controller PUBLIC  $<$<OR:$<COMPILE_LANGUAGE:CXX>,$<COMPILE_LANGUAGE:C>>: -Wall -Wextra -Wpedantic >)
endif()
target_compile_options(ready_controller PUBLIC 
  $<$<OR:$<COMPILE_LANGUAGE:CXX>,$<COMPILE_LANGUAGE:C>>:
  -DMODEL=ready_controller
  -DNUMST=2
  -DNCSTATES=3
  -DHAVESTDIO
  -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
  -DCLASSIC_INTERFACE=0
  -DALLOCATIONFCN=0
  -DTID01EQ=1
  -DONESTEPFCN=1
  -DTERMFCN=1
  -DMULTI_INSTANCE_CODE=0
  -DINTEGER_CODE=0
  -DMT=0
  -DROS_PROJECT
  -DMW_SCHED_OTHER
  -DSTACK_SIZE=64
  -D__MW_TARGET_USE_HARDWARE_RESOURCES_H__
  -DRT=RT
     -fpermissive  >
  )
## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
add_dependencies(
  ready_controller
  ${catkin_EXPORTED_TARGETS}
)
target_include_directories(ready_controller PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
## Specify libraries to link a library or executable target against
target_link_libraries(
  ready_controller 
    ${catkin_LIBRARIES}
    ${Boost_LIBRARIES}
    ${CMAKE_DL_LIBS}
)
install(TARGETS ready_controller
  EXPORT export_${PROJECT_NAME}
  DESTINATION lib/${PROJECT_NAME})
foreach(file_i ${CUDA_BINS})
add_custom_command(
                   TARGET ready_controller
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND}
                   ARGS -E copy ${PROJECT_SOURCE_DIR}/src/${file_i} ${CATKIN_DEVEL_PREFIX}/codegen/exe/ready_controller/${file_i}
				   )
add_custom_command(
                   TARGET ready_controller
                   POST_BUILD
                   COMMAND ${CMAKE_COMMAND}
                   ARGS -E copy ${PROJECT_SOURCE_DIR}/src/${file_i} ${CATKIN_DEVEL_PREFIX}/ready_controller_ert_rtw/${file_i}
				   )
endforeach(file_i)
# Generated on Wed Oct 30 08:46:41 2024
