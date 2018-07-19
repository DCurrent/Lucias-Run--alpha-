#include <iostream>
using namespace std;

#include "videos-master/olcConsoleGameEngine.h"

class lucias_run : public olcConsoleGameEngine
{
public:
	lucias_run()
	{
		m_sAppName = L"Lucia's Run";
	}

private:

protected:
	
	// Called by olcConsoleGameEngine
	virtual bool OnUserCreate()
	{
		return true;
	}

	// Called by olcConsoleGameEngine
	virtual bool OnUserUpdate(float fElapsedTime)
	{
		return true;
	}
};

int main()
{
	// Initialize the game object.
	lucias_run game;
	game.ConstructConsole(160, 100, 8, 8);
	game.Start();

	return 0;
}