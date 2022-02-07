#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <list>

class game
{
public:
	/// <summary>
	/// Creates window
	/// </summary>
	/// <param name="width">x axis</param>
	/// <param name="height">y axis</param>
	/// <param name="window_name">window name</param>
	game(int width, int height, std::string window_name);

	/// <summary>
	/// Initializing the snake
	/// </summary>
	void init_snake();

	/// <summary>
	/// Initializing the food
	/// </summary>
	void init_food();

	/// <summary>
	/// Runs the snake game
	/// </summary>
	void run();

	/// <summary>
	/// Getting the user events
	/// </summary>
	void process_events();

	/// <summary>
	/// Handles the player input
	/// </summary>
	/// <param name="key">key code</param>
	/// <param name="isPressed">is key pressed?</param>
	void input_handler(sf::Keyboard::Key key, bool isPressed);

	/// <summary>
	/// Updates the movement for the snake
	/// </summary>
	void update();

	/// <summary>
	/// Renders our snake
	/// </summary>
	void draw_snake();

	/// <summary>
	/// Checks if the head hit the body
	/// </summary>
	void collusion_check();

	/// <summary>
	/// Checks if the snake head ate the food
	/// </summary>
	void ate_food();

	/// <summary>
	/// Renders utilities
	/// </summary>
	void render();

private:
	/*
	 * Player utilities
	 */
	std::list<sf::RectangleShape> snake;
	bool is_moving_up = false,
		 is_moving_down = false,
		 is_moving_right = false,
		 is_moving_left = false;

	// Temporarily rectangle variable
	sf::RectangleShape temp;

private:
	sf::RectangleShape food;

private:
	// Renders window
	sf::RenderWindow app;
};