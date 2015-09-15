#ifndef MOBILE_H
#define MOBILE_H

#include "Camera.h"
#include "MediaPlayer.h"
#include "Wireless.h"
#include "Memory.h"

class Mobile
{
private:
	bool onStatus;
	bool silentStatus;
	int batteryStatus;
	int screenSize_inch;


public:
	Camera cam;
	MediaPlayer player;
	Wireless radio;
	Memory memoryUnit;

	Mobile();

	void turnOn();
	void turnOff();
	void silentModeOn();
	void silentModeOff();

	int batteryRemaining();
	int getScreenSize();
	bool isOn();

};

#endif