#include <ros/ros.h>
#include "ros/console.h"
#include "ax_msgs/Alerts.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "monitor_test");

    ros::NodeHandle nh("~");

    ros::Publisher alertsPub = nh.advertise<ax_msgs::Alerts>("/alerts", 1, true);

    ros::Rate loop(1);
    while (ros::ok())
    {
        ros::spinOnce();

        ax_msgs::Alerts result;
        ax_msgs::Alert alert;
        // result->alerts.reserve(16);
        alert.code = 1;
        alert.level = "";
        alert.msg = "";
        result.alerts.push_back(alert);
        alert.code = 2;
        result.alerts.push_back(alert);
        alert.code = 3;
        result.alerts.push_back(alert);
        alertsPub.publish(result);

        loop.sleep();
    }

    return 0;
}