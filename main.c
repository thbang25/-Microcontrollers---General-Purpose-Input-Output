/*
thabang sambo
EEE2046F/50F
Program STM32
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "stm32f0xx.h"
#define DELAY1 16 // DELAY1 used to create a delay of 22ms
#define DELAY2 65535 // DELAY2 used to create a delay of 22ms
#define TRUE 1 //check
#define FALSE 0 //check

uint32_t bitpattern1 = 0x0000; // no LEDs lit
uint32_t bitpattern2 = 0xFFFF; // all LEDs lit
uint32_t bitpattern3 = 0xAAAA; // alternating LEDS lit

typedef uint8_t flag_t;//create a new variable
flag_t startFlag = FALSE; //set condition
flag_t firstFlag = FALSE; //set condition
flag_t secondFlag = FALSE; //set condition
flag_t thirdFlag = FALSE; //set condition

void initGPIO(void);

void firstDisplay(void);

void initGPIO(void) {
    // Enable clock for GPIO ports A and C
    RCC->AHBENR |= (RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOCEN|RCC_AHBENR_GPIOBEN);



    // Configure pins 4-7 of port A as outputs for the user-controlled LEDs
        GPIOB->MODER |= (GPIO_MODER_MODER0_0 |
						 GPIO_MODER_MODER1_0 |
						 GPIO_MODER_MODER2_0 |
						 GPIO_MODER_MODER3_0 |
						 GPIO_MODER_MODER4_0 |
						 GPIO_MODER_MODER5_0 |
						 GPIO_MODER_MODER6_0 |
						 GPIO_MODER_MODER7_0 );

        GPIOA->PUPDR |=(GPIO_PUPDR_PUPDR0_0|
        		GPIO_PUPDR_PUPDR1_0|
				GPIO_PUPDR_PUPDR2_0|
				GPIO_PUPDR_PUPDR3_0);
}





void displayPattern(uint8_t pattern) {//patttern
    GPIOB->ODR |= pattern;
}

// Function to wait for a given number of milliseconds
void delay(void) {
    uint32_t i, j;
    for (i = 0; i < DELAY1; i++) {
        for (j = 0; j <DELAY2 ; j++);
    }
}

//the patterns and using a delay to display each pattern
void firstDisplay(void) {
    while (1) {
        displayPattern(bitpattern1);
        delay();
        GPIOB->ODR &=~ bitpattern2;
        displayPattern(bitpattern2);
        delay();
        GPIOB->ODR &=~ bitpattern2;
        displayPattern(bitpattern3);
        delay();
        GPIOB->ODR &=~ bitpattern2;
    }
}

//the second display use the same parameters as first
void secondDisplay(void){
	while(1){
		GPIOB->ODR |= GPIO_ODR_0;
		delay();
		GPIOB->ODR &=~ bitpattern2;
		GPIOB->ODR |= GPIO_ODR_1;
		delay();
		GPIOB->ODR &=~ bitpattern2;
		GPIOB->ODR |= GPIO_ODR_2;
		delay();
		GPIOB->ODR &=~ bitpattern2;
		GPIOB->ODR |= GPIO_ODR_3;
		delay();
		GPIOB->ODR &=~ bitpattern2;
		GPIOB->ODR |= GPIO_ODR_4;
		delay();
		GPIOB->ODR &=~ bitpattern2;
		GPIOB->ODR |= GPIO_ODR_5;
		delay();
		GPIOB->ODR &=~ bitpattern2;
		GPIOB->ODR |= GPIO_ODR_6;
		delay();
		GPIOB->ODR &=~ bitpattern2;
		GPIOB->ODR |= GPIO_ODR_7;
		delay();
		GPIOB->ODR &=~ bitpattern2;
	}
}
//bit mask counter
void thirdDisplay(void){
	while(1){
	for (int i = 0; i<255; i++){
		GPIOB->ODR |= i;
		delay();
		GPIOB->ODR &=~ bitpattern2;
	}
	}
}

void checkPB(void){
//SW0
	if (!(GPIOA->IDR & GPIO_IDR_0)){
		startFlag = TRUE;
		firstFlag = FALSE;
		secondFlag = FALSE;
		thirdFlag = FALSE;
//SW1
	}
	if (!(GPIOA->IDR & GPIO_IDR_1)){
		startFlag = TRUE;
		firstFlag = TRUE;
		secondFlag = FALSE;
		thirdFlag = FALSE;
	}
//SW2
	if (!(GPIOA->IDR & GPIO_IDR_2)){
		startFlag = TRUE;
		firstFlag = FALSE;
		secondFlag = TRUE;
		thirdFlag = FALSE;
	}
//SW3
	if (!(GPIOA->IDR & GPIO_IDR_3)){
		startFlag = TRUE;
		firstFlag = FALSE;
		secondFlag = FALSE;
		thirdFlag = TRUE;
	}



}

void display(void){

	if(startFlag & !firstFlag & !secondFlag & !thirdFlag){//CHECK0
		GPIOB->ODR |= GPIO_ODR_0;

	}
	if(startFlag & firstFlag & !secondFlag & !thirdFlag){//CHECK1
		firstDisplay();
	}
	if(startFlag & !firstFlag & secondFlag & !thirdFlag){//CHECK2
		secondDisplay();
	}
	if(startFlag & !firstFlag & !secondFlag & thirdFlag){//CHECK3
		thirdDisplay();
	}

}

int main(void) {
	initGPIO();

    //Delay();
    //firstDisplay();
	//secondDisplay();
	//thirdDisplay();


	while(1){
		checkPB();
		display();

	}

}


