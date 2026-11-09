
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "mavros_msgs/msg/state.hpp"
#include "sensor_msgs/msg/battery_state.hpp"

class FailsafeBridgeNode : public rclcpp::Node
{
public:
    FailsafeBridgeNode()
    : Node("failsafe_bridge_node")
    {
        // Subscribe to the flight controller state
        state_sub_ = this->create_subscription<mavros_msgs::msg::State>(
            "/mavros/state",
            10,
            std::bind(
                &FailsafeBridgeNode::state_callback,
                this,
                std::placeholders::_1
            )
        );

        // Subscribe to the battery information
        battery_sub_ = this->create_subscription<sensor_msgs::msg::BatteryState>(
            "/mavros/battery",
            10,
            std::bind(
                &FailsafeBridgeNode::battery_callback,
                this,
                std::placeholders::_1
            )
        );

        RCLCPP_INFO(this->get_logger(), "Failsafe Bridge Node started");
    }

private:
    void state_callback(const mavros_msgs::msg::State::SharedPtr msg)
    {
        RCLCPP_INFO(
            this->get_logger(),
            "Connected: %s | Armed: %s | Mode: %s",
            msg->connected ? "true" : "false",
            msg->armed ? "true" : "false",
            msg->mode.c_str()
        );
    }

    void battery_callback(const sensor_msgs::msg::BatteryState::SharedPtr msg)
    {
        RCLCPP_INFO(
            this->get_logger(),
            "Battery voltage: %.2f V | Percentage: %.1f%%",
            msg->voltage,
            msg->percentage * 100.0
        );
    }

    rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr state_sub_;
    rclcpp::Subscription<sensor_msgs::msg::BatteryState>::SharedPtr battery_sub_;
};

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    rclcpp::spin(std::make_shared<FailsafeBridgeNode>());

    rclcpp::shutdown();
    return 0;
}

