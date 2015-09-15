#ifndef WIRELESS_H
#define WIRELESS_H

class Wireless
{
private:
	bool statusBluetooth;
	bool statusWifi;

public:
	Wireless()
	{
		this->statusBluetooth = false;
		this->statusWifi = false;
	}

	void turnOnBluetooth(){this->statusBluetooth = true;}
	void turnOffBluetooth(){this->statusBluetooth = false;}
	void turnOnWifi(){this->statusWifi = true;}
	void turnOffWifi(){this->statusWifi = false;}

	bool isBluetoothOn(){return this->statusBluetooth;}
	bool isWifiOn(){return this->statusWifi;}
};

#endif