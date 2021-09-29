#pragma once

#include "segment.hpp"
#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

class Obstacle {
  sf::ConvexShape m_shape;
  std::vector<Segment> m_segments;

public:
  Obstacle(std::vector<sf::Vector2f> &points);
  void draw(sf::RenderWindow &window);
	const std::vector<Segment>& getSegments() const;
};
