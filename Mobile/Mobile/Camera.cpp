#include "Camera.h"

Camera::Camera()
	:status(false),megaPixels(5),resolution(720)
{
}

Camera::Camera(int m_megaPixels,int m_resolution)
{
	this->status = false;
	this->megaPixels = m_megaPixels;
	this->resolution = m_resolution;
}

void Camera::turnOn(){this->status = true;}
void Camera::turnOff(){this->status = false;}
bool Camera::isOn(){return this->status;}
int Camera::getMegaPixels(){return this->megaPixels;}
int Camera::getResolution(){return this->resolution;}