
#include "Mobile.h"
#include <conio.h>

int main()
{
	Mobile myCell;
	
	cout<<"camera info :"<<myCell.cam.getMegaPixels()<<","<<myCell.cam.getResolution()<<endl;
	cout<<"MediaPlayer volume :"<<myCell.player.getVolume()<<endl;
	cout<<"Memory info :"<<myCell.memoryUnit.getRAM_GB()<<endl;

	_getch();
	return 0;
}