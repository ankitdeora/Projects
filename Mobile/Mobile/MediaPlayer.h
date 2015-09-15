#ifndef MEDIAPLAYER_H
#define	MEDIAPLAYER_H

class MediaPlayer
{
private:
	bool status;
	int volume;

public:
	MediaPlayer();
	
	void turnOnPlayer();
	void turnOffPlayer();
	void setVolume(int);

	bool isOn();
	int getVolume();
};


#endif