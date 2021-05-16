#include <wiringPiI2C.h>
#include <stdio.h>

int main(void)
{
	int handle = wiringPiI2CSetup(0x23);
	while(1)
	{
		wiringPiI2CWrite(handle, 0x21);
		sleep(1);
		int word = wiringPiI2CReadReg16(handle, 0x00);
		int lux = ((word & 0xff00)>>8) | ((word & 0x00ff)<<8);
		//printf("Current Lux: %d\n", lux);
		if (lux <= 10.0)
		{
			 printf("too dark\n");
		}
		else if (lux > 10.0 & lux <= 30.0)
		{
			printf("dark\n");
		}
		else if (lux > 30.0 & lux <= 400.0)
		{
			 printf("medium\n");
		}
		else if (lux > 400.0 & lux <= 900.0)
		{
			printf("bright\n");
		}
		else
		{
			printf("too bright\n");
		}
	}
	return 0;
}
