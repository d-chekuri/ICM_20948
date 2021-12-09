# ICM_20948 Driver
Driver for ICM20948

This project aims to develop a driver for ICM20948. The ICM-20948 is the world's lowest-power 9-axis motion-tracking device, making it excellent for Smartphones, Tablets, Wearable Sensors, and Internet-of-Things (IoT) applications. Auxiliary I2 C interface to external sensors, on-chip 16-bit ADCs, programmable digital filters, an inbuilt temperature sensor, and programmable interrupts are all features of the ICM-20948. I2C protocol is used to communicate between ICM20948 and the master device.  

We have developed a driver for reading 3-axis accelerometer and 3-axis gyroscope data in this project. Raspberry pi has been taken as the master device. 

Build process:

step-1
Setup the Raspberry-pi for I2C communication and install the Kernel headers

         sudo apt-get update
Step-2
Change the directory to the present directory with required files (main.c, config.h, user_file.c, Makefile)

        sudo cd /dd_proj
step-3
Generate kernel object file  for the kernel code

       sudo make all
step-4
Insert the kernel module 

       sudo insmod main.ko
step-5
check the accelerometer and gyroscope raw data 

       sudo cat /dev/imu20948
step-6
check the accelerometer and gyroscope data using userspace file

       sudo ./user_file
