#include "led.h"
#include "keyboard.h"

void Delay(int iTimeValueMs) {
	
	int iCounter;
	int iTimeLimiter;
	iTimeLimiter = iTimeValueMs * 12000; // mnoznik 12000 dla mojego laptopa
	
	for(iCounter=0; iCounter<iTimeLimiter; iCounter++) {}
}

int main() {
	
	LedInit();
	KeyboardInit();
while(1) {
		switch(eKeyboardRead()) {
			case RELEASED:
				break;
			case BUTTON_0:
				break;
			case BUTTON_1:
				LedStepRight();
				break;
			case BUTTON_2:
				LedStepLeft();
				break;
			case BUTTON_3:
				break;
			default:
				break;
		}
		Delay(250);
	}
}
