#pragma once
#include "SFML/Graphics.hpp"
namespace Car
{

struct Scene
{
	sf::RectangleShape body;
	sf::CircleShape tire[2];
	sf::ConvexShape roof;
};
void drawScene(sf::RenderWindow& win, const Scene& scene);
Scene createScene();
void displayCar();

}