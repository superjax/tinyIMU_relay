/*!
 *  \author Robert Leishman
 *  \author David Wheeler
 *  \date October 2012
 *  \date January 2014
 *
 *  \brief This class handles the ROS communication of the Altitude information
*/


#ifndef TINYIMURELAY_H
#define TINYIMURELAY_H

#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <tiny_msgs/tinyIMU.h>

class tinyIMURelay
{

public:

  tinyIMURelay();

private:

  ros::Publisher imu_pub_;  //!< ROS publisher for publishing the altitude

  ros::Subscriber tinyIMU_sub_;

  ros::NodeHandle nh_;            //!< public node handle for subscribing, publishing, etc.
  ros::NodeHandle nh_private_;    //!< private node handle for pulling parameter values from the parameter server

  /*!
   *  \brief This function is a timer callback.  It brings in the raw data, extracts the height, and publishes it over ROS
   *
   *  The height comes in a string with R###.  The height in inches are the three numbers after the R. These numbers are
   *  converted to meters and the data is published.
  */
void tinyIMUCallback(const tiny_msgs::tinyIMU &tinyIMU_msg);

};

#endif // TINYIMURELAY_H
