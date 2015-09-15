#ifndef MEMORY_H
#define MEMORY_H

class Memory
{
private:
	bool memoryCardStatus;
	int TotalSpace_GB;
	int spaceUsed_GB;
	int RAM_GB;

public:
	Memory();
	Memory(bool,int,int);

	void ejectMemoryCard();
	void insertMemoryCard(int);
	void fillSpace_GB(int);

	int getRAM_GB();
	int getTotalSpace_GB();
	int getSpaceUsed_GB();
	bool isCardPresent();
};

#endif