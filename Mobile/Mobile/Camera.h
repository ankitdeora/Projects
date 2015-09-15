#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
//#include <cstdint>
//#include <string>

using namespace std;

class Camera
{
private:
	bool status;
	int megaPixels;
	int resolution;

public:
	Camera();
	Camera(int,int);

	void turnOn();
	void turnOff();
	
	bool isOn();
	int getMegaPixels();
	int getResolution();

	void takePhoto(){};
	void recordVideo(){};
};

#endif