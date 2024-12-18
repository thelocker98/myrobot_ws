#!/usr/bin/env python
import rclpy
from rclpy.node import Node

from my_robot_interfaces.msg import HardwareStatus

class HardwareStatusPublisherNode(Node):
    def __init__(self):
        super().__init__("hardware_status_publisher")

        self.publisher_ = self.create_publisher(HardwareStatus, "hw_status", 10)
        self.timer_ = self.create_timer(0.5, self.publish_news)
        self.get_logger().info("Hardware status has been started.")

    def publish_news(self):
        msg = HardwareStatus()
        msg.temperature = 25
        msg.are_motors_ready = True
        msg.debug_message = "Everything is working."

        self.publisher_.publish(msg)



def main (args=None):
    rclpy.init(args=args)
    node = HardwareStatusPublisherNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == '__main__':
    main()