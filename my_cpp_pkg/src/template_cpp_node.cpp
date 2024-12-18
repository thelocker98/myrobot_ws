#include "rclcpp/rclcpp.hpp"

class MyCustomeNode : public rclcpp::Node // MODIFY NAME
{
public:
    MyCustomeNode() : Node("node_name") // MODIFY NAME
    {
    }

private:
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyCustomeNode>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}