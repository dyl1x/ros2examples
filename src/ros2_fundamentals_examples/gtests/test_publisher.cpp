/**
 * @file test_publisher.cpp
 * @author your name (you@domain.com)
 * @brief Unit test for ros2 minimal publisher node
 * @version 0.1
 * @date 2025-09-21
 * 
 * We test two main things:
 * 1. That the node is created correctly with the right name and topic
 * 2. That it publishes the expected "Hello World!" message
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <gtest/gtest.h>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class MinimalCppPublisher;

#define TESTING_EXCLUDE_MAIN // dont include main function from cppfile being tested
#include "../src/minimal_cpp_publisher.cpp"

class TestMinimalPublisher : public ::testing::Test
{
protected:
  void SetUp() override
  {
    rclcpp::init(0, nullptr);

    node = std::make_shared<MinimalCppPublisher>();
  }

  void TearDown() override
  {
    node.reset();
    rclcpp::shutdown();
  }
  std::shared_ptr<MinimalCppPublisher> node;
};

TEST_F(TestMinimalPublisher, TestNodeCreation)
{
  EXPECT_EQ(std::string(node->get_name()), std::string("minimal_cpp_publisher"));

  auto pub_endpoints = node->get_publishers_info_by_topic("/cpp_example_topic");
  EXPECT_EQ(pub_endpoints.size(), 1u);
}

TEST_F(TestMinimalPublisher, TestMessageContent)
{
  std::shared_ptr<std_msgs::msg::String> received_msg;

  auto subscription = node->create_subscription<std_msgs::msg::String>(
    "/cpp_example_topic",
    10,
    [&received_msg](const std_msgs::msg::String::SharedPtr msg){
      received_msg = std::make_shared<std_msgs::msg::String>(*msg);
    }
  );

  node->timerCallback();

  rclcpp::spin_some(node);

  EXPECT_EQ(received_msg->data.substr(0,8), "Hello W!");
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}