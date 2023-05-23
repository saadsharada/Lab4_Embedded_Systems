#include "GPIO_Address.h"
#include "Rcc.h"
#include "Std_Types.h"

int main()
{

	uint32 i = 0;
	uint8 flag = 0, status = 0;
	Rcc_Init();
	Rcc_Enable(RCC_GPIOB);
	Gpio_ConfigPin(GPIO_B, 3, GPIO_INPUT, GPIO_PULL_UP);
	for (i = 5; i < 8; i++)
	{
		Gpio_ConfigPin(GPIO_B, i, GPIO_OUTPUT, GPIO_PUSH_PULL);
	}

	while (1)
	{

		if (Gpio_ReadPin(GPIO_B, 3) == 0)
		{
			for (i = 0; i <= 80000; i++)
				;
			if (Gpio_ReadPin(GPIO_B, 3) == 0 && flag == 0)
			{
				switch (status)
				{
				case 0:
					Gpio_WritePin(GPIO_B, 5, HIGH);
					Gpio_WritePin(GPIO_B, 6, LOW);
					Gpio_WritePin(GPIO_B, 7, LOW);
					status = 1;
					break;

				case 1:
					Gpio_WritePin(GPIO_B, 5, LOW);
					Gpio_WritePin(GPIO_B, 6, HIGH);
					Gpio_WritePin(GPIO_B, 7, LOW);
					status = 2;
					break;
				case 2:
					Gpio_WritePin(GPIO_B, 5, HIGH);
					Gpio_WritePin(GPIO_B, 6, HIGH);
					Gpio_WritePin(GPIO_B, 7, LOW);
					status = 3;
					break;
				case 3:
					Gpio_WritePin(GPIO_B, 5, LOW);
					Gpio_WritePin(GPIO_B, 6, LOW);
					Gpio_WritePin(GPIO_B, 7, HIGH);
					status = 4;
					break;
				case 4:
					Gpio_WritePin(GPIO_B, 5, HIGH);
					Gpio_WritePin(GPIO_B, 6, LOW);
					Gpio_WritePin(GPIO_B, 7, HIGH);
					status = 5;
					break;
				case 5:
					Gpio_WritePin(GPIO_B, 5, LOW);
					Gpio_WritePin(GPIO_B, 6, HIGH);
					Gpio_WritePin(GPIO_B, 7, HIGH);
					status = 6;
					break;
				case 6:
					Gpio_WritePin(GPIO_B, 5, HIGH);
					Gpio_WritePin(GPIO_B, 6, HIGH);
					Gpio_WritePin(GPIO_B, 7, HIGH);
					status = 7;
					break;
				case 7:
					Gpio_WritePin(GPIO_B, 5, LOW);
					Gpio_WritePin(GPIO_B, 6, LOW);
					Gpio_WritePin(GPIO_B, 7, LOW);
					status = 0;
					break;
				}
				flag = 1;
			}
		}

		else
		{
			for (long i = 0; i <= 80000; i++)
				;
			if (Gpio_ReadPin(GPIO_B, 3) == 1)
			{
				flag = 0;
			}
		}
	}

	// Rcc_Init();
	// Rcc_Enable(RCC_GPIOA);

	// uint32 i = 0;
	// for (i = 0; i < 7; i++)
	// {
	// 	Gpio_ConfigPin(GPIO_A, i, GPIO_OUTPUT, GPIO_PUSH_PULL);
	// }
	// uint8 counter = 0;
	// while (1)
	// {
	// 	switch (counter)
	// 	{
	// 	case 0:
	// 		Gpio_WritePin(GPIO_A, 0, HIGH);
	// 		Gpio_WritePin(GPIO_A, 1, HIGH);
	// 		Gpio_WritePin(GPIO_A, 2, HIGH);
	// 		Gpio_WritePin(GPIO_A, 3, HIGH);
	// 		Gpio_WritePin(GPIO_A, 4, HIGH);
	// 		Gpio_WritePin(GPIO_A, 5, HIGH);
	// 		Gpio_WritePin(GPIO_A, 6, LOW);
	// 		break;

	// 	case 1:
	// 		Gpio_WritePin(GPIO_A, 0, LOW);
	// 		Gpio_WritePin(GPIO_A, 1, HIGH);
	// 		Gpio_WritePin(GPIO_A, 2, HIGH);
	// 		Gpio_WritePin(GPIO_A, 3, LOW);
	// 		Gpio_WritePin(GPIO_A, 4, LOW);
	// 		Gpio_WritePin(GPIO_A, 5, LOW);
	// 		Gpio_WritePin(GPIO_A, 6, LOW);
	// 		break;

	// 	case 2:
	// 		Gpio_WritePin(GPIO_A, 0, HIGH);
	// 		Gpio_WritePin(GPIO_A, 1, HIGH);
	// 		Gpio_WritePin(GPIO_A, 2, LOW);
	// 		Gpio_WritePin(GPIO_A, 3, HIGH);
	// 		Gpio_WritePin(GPIO_A, 4, HIGH);
	// 		Gpio_WritePin(GPIO_A, 5, LOW);
	// 		Gpio_WritePin(GPIO_A, 6, HIGH);
	// 		break;

	// 	case 3:
	// 		Gpio_WritePin(GPIO_A, 0, HIGH);
	// 		Gpio_WritePin(GPIO_A, 1, HIGH);
	// 		Gpio_WritePin(GPIO_A, 2, HIGH);
	// 		Gpio_WritePin(GPIO_A, 3, HIGH);
	// 		Gpio_WritePin(GPIO_A, 4, LOW);
	// 		Gpio_WritePin(GPIO_A, 5, LOW);
	// 		Gpio_WritePin(GPIO_A, 6, HIGH);
	// 		break;

	// 	case 4:
	// 		Gpio_WritePin(GPIO_A, 0, LOW);
	// 		Gpio_WritePin(GPIO_A, 1, HIGH);
	// 		Gpio_WritePin(GPIO_A, 2, HIGH);
	// 		Gpio_WritePin(GPIO_A, 3, LOW);
	// 		Gpio_WritePin(GPIO_A, 4, LOW);
	// 		Gpio_WritePin(GPIO_A, 5, HIGH);
	// 		Gpio_WritePin(GPIO_A, 6, HIGH);
	// 		break;
	// 	case 5:
	// 		Gpio_WritePin(GPIO_A, 0, HIGH);
	// 		Gpio_WritePin(GPIO_A, 1, LOW);
	// 		Gpio_WritePin(GPIO_A, 2, HIGH);
	// 		Gpio_WritePin(GPIO_A, 3, HIGH);
	// 		Gpio_WritePin(GPIO_A, 4, LOW);
	// 		Gpio_WritePin(GPIO_A, 5, HIGH);
	// 		Gpio_WritePin(GPIO_A, 6, HIGH);
	// 		break;
	// 	case 6:
	// 		Gpio_WritePin(GPIO_A, 0, HIGH);
	// 		Gpio_WritePin(GPIO_A, 1, LOW);
	// 		Gpio_WritePin(GPIO_A, 2, HIGH);
	// 		Gpio_WritePin(GPIO_A, 3, HIGH);
	// 		Gpio_WritePin(GPIO_A, 4, HIGH);
	// 		Gpio_WritePin(GPIO_A, 5, HIGH);
	// 		Gpio_WritePin(GPIO_A, 6, HIGH);
	// 		break;
	// 	case 7:
	// 		Gpio_WritePin(GPIO_A, 0, HIGH);
	// 		Gpio_WritePin(GPIO_A, 1, HIGH);
	// 		Gpio_WritePin(GPIO_A, 2, HIGH);
	// 		Gpio_WritePin(GPIO_A, 3, LOW);
	// 		Gpio_WritePin(GPIO_A, 4, LOW);
	// 		Gpio_WritePin(GPIO_A, 5, LOW);
	// 		Gpio_WritePin(GPIO_A, 6, LOW);
	// 		break;
	// 	case 8:
	// 		Gpio_WritePin(GPIO_A, 0, HIGH);
	// 		Gpio_WritePin(GPIO_A, 1, HIGH);
	// 		Gpio_WritePin(GPIO_A, 2, HIGH);
	// 		Gpio_WritePin(GPIO_A, 3, HIGH);
	// 		Gpio_WritePin(GPIO_A, 4, HIGH);
	// 		Gpio_WritePin(GPIO_A, 5, HIGH);
	// 		Gpio_WritePin(GPIO_A, 6, HIGH);
	// 		break;

	// 	case 9:
	// 		Gpio_WritePin(GPIO_A, 0, HIGH);
	// 		Gpio_WritePin(GPIO_A, 1, HIGH);
	// 		Gpio_WritePin(GPIO_A, 2, HIGH);
	// 		Gpio_WritePin(GPIO_A, 3, HIGH);
	// 		Gpio_WritePin(GPIO_A, 4, LOW);
	// 		Gpio_WritePin(GPIO_A, 5, HIGH);
	// 		Gpio_WritePin(GPIO_A, 6, HIGH);
	// 		break;
	// 	default:
	// 		break;
	// 	}

	// 	for (i = 0; i < 4000000; i++);
	// 	counter++;
	// 	if (counter == 10)
	// 	{
	// 		counter = 0;
	// 	}
	// }

	// display numbers on 7 seg
	return 0;
}
