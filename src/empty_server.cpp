#include <ros/ros.h>
#include <std_srvs/Empty.h>

bool handle(std_srvs::Empty::Request &req, std_srvs::Empty::Response &res)
{
    std::cout<<"service call"<<std::endl;
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "empty_server");
    ros::NodeHandle nh;

    ros::ServiceServer server = nh.advertiseService("empty_service", handle);

    ros::spin();
}