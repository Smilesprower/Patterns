// HandleBridgePattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


class Character
{
public:
	Character() {}
	void print()
	{
		std::cout << "Printing Character" << std::endl;
	}
};
class HandleToCharacter
{
public:
	HandleToCharacter() : character(new Character()) {}
	~HandleToCharacter()
	{
		delete character;
	}
	Character* operator->()
	{
		return character;
	}
private:
	Character * character;
};
int main()
{
	HandleToCharacter handle;
	handle->print();
	system("pause");
    return 0;
}

