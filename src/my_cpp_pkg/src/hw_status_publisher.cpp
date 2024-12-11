#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/msg/hardware_status.hpp"

class HardwareStatusPublisherNode : public rclcpp::Node
{
public:
    HardwareStatusPublisherNode() : Node("hardware_status_publisher")
    {
        publisher_ = this->create_publisher<my_robot_interfaces::msg::HardwareStatus>("hw_status", 10);
        timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&HardwareStatusPublisherNode::publishNews, this));
        RCLCPP_INFO(this->get_logger(),"Hardware status has been started.");
    }

private:
    void publishNews()
    {
        auto msg = my_robot_interfaces::msg::HardwareStatus();
        msg.temperature = 25;
        msg.are_motors_ready = true;
        msg.debug_message = "Everything is working.";
        publisher_->publish(msg);
    }


    std::string robot_name_;
    rclcpp::Publisher<my_robot_interfaces::msg::HardwareStatus>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<HardwareStatusPublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}