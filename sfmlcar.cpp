#include "sfmlcar.h"


void Car::drawScene(sf::RenderWindow& win, const Scene& scene)
{
	win.draw(scene.body);
	win.draw(scene.tire[0]);
	win.draw(scene.tire[1]);
	win.draw(scene.roof);
}

Car::Scene Car::createScene()
{
	Scene s;

	int xpos = 200;
	int ypos = 100;

	int carLength = 150;
	int carHeight = 50;

	float rP = 0.3;
	float bP = 0.5;
	float tP = 0.2;

	s.body.setSize(sf::Vector2f(carLength, bP * carHeight));
	s.body.setPosition(sf::Vector2f(xpos, ypos + rP * carHeight));

	s.tire[0].setRadius(tP / 2 * carHeight);
	s.tire[1].setRadius(tP / 2 * carHeight);

	s.tire[0].setPosition(sf::Vector2f(xpos + 0.2 * carLength, ypos + (rP + bP) * carHeight));
	s.tire[1].setPosition(sf::Vector2f(xpos + 0.7 * carLength, ypos + (rP + bP) * carHeight));

	s.roof.setPointCount(4);
	s.roof.setPoint(0, sf::Vector2f(xpos + 0.4 * carLength, ypos + rP * carHeight));
	s.roof.setPoint(1, sf::Vector2f(xpos + 0.5 * carLength, ypos));
	s.roof.setPoint(2, sf::Vector2f(xpos + carLength, ypos));
	s.roof.setPoint(3, sf::Vector2f(xpos + carLength, ypos + rP * carHeight));


	return s;
}

void Car::displayCar()
{
	sf::RenderWindow window(sf::VideoMode({ 800, 600 }), "SFML car trial");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(1);

	Scene scene = createScene();

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		window.clear();
		drawScene(window, scene);
		window.display();
	}
}