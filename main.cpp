#include "game.h"

int main()
{
	// Creating our snake window
	game g_window(600, 800, "Snake");

	// Runnning the game
	g_window.run();

	return 0;
}