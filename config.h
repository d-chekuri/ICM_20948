#define MAGIC_NUM 225


struct gyroData  // struct for gyro sensor data
{
 int16_t x;
 int16_t y;
 int16_t z;
};

struct accelData // struct for accel sensor data
{
 int16_t x;
 int16_t y;
 int16_t z;
};

//IOCTL interface prototypes

#define IOCTL_GYRO  _IOWR(MAGIC_NUM, 0, struct gyroData*)
#define IOCTL_ACCEL  _IOWR(MAGIC_NUM, 1, struct accelData*)

//Device file interface
#define DEVICE_FILE_NAME "/dev/imu20948"
