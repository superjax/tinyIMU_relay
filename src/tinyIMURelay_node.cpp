/*!
 *  \file main.cpp
 *  \author Robert Leishman
 *  \date October 2012
 *  \brief This file runs a serial port to access range data from a a sonar rangefinder.
*/

#include <ros/ros.h>
#include "tinyIMURelay/tinyIMURelay.h"

int main(int argc, char** argv)
{
    ros::init(argc, argv, "tinyIMURelay");
    ros::NodeHandle n;

    tinyIMURelay tiny_Relay;
    ros::spin();

    return 1;
}
