#include "obstacle.hpp"
#include "ray.hpp"
#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

  Ray ray(sf::Vector2f(200.f, 400.f), 20.f);

  std::vector<sf::Vector2f> points{sf::Vector2f(600.f, 300.f), sf::Vector2f(700.f, 300.f),
                                   sf::Vector2f(700.f, 500.f), sf::Vector2f(600.f, 500.f)};

	Obstacle obstacle(points);

	ray.cast(obstacle);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();

		obstacle.draw(window);
    ray.draw(window);

    window.display();
  }

  return 0;
}
