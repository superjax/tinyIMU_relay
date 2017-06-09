# tinyIMU_relay

A package designed to relay messages from the tinyIMU messages published by the arduino running the sketch found in https://github.com/superjax/tinyIMU_arduino to full IMU messages recognized by the rest of ROS.

## Scaling for MPU6050

When using the MPU6050, the raw sensor value are scaled corresponding to the sensitivity of the sensor and in an odd range. When setting the ros parameter 'scale' = true, the readings will be scaled to [m/s²] (accel) and [rad/s] (gyro). These units are defined as a standard in [sensor_msgs/Imu](http://docs.ros.org/api/sensor_msgs/html/msg/Imu.html).

To use the scaling function run
```
rosrun tinyIMU_relay tinyIMU_relay _scale:=true
```


This works with the standard MPU6050 settings AFS_SEL=0 and FS_SEL=0 which corresponds to a sensitivity of +-2g for the accelerometer and +-250 degree/second for the gyro. The scaling factor to get from the reading to [g] (accel) and [deg/s] (gyro) is 16,384 and 131. The readings are then scaled from [g] to [m/s²] and from [deg/s] to [rad/s]. The values come from the [MPU6050 Datasheet Page 12-13](https://www.invensense.com/wp-content/uploads/2015/02/MPU-6000-Datasheet1.pdf).

This is usefull when using the imu data for another package like [imu_complementary_filter](http://wiki.ros.org/imu_complementary_filter). Don't forget to [calibrate](https://www.i2cdevlib.com/forums/topic/96-arduino-sketch-to-automatically-calculate-mpu6050-offsets/) the sensor offsets.
