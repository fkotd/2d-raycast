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
  sf::CircleShape m_intersection_circle;

public:
  Ray(const sf::Vector2f &start_point, float direction);
  void update(const sf::RenderWindow &window,
              const std::vector<Obstacle> &obstacles);
  void draw(sf::RenderWindow &window);
  void cast(const Segment &segment);
  bool isIntersecting(float ray_paramater, float segment_parameter);
  void setSegmentEndPoint(const sf::Vector2f &end_point);
};
