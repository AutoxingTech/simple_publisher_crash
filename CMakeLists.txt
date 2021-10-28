cmake_minimum_required(VERSION 3.16)
project(simple_publisher_crash)

add_compile_options(-Werror)  # make all warning into error
add_compile_options(-Wno-unused-variable)
add_compile_options(-Wno-unused-parameter)
add_compile_options(-Waddress)

find_package(catkin REQUIRED
        COMPONENTS
            roscpp
            std_msgs
            message_generation
        )

find_package(Boost REQUIRED COMPONENTS filesystem)

add_message_files(
  DIRECTORY
    msg
  FILES
    MyAlert.msg
    MyAlerts.msg
)

# Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
    CATKIN_DEPENDS
        roscpp
)

include_directories(
    ${catkin_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} "src/simple_publisher_crash.cpp")
add_dependencies(${PROJECT_NAME} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${catkin_LIBRARIES})

# Install executables and/or libraries

install(TARGETS ${PROJECT_NAME}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
