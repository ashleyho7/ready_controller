#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "ready_controller_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block ready_controller/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_ready_controller_std_msgs_Float64> Sub_ready_controller_234;

// For Block ready_controller/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_ready_controller_std_msgs_Float64> Pub_ready_controller_235;

void slros_node_init(int argc, char** argv);

#endif
