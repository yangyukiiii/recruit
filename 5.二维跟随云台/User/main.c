


#include "stm32f10x.h"              
#include "Delay.h"
#include "OLED.h"
#include "MPU6050.h"
#include <math.h>
#include "Servo.h"
#include "PWM.h"
#include "inv_mpu.h"

float Pitch,Roll,Yaw;								


int main(void)
{
	OLED_Init();
	MPU6050_Init();
	MPU6050_DMP_Init();

	Servo_Init();
	OLED_ShowString(1,1,"Roll:");
	OLED_ShowString(2,1,"Pitch:");
	OLED_ShowString(3,1,"Yaw:");

	while (1)
	{
	
	 
	 OLED_ShowSignedNum(1, 7, Roll, 5);
     OLED_ShowSignedNum(2, 7, Pitch, 5);
	 OLED_ShowSignedNum(3, 7, Yaw, 5);
		  MPU6050_DMP_Get_Data(&Pitch,&Roll,&Yaw);				
				Servo_SetAngle(Yaw+90);
				Servo_SetAngle3(90+Roll);
				if(Pitch >= 0)
				{
					Servo_SetAngle2(90-Pitch);
				}
			
				else if(Pitch <0)
				{
					float a = abs(Pitch);
					Servo_SetAngle2(a+90);
				}
	}
}



























