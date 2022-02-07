#include "game.h"

game::game(int width, int height, std::string window_name)
{
	this->app.create(sf::VideoMode(height, width), window_name);

	// Initializating...
	init_snake();
	init_food();
}

void game::init_snake()
{
	// Setting up snake size
	this->temp.setSize(sf::Vector2f(20.f, 20.f));

	// Head of snake
	this->temp.setPosition(sf::Vector2f(60.f, 0.f));
	this->snake.push_back(temp);

	/*
	 * Setting up snake body
	 */
	this->temp.setPosition(sf::Vector2f(40.f, 0.f));
	this->snake.push_back(temp);

	this->temp.setPosition(sf::Vector2f(20.f, 0.f));
	this->snake.push_back(temp);
}

void game::init_food()
{
	// Setting up the size of the food
	this->food.setSize(sf::Vector2f(20.f, 20.f));
	
	// Assigning the food the color red
	this->food.setFillColor(sf::Color::Red);

	// Setting up the position of the food
	this->food.setPosition(sf::Vector2f(100.f, 100.f));
}

void game::run()
{
	while (this->app.isOpen())
	{
		// Sleeping the application for 100 miliseconds
		sf::sleep(sf::milliseconds(100));

		// Checks for events
		process_events();
		
		// Updates the movement
		update();

		// Check if the snake head hit the body
		collusion_check();

		// Checks if the food was eaten
		ate_food();

		// Renderer
		render();
	}
}

void game::process_events()
{
	sf::Event event;

	while (this->app.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			input_handler(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			input_handler(event.key.code, false);
			break;

		case sf::Event::Closed:
			this->app.close();
			break;

		default:
			break;
		}
	}
}

void game::input_handler(sf::Keyboard::Key key, bool isPressed)
{
	switch (key)
	{
	case sf::Keyboard::W:
		this->is_moving_up = isPressed;
		break;

	case sf::Keyboard::S:
		this->is_moving_down = isPressed;
		break;

	case sf::Keyboard::D:
		this->is_moving_right = isPressed;
		break;

	case sf::Keyboard::A:
		this->is_moving_left = isPressed;
		break;

	default:
		break;
	}
}

/// <summary>
/// Updates the movement for the snake
/// </summary>
void game::update()
{
	if (this->is_moving_up)
	{
		// If snake.y is less than 0 then...
		if (snake.front().getPosition().y < 0)
		{
			// snake.y = 580
			this->temp.setPosition({ snake.front().getPosition().x, 580 });
		}
		else
		{
			// Pushing rectangle to front
			this->temp.setPosition({ snake.front().getPosition().x, snake.front().getPosition().y - 20 });
		}

		// Clearing up snake
		this->snake.push_front(temp);
		this->snake.pop_back();
	}

	if (this->is_moving_down)
	{
		// If snake.y position is above 580 then... 
		if (snake.front().getPosition().y > 580)
		{
			// snake.y = 0
			this->temp.setPosition({ snake.front().getPosition().x, 0 });
		}
		else
		{
			// Pushing rectangle to front
			this->temp.setPosition({ snake.front().getPosition().x, snake.front().getPosition().y + 20 });
		}

		// Clearing up snake
		this->snake.push_front(temp);
		this->snake.pop_back();
	}

	if (this->is_moving_right)
	{
		// If snake.x position is above 780 then...
		if (snake.front().getPosition().x > 780)
		{
			// snake.x = 0
			this->temp.setPosition({ 0, snake.front().getPosition().y });
		}
		else
		{
			// Pushing rectangle to front
			this->temp.setPosition({ snake.front().getPosition().x + 20, snake.front().getPosition().y });
		}

		// Clearing up snake
		this->snake.push_front(temp);
		this->snake.pop_back();
	}

	if (this->is_moving_left)
	{
		// If snake.x position is less than 0 then...
		if (snake.front().getPosition().x < 0)
		{
			// snake.x position = 780.
			this->temp.setPosition({ 780, snake.front().getPosition().y });
		}
		else
		{
			// Pushing rectangle to front
			this->temp.setPosition({ snake.front().getPosition().x - 20, snake.front().getPosition().y });
		}

		// Clearing up snake
		this->snake.push_front(temp);
		this->snake.pop_back();
	}
}

void game::draw_snake()
{
	for (auto it : this->snake)
	{
		this->app.draw(it);
	}
}

void game::collusion_check()
{
	// Looping through snake elements
	for (auto i = this->snake.begin(); i != this->snake.end(); i++)
	{
		// i != snake.front()
		if (i != this->snake.begin())
		{
			/*
			 * Head hit the body then snake length is decreased.
			 * The length of the snake has to be above 3.
			 */
			if (this->snake.front().getPosition().x == i->getPosition().x && this->snake.front().getPosition().y == i->getPosition().y && this->snake.size() > 3)
			{
				this->snake.pop_front();
			}
		}
	}
}

void game::ate_food()
{
	// Snake head hit the food; snake.front() = head.
	if (this->snake.front().getGlobalBounds().intersects(this->food.getGlobalBounds()))
	{
		// Random x position
		int x_pos = (rand() % (770 / 50) * 50);
		// Random y position
		int y_pos = (rand() % (570 / 50) * 50);

		// Assigning the food new position
		this->food.setPosition(x_pos, y_pos);

		/* Increasing the length of the snake */
		this->temp.setPosition(sf::Vector2f(this->snake.back().getPosition().x + 20, this->snake.back().getPosition().y));
		this->snake.push_back(this->temp);
	}
}

void game::render()
{
	// Clearing screen
	this->app.clear();
	
	// Rendering our snake
	draw_snake();
	
	// Rendering our food
	this->app.draw(this->food);

	// Displaying
	this->app.display();
}