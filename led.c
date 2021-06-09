#include <LPC21xx.H>
#include "led.h"

#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)


void LedInit() {

	IO1DIR = IO1DIR | LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	IO1SET = LED0_bm;
}

void LedOn(unsigned char ucLedIndeks) {
	
	IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	IO1SET = (1<<(16+ucLedIndeks));
}

enum DirectionStep{LEFT, RIGHT}; // to tutaj a nie .h bo korzystam z tego tylko tu

void LedStep(enum DirectionStep eDirStep) {
	static unsigned int uiStepChange;
	if(LEFT == eDirStep) {
		uiStepChange = (uiStepChange+1)%4;
	}
	else if(RIGHT == eDirStep) {
		uiStepChange = (uiStepChange-1)%4;
	}
	LedOn(uiStepChange);
}

void LedStepLeft() {
	LedStep(LEFT);
}

void LedStepRight() {
	LedStep(RIGHT);
}
