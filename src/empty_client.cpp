#include <ros/ros.h>
#include <std_srvs/Empty.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "empty_client");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<std_srvs::Empty>("empty_service");

    ros::Rate loop_rate(2);
    std_srvs::Empty srv;
    while(ros::ok())
    {
        if(client.call(srv)){
            std::cout<<"responce from server"<<std::endl;
        }
        loop_rate.sleep();
    }

    return 0;
}