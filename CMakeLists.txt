cmake_minimum_required(VERSION 2.8.3)
project(ros_protocol_buffer_tutorial)

find_package(catkin REQUIRED COMPONENTS roscpp)

set(PROTOBUF_FOLDER ${PROJECT_SOURCE_DIR}/lib/protobuf-3.5.0)

set(Protobuf_INCLUDE_DIRS ${PROTOBUF_FOLDER}/include)
set(Protobuf_LIBRARIES ${PROTOBUF_FOLDER}/lib/libprotobuf.so)

catkin_package()
include_directories(include ${catkin_INCLUDE_DIRS} ${Protobuf_INCLUDE_DIRS})

add_library(addressbook_protobuf include/addressbook.pb.cc)

add_executable(main src/main.cpp)
target_link_libraries(main ${catkin_LIBRARIES} addressbook_protobuf ${Protobuf_LIBRARIES})
