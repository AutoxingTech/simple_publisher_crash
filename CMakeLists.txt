cmake_minimum_required(VERSION 3.16)
project(simple_publisher_crash)

include("platform_detect.cmake")

add_compile_options(-Werror)  # make all warning into error
add_compile_options(-Wno-unused-variable)
add_compile_options(-Wno-unused-parameter)
add_compile_options(-Waddress)

find_package(catkin REQUIRED
        COMPONENTS
            roscpp
            std_msgs
            ax_msgs
        )

find_package(Boost REQUIRED COMPONENTS filesystem)
# find_package(nc_runtime REQUIRED)

catkin_package(
    CATKIN_DEPENDS
        roscpp
)

include_directories(
    ${catkin_INCLUDE_DIRS}
    ${Boost_INCLUDE_DIRS}
)

add_executable(simple_publisher_crash src/simple_publisher_crash.cpp)
target_link_libraries(simple_publisher_crash ${catkin_LIBRARIES})

# Install executables and/or libraries

install(TARGETS simple_publisher_crash ax_ros_common
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
