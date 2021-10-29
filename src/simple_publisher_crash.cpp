#include <ros/ros.h>
#include "ros/console.h"
#include "simple_publisher_crash/MyAlerts.h"
#include <string>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "simple_publisher_crash");

    ros::NodeHandle nh("~");

    ros::Publisher alertsPub = nh.advertise<simple_publisher_crash::MyAlerts>("/my_alerts", 1, true);

    ros::Rate loop(1);
    while (ros::ok())
    {
        ros::spinOnce();

        simple_publisher_crash::MyAlerts msg;
        simple_publisher_crash::MyAlert alert;
        alert.code = 1;
        alert.level = "";
        alert.message = "";
        for (int i = 0; i < 10; i++)
        {
            alert.code = i;
            alert.level = std::to_string(i);
            alert.message = std::to_string(i) + "msg";
            msg.alerts.push_back(alert);
        }
        // alert.code = 2;
        // msg.alerts.push_back(alert);
        // alert.code = 3;
        // msg.alerts.push_back(alert);

        alertsPub.publish(msg);

        loop.sleep();
    }

    return 0;
}