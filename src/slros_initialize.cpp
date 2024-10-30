#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "ready_controller";

// For Block ready_controller/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_ready_controller_std_msgs_Float64> Sub_ready_controller_234;

// For Block ready_controller/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_ready_controller_std_msgs_Float64> Pub_ready_controller_235;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

