#include "MediaPlayer.h"

MediaPlayer::MediaPlayer()
	:status(false),volume(50)
{
}

void MediaPlayer::turnOnPlayer(){this->status = true;}
void MediaPlayer::turnOffPlayer(){this->status = false;}
void MediaPlayer::setVolume(int volume){this->volume = volume;}

bool MediaPlayer::isOn(){return this->status;}
int MediaPlayer::getVolume(){return this->volume;}
