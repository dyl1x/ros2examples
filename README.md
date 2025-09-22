files will go to ~/ros2_ws/

this will be the colcon workspace.

bash aliases:
source /opt/ros/jazzy/setup.bash
source ~/ros2_ws/install/setup.bash
alias build='cd ~/ros2_ws && colcon build'
alias sourcebash='source ~/.bashrc'

running node: ros2 run ....

gtest compile and:
colcon test --packages-select ros2_fundamentals_examples --event-handlers console_direct+

RHR coordinates z thumb, x pointer, y coming out of the screen

make ros package:
ros2 pkg create --build-type ament_cmake --license BSD-3-Clause mycobot_description

make meta package: list of dependent packages. cobot_ros2 is the name of the package, also name of the parent dir of the source code.
ros2 pkg create --build-type ament_cmake --license BSD-3-Clause cobot_ros2

make the xacro urdfs
touch ~/ros2_ws/src/mycobot_ros2/mycobot_description/urdf/mech/{g_shape_base_v2_0.urdf.xacro,adaptive_gripper.urdf.xacro,mycobot_280_arm.urdf.xacro} ~/ros2_ws/src/mycobot_ros2/mycobot_description/urdf/robots/mycobot_280.urdf.xacro

to generate the coordinate frames pdfs, with flow chart:
ros2 run tf2_tools view_frames
to open pdf:
evince frames_YYYY-MM-DD_HH.MM.SS.pdf 
