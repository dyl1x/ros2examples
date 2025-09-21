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


