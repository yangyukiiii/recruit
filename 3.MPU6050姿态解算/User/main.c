#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "MPU6050.h"
#include "inv_mpu.h"

float Pitch,Roll,Yaw;								
int16_t ax,ay,az,gx,gy,gz;	

u8 MPU_Get_Gyroscope(short *gx,short *gy,short *gz);
u8 MPU_Get_Accelerometer(short *ax,short *ay,short *az);

int main(void)
{
	OLED_Init();
	MPU6050_Init();
	MPU6050_DMP_Init();
	OLED_ShowString(1,1,"Pitch:");
	OLED_ShowString(2,1,"Roll:");
	OLED_ShowString(3,1,"Yaw:");
	while (1)
	{
		MPU6050_DMP_Get_Data(&Pitch,&Roll,&Yaw);				
		MPU_Get_Gyroscope(&gx,&gy,&gz);
		MPU_Get_Accelerometer(&ax,&ay,&az);


		OLED_ShowSignedNum(1, 7, Pitch, 5);
		OLED_ShowSignedNum(2, 7, Roll, 5);
		OLED_ShowSignedNum(3, 7, Yaw, 5);
		
	}
}
