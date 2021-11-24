#include <ros/ros.h>
#include <std_srvs/SetBool.h>

bool handle(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res)
{
    if(req.data){
        std::cout<<"true"<<std::endl;
    }else{
        std::cout<<"false"<<std::endl;
    }
    
    return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "setBool_server");
    ros::NodeHandle nh;

    ros::ServiceServer service = nh.advertiseService("setBool_service", handle);

    ros::spin();
}