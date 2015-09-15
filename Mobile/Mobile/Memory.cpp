#include "Memory.h"

Memory::Memory()
	: memoryCardStatus(false), RAM_GB(2), TotalSpace_GB(0), spaceUsed_GB(0)
{
}

Memory::Memory(bool cardStatus=false, int spaceOnCard = 0, int RAM=2)
	: memoryCardStatus(cardStatus), TotalSpace_GB(spaceOnCard), RAM_GB(RAM), spaceUsed_GB(0)
{
}

void Memory::ejectMemoryCard()
{
	this->memoryCardStatus = false;
	this->spaceUsed_GB = 0;
	this->TotalSpace_GB = 0;
}

void Memory::insertMemoryCard(int spaceOnCard)
{
	this->memoryCardStatus = true;
	this->TotalSpace_GB = spaceOnCard;
}

void Memory::fillSpace_GB(int dataSizeInGB){ this->spaceUsed_GB = dataSizeInGB;}

int Memory::getRAM_GB(){return this->RAM_GB;}
int Memory::getSpaceUsed_GB(){return this->spaceUsed_GB;}
int Memory::getTotalSpace_GB(){return this->TotalSpace_GB;}
bool Memory::isCardPresent(){return this->memoryCardStatus;}

