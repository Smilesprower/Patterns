// FactoryPattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

class Character
{
public:
	Character() {}
	virtual ~Character() {}
	virtual void draw() = 0;
};

class Player : public Character
{
public:
	void draw()
	{
		std::cout << "Draw Player" << std::endl;
	}
};

class Boss : public Character
{
public:
	void draw()
	{
		std::cout << "Draw Boss" << std::endl;
	}
};
class Factory
{
public:
	virtual Character* createPlayer() = 0;
	virtual Character* createOpponents() = 0;
};
class CharacterFactory : public Factory
{
public:
	Character* createPlayer()
	{
		return new Player;
	}
	Character* createOpponents()
	{
		return new Boss;
	}
};

int main()
{
	Factory * factory = new CharacterFactory;
	std::vector<Character*> characters;
	characters.push_back(factory->createPlayer());
	characters.push_back(factory->createOpponents());

	for (int i = 0; i < characters.size(); i++)
	{
		characters[i]->draw();
	}

	system("Pause");
    return 0;
}

