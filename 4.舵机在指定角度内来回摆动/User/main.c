#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Servo.h"


uint8_t KeyNum;
float Angle;

int main(void)
{
	OLED_Init();
	Servo_Init();
	
	
	OLED_ShowString(1, 1, "Angle:");
	
	while (1)
	{
		
		Angle += 1;
		Delay_ms(20);
		if (Angle > 180)
		{
			Angle = 0;
		}
		
		Servo_SetAngle(Angle);
		OLED_ShowNum(1, 7, Angle, 3);
	}
}
