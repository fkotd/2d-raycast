#pragma once

#include "obstacle.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

class Ray {
  Segment m_segment;
  sf::CircleShape m_start_circle;
  sf::CircleShape m_end_circle;
  sf::RectangleShape m_shape;

public:
  Ray(const sf::Vector2f &start_point, float direction);
  void draw(sf::RenderWindow &window);
  void cast(const Obstacle &obstacle);
  bool isIntersecting(float ray_paramater, float segment_parameter);
};
