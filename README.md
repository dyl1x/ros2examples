files will go to ~/ros2_ws/

this will be the colcon workspace.

##
bash aliases:
source /opt/ros/jazzy/setup.bash
source ~/ros2_ws/install/setup.bash
alias build='cd ~/ros2_ws && colcon build'
alias sourcebash='source ~/.bashrc'
##

running node: ros2 run ....

gtest compile and:
colcon test --packages-select ros2_fundamentals_examples --event-handlers console_direct+

## theory
RHR coordinates z thumb, x pointer, y coming out of the screen

## 
make ros package:
ros2 pkg create --build-type ament_cmake --license BSD-3-Clause mycobot_description

##
make meta package: list of dependent packages. cobot_ros2 is the name of the package, also name of the parent dir of the source code.
ros2 pkg create --build-type ament_cmake --license BSD-3-Clause cobot_ros2
or
ros2 pkg create --build-type ament_cmake \
                --license BSD-3-Clause \
                --maintainer-name ubuntu \
                --maintainer-email email@todo.com \
                yahboom_rosmaster_bringup

make the xacro urdfs
touch ~/ros2_ws/src/mycobot_ros2/mycobot_description/urdf/mech/{g_shape_base_v2_0.urdf.xacro,adaptive_gripper.urdf.xacro,mycobot_280_arm.urdf.xacro} ~/ros2_ws/src/mycobot_ros2/mycobot_description/urdf/robots/mycobot_280.urdf.xacro

to generate the coordinate frames pdfs, with flow chart:
ros2 run tf2_tools view_frames
to open pdf:
evince frames_YYYY-MM-DD_HH.MM.SS.pdf
to launch the model in rviz:
ros2 launch urdf_tutorial display.launch.py model:=/home/chamath/ros2_ws/src/yahboom_rosmaster/yahboom_rosmaster_description/urdf/robots/rosmaster_x3.urdf.xacro


make a file executable: sudo chmod +x file.sh

## which pkg are we using right now, if we have similar or duplicates:
ros2 pkg prefix name_of_pkg

## make robot sim
1 make packages:
- robot (main pkg)
  - robot
  - robot description
  - gazebo
  - system_tests

2 add the sub packages to the package.xml of main robot as <exec_depend>

3 add this block to package.xml in gazebo pkg for gz integration:
<depend>controller_manager</depend>
<depend>gz_ros2_control</depend>
<depend>python3-numpy</depend>
<depend>rclcpp</depend>
<depend>ros_gz</depend>
<depend>ros_gz_bridge</depend>
<depend>ros_gz_image</depend>
<depend>ros_gz_sim</depend>
<depend>ros2_control</depend>
<depend>ros2_controllers</depend>
<depend>trajectory_msgs</depend>
<depend>xacro</depend>
<exec_depend>gz_ros2_control_demos</exec_depend>
<exec_depend>rqt_robot_steering</exec_depend>
<exec_depend>rviz_imu_plugin</exec_depend>

4 add them to cmakelists as well. of gz pkg
find_package(ament_cmake REQUIRED)
find_package(controller_manager REQUIRED)
find_package(gz_ros2_control REQUIRED)
find_package(rclcpp REQUIRED)
find_package(ros_gz REQUIRED)
find_package(ros_gz_bridge REQUIRED)
find_package(ros_gz_image REQUIRED)
find_package(ros_gz_sim REQUIRED)
find_package(ros2_control REQUIRED)
find_package(ros2_controllers REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(xacro REQUIRED)

5 build

6 install depends:
rosdep install -i --from-path src --rosdistro $ROS_DISTRO -y

7 build and source

8 world files
# make world files
these go inside the gz pkg, -gazebo/worlds
mkdir -p worlds launch models

make a filename.world file and copy the code from a template work file.
add models to the folder

9 yaml config. tell ros2 control how to manage the robot movements.
file goes in robot/robot_description/config/robot/

10 make the .urdf.xacro files
they all go in urdf/control. the urdf.xacro file inside robot should know about these files. (its at the bottom)

11 make launch files
these go in the bring up tree. inside /launch/

12 yaml file for ros2 bridge
specify how sensor data translates between ros2 and gazebo
goes in _gazebo/config/

13 add the rviz config to robot_gazebo/rviz/file.rviz

14 make the gazebo launch file in robot_gazebo/launch/

15 bash script for quick launching: _bringup/scripts

## debugging
rqt console
ros2 run rqt_console rqt_console