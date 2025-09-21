/**
 * 
 */
#include "rclcpp/rclcpp.hpp" //ros2 client library
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals; //handles time

class MinimalCppPublisher : public rclcpp::Node
{
public:
  MinimalCppPublisher() : Node("minimal_cpp_publisher"), count_(0)
  {
    publisher_ = create_publisher<std_msgs::msg::String>("/cpp_example_topic", 10);
    timer_ = create_wall_timer(500ms,
                              std::bind(&MinimalCppPublisher::timerCallback, this));
    RCLCPP_INFO(get_logger(), "publishing at 2Hz");
  }

  void timerCallback()
  {
    auto message = std_msgs::msg::String();
    message.data = "Hello W! " + std::to_string(count_++);

    publisher_->publish(message);
  }

private:
  size_t count_; 
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

#ifndef TESTING_EXCLUDE_MAIN
int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto minimal_cpp_publisher_node = std::make_shared<MinimalCppPublisher>();
  rclcpp::spin(minimal_cpp_publisher_node);

  rclcpp::shutdown();

  return 0;
}
#endif