/*!
 *  /file altimeter.cpp
 *  \brief Contains the methods in the Altimeter Class
 *
*/

#include "tinyIMURelay/tinyIMURelay.h"

tinyIMURelay::tinyIMURelay()
{
  nh_ = ros::NodeHandle();
  nh_private_ = ros::NodeHandle("~");
  imu_pub_ = nh_.advertise<sensor_msgs::Imu>("imu_msgs",10);

  // subscribers
  tinyIMU_sub_ = nh_.subscribe("tinyImu", 1, &tinyIMURelay::tinyIMUCallback, this);
}

// convert evart messages to altimeter messages
void tinyIMURelay::tinyIMUCallback(const tiny_msgs::tinyIMU &tinyIMU_msg)
{
  sensor_msgs::Imu bigIMU_msg;
  bigIMU_msg.header = tinyIMU_msg.header;

  bigIMU_msg.linear_acceleration.x = tinyIMU_msg.accel.x;
  bigIMU_msg.linear_acceleration.y = tinyIMU_msg.accel.y;
  bigIMU_msg.linear_acceleration.z = tinyIMU_msg.accel.z;

  bigIMU_msg.angular_velocity.x = tinyIMU_msg.gyro.x;
  bigIMU_msg.angular_velocity.y = tinyIMU_msg.gyro.y;
  bigIMU_msg.angular_velocity.z = tinyIMU_msg.gyro.z;

  // FIll Quaternion
  bigIMU_msg.orientation.w = 0.0;
  bigIMU_msg.orientation.x = 0.0;
  bigIMU_msg.orientation.y = 0.0;
  bigIMU_msg.orientation.z = 0.0;

  for(int i = 0; i<9; i++)
  {
    bigIMU_msg.angular_velocity_covariance[i] = 0;
    bigIMU_msg.linear_acceleration_covariance[i] = 0;
    bigIMU_msg.orientation_covariance[i] = 0;
  }

  imu_pub_.publish(bigIMU_msg);

}

