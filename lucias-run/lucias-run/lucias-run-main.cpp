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
		int y;					// Y index in loop.
		int x;					// X index in loop.
		int screen_height;		// Screen height.
		int screen_height_half;	// Half of screen height.
		int screen_width;		// Screen width;

		float screen_middle = 0.5f;
		float road_width = 0.6f;
		float clip_width = road_width * 0.15f;

		int grass_left;		// Grass on left side of road area.
		int grass_right;	// '' right.
		int clip_left;		// Clipping area of road.
		int clip_right;		// ''.
		int row;			// Current Y position to draw ground elements.

		// Get screen demensions.
		screen_height = ScreenHeight();
		screen_height_half = screen_height / 2;
		screen_width = ScreenWidth();

		// Fill background.
		Fill(0, 0, screen_width, screen_height, L' ', 0);

		// Interate each line on Y axis.
		for (y = 0; y < screen_height_half; y++)
		{
			// Iterate each line on X axis.
			for (x = 0; x < screen_width; x++)
			{
				road_width *= 0.5f;

				// Calculate X position of ground elements.
				grass_left	= (screen_middle - road_width - clip_width) * screen_width;
				clip_left = (screen_middle - road_width) * screen_width;
				clip_right = (screen_middle + road_width) * screen_width;
				grass_right = (screen_middle + road_width + clip_width) * screen_width;

				// Get Y location to draw elements.
				row = screen_height_half + y;

				// Draw ground elements.
				if (x >= 0 && x < grass_left)
				{
					Draw(x, row, PIXEL_SOLID, FG_GREEN);
				}

				if (x >= grass_left && x < clip_left)
				{
					Draw(x, row, PIXEL_SOLID, FG_RED);
				}

				if (x >= clip_left && x < clip_right)
				{
					Draw(x, row, PIXEL_SOLID, FG_GREY);
				}

				if (x >= clip_right && x < grass_right)
				{
					Draw(x, row, PIXEL_SOLID, FG_RED);
				}

				if (x >= grass_right && x < screen_width)
				{
					Draw(x, row, PIXEL_SOLID, FG_GREEN);
				}

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