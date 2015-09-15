#include "Mobile.h"

Mobile::Mobile()
	:onStatus(false), silentStatus(false), batteryStatus(100), screenSize_inch(5)
{
}

void Mobile::turnOn(){this->onStatus = true;}
void Mobile::turnOff(){this->onStatus = false;}
void Mobile::silentModeOn(){this->silentStatus = true;}
void Mobile::silentModeOff(){this->silentStatus = false;}

int Mobile::batteryRemaining(){return this->batteryStatus;}
int Mobile::getScreenSize(){return this->screenSize_inch;}
bool Mobile::isOn(){return this->onStatus;}