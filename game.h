#pragma once

#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
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

	void menu();

	/// <summary>
	/// Renders utilities
	/// </summary>
	void render();

private:
	// Total eaten apple's
	int score = 0;

	// Font holder
	sf::Font font;

	// Score text
	sf::Text menu_str;

	// Temporarily unique ptr
	sf::RectangleShape menu_rect;

private:
	/*
	 * Player utilities
	 */
	std::list<sf::Sprite> snake;
	sf::Texture snake_texture;

	bool is_moving_up = false,
	     is_moving_down = false,
	     is_moving_right = false,
	     is_moving_left = false;

	// Temporarily rectangle variable
	sf::Sprite temp;

private:
	sf::Sprite food;
	sf::Texture food_texture;

private:
	// Renders window
	sf::RenderWindow app;
};
