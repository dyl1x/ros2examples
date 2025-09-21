/**
 * @file minimal_cpp_subscriber.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-21
 * 
 * @copyright Copyright (c) 2025
 * Subscription Topics:
 * String message
 * /cpp_example_topic - stdmsgs/String
 * --------
 * Publishing Topics:
 *  None
 * 
 */

 #include "rclcpp/rclcpp.hpp"
 #include "std_msgs/msg/string.hpp"

 using std::placeholders::_1; //placeholder for callback function

 class MinimalCppSubscriber : public rclcpp::Node
 {
  public:
    MinimalCppSubscriber() : Node("minimal_cpp_subscriber")
    {
      subscriber_ = create_subscription<std_msgs::msg::String>
      (
        "/cpp_example_topic",
        10,
        std::bind(
          &MinimalCppSubscriber::topicCallback,
          this,
          _1
        )
      );
    }

    void topicCallback(const std_msgs::msg::String & msg) const
    {
      RCLCPP_INFO_STREAM(get_logger(), "I got: " << msg.data.c_str());
    }
  
  private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscriber_;

 };
 
 int main(int argc, char * argv[])
 {
  rclcpp::init(argc, argv);
  auto minimal_cpp_subscriber_node  = std::make_shared<MinimalCppSubscriber>();
  rclcpp::spin(minimal_cpp_subscriber_node);
  rclcpp::shutdown();
  return 0;
 }
 