#include "main.h"
#include "keypad_4x4.h"

char val_key;
const char keys[4][4] = {{'1','2','3','A'},
                         {'4','5','6','B'},
                         {'7','8','9','C'},
                         {'*','0','#','D'}};

char Keypad_Get_Char(void)
{
	val_key = 0;

	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_SET);

	if(!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin))){
		HAL_Delay(4);
		while(!(HAL_GPIO_ReadPin (C1_GPIO_Port, C1_Pin)));
		HAL_Delay(4);
		val_key = keys[0][0];
	}
	if(!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin))){
		HAL_Delay(4);
		while(!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin)));
		HAL_Delay(4);
		val_key = keys[0][1];
	}
	if(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))){
		HAL_Delay(4);
		while(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin)));
		HAL_Delay(4);
		val_key = keys[0][2];
	}
	if (!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin))){
		HAL_Delay(4);
		while(!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin)));
		HAL_Delay(4);
		val_key = keys[0][3];
	}

	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_SET);

	if(!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin))){
		HAL_Delay(4);
		while(!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin)));
		HAL_Delay(4);
		val_key = keys[1][0];
	}
	if(!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin))){
		HAL_Delay(4);
		while(!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin)));
		HAL_Delay(4);
		val_key = keys[1][1];
	}
	if(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))){
		HAL_Delay(4);
		while(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin)));
		HAL_Delay(4);
		val_key = keys[1][2];
	}
	if(!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin))){
		HAL_Delay(4);
		while(!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin)));
		HAL_Delay(4);
		val_key = keys[1][3];
	}

	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_SET);

	if(!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin))){
		HAL_Delay(4);
		while(!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin)));
		HAL_Delay(4);
		val_key = keys[2][0];
	}
	if(!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin))){
		HAL_Delay(4);
		while(!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin)));
		HAL_Delay(4);
		val_key = keys[2][1];
	}
	if(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))){
		HAL_Delay(4);
		while(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin)));
		HAL_Delay(4);
		val_key = keys[2][2];
	}
	if(!(HAL_GPIO_ReadPin (C4_GPIO_Port, C4_Pin))){
		HAL_Delay(4);
		while(!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin)));
		HAL_Delay(4);
		val_key = keys[2][3];
	}

	HAL_GPIO_WritePin(R1_GPIO_Port, R1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R2_GPIO_Port, R2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R3_GPIO_Port, R3_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(R4_GPIO_Port, R4_Pin, GPIO_PIN_RESET);

	if(!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin))){
		HAL_Delay(4);
		while(!(HAL_GPIO_ReadPin(C1_GPIO_Port, C1_Pin)));
		HAL_Delay(4);
		val_key = keys[3][0];
	}
	if(!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin))){
		HAL_Delay(4);
		while (!(HAL_GPIO_ReadPin(C2_GPIO_Port, C2_Pin)));
		HAL_Delay(4);
		val_key = keys[3][1];
	}
	if(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin))){
		HAL_Delay(4);
		while(!(HAL_GPIO_ReadPin(C3_GPIO_Port, C3_Pin)));
		HAL_Delay(4);
		val_key = keys[3][2];
	}
	if(!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin))){
		HAL_Delay(4);
		while(!(HAL_GPIO_ReadPin(C4_GPIO_Port, C4_Pin)));
		HAL_Delay(4);
		val_key = keys[3][3];
	}
	return val_key;
}
