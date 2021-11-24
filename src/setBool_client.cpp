#include <ros/ros.h>
#include <std_srvs/SetBool.h>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "setBool_client");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<std_srvs::SetBool>("setBool_service");

    ros::Rate loop_rate(2);
    std_srvs::SetBool srv;
    srv.request.data = true;
    while(ros::ok())
    {
        
        if(client.call(srv)){
            std::cout<<"responce from server"<<std::endl;
            srv.request.data = !srv.request.data;
        }
        loop_rate.sleep();
    }

    return 0;
}