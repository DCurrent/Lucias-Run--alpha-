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
		int y;				// Y index in loop.
		int x;				// X index in loop.
		int screen_y_half;	// Half of screen height.
		int screen_x;

		// Get half the screen height.
		screen_y_half = ScreenHeight() / 2;

		// Get screen width.
		screen_x = ScreenWidth();

		// Interate each line on Y axis.
		for (y = 0; y < screen_y_half; y++)
		{
			// Iterate each line on X axis.
			for (x = 0; x < screen_x; x++)
			{

			}
		}

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