# Driver for ICM20948
# Summary
This project aims to develop a driver for ICM20948. The ICM-20948 is the world's lowest-power 9-axis motion-tracking device, making it excellent for Smartphones, Tablets, Wearable Sensors, and Internet-of-Things (IoT) applications. Auxiliary I2 C interface to external sensors, on-chip 16-bit ADCs, programmable digital filters, an inbuilt temperature sensor, and programmable interrupts are all features of the ICM-20948. I2C protocol is used to communicate between ICM20948 and the master device.  

We have developed a driver for reading 3-axis accelerometer and 3-axis gyroscope data in this project. Raspberry pi has been taken as the master device. 
# Schematic 
![image](https://user-images.githubusercontent.com/90763629/145373028-6ca682a6-c2c1-4471-b61c-f9386ed8a095.png)
# Hardware setup
![image](https://user-images.githubusercontent.com/90763629/145373639-8580bc20-f7b5-43c4-8e68-c7d0b5146165.png)
# connections
![image](https://user-images.githubusercontent.com/90763629/145374843-72a5760e-107b-452c-8bf7-5c5a2530f6a4.png)
# Configuration
Based on the requirements the configuration registers should be initialized in the "__init ModuleInit(void)" function in [main.c](https://github.com/h20201400222/ICM_20948/blob/8e1a77092dd8b29bf0f5aa57149a00e664e33473/main.c#L196) file.
Details of the configuration registers and electrical specifications can be found [here](https://www.waveshare.com/w/upload/1/18/DS-000189-ICM-20948-v1.3.pdf)


# Build process

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
