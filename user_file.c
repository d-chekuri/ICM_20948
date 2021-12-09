#include<stdio.h>
#include<stdlib.h>
#include<sys/ioctl.h>
#include<time.h>
#include<fcntl.h>
#include<signal.h>
#include<unistd.h>


#include "config.h"

int file_descript;
/*************************************************/

int ioctl_accel(int file_descript, struct accelData *message)
{
 int ret_accel;

 ret_accel = ioctl(file_descript, IOCTL_ACCEL,message);
 return ret_accel;
}

int ioctl_gyro(int file_descript, struct gyroData *message)
{
 int ret_gyro;

 ret_gyro = ioctl(file_descript, IOCTL_GYRO,message);
 return 0;
}

/************************************************************/
int main(void)
{
 int ret_val,i;
 struct gyroData gyro;
 struct accelData accel;
 float accel_x,accel_y,accel_z,gyro_x,gyro_y,gyro_z;

 file_descript = open(DEVICE_FILE_NAME,0);

 if(file_descript<0)
 {
  printf(" Failed to open device %s\n",DEVICE_FILE_NAME);
  exit(-1);
 }
 printf("Logging started...\n");

 while(1)
 {
  ioctl_accel(file_descript,&accel);
  accel_x= ((float)(accel.x))/8192;
  accel_y= ((float)(accel.y))/8192;
  accel_z= ((float)(accel.z))/8192;

  printf("accelerometer readings: x:%f , y:%f, z:%f\n",accel_x,accel_y,accel_z);
sleep(1);
ioctl_gyro(file_descript,&gyro);
  gyro_x= ((float)(gyro.x))/32.8;
  gyro_y= ((float)(gyro.y))/32.8;
  gyro_z= ((float)(gyro.z))/32.8;

  printf("gyroscope readings: x:%f , y:%f, z:%f\n",gyro_x,gyro_y,gyro_z);
  sleep(1);
 }
}
