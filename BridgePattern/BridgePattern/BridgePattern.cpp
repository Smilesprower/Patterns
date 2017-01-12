// BridgePattern.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class DrawAPI
{
public:
	virtual void draw() = 0;
};

class DrawImpl : public DrawAPI
{
public:
	void draw()
	{
		std::cout << "Draw Impl" << std::endl;
	}
};

class Character
{
public:
	virtual void draw() = 0;
};

class Player : public Character
{
public:
	Player(DrawAPI * api)
	{
		m_api = api;
	}
	~Player()
	{
		delete m_api;
	}
	void draw()
	{
		m_api->draw();
	}
private:
	DrawAPI * m_api;
};



int main()
{
	DrawAPI * api = new DrawImpl();
	Character* character = new Player(api);
	character->draw();
	system("pause");
    return 0;
}

