#include "obstacle.hpp"

Obstacle::Obstacle(std::vector<sf::Vector2f> &points) {
  m_shape.setPointCount(points.size());

  for (size_t i = 0; i < points.size(); i++) {
    m_shape.setPoint(i, points.at(i));

    m_segments.push_back(Segment(points.at(i), points.at((i + 1) % points.size())));
  }
}

void Obstacle::draw(sf::RenderWindow &window) { window.draw(m_shape); }

const std::vector<Segment> &Obstacle::getSegments() const { return m_segments; }
