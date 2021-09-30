#pragma once

#include <SFML/System/Vector2.hpp>

class Segment {
  sf::Vector2f m_start_point;
  sf::Vector2f m_end_point;

public:
  Segment();
  Segment(const sf::Vector2f &start_point, const sf::Vector2f &end_point);
  void setPoints(const sf::Vector2f &start_point,
                 const sf::Vector2f &end_point);
  void setStartPoint(const sf::Vector2f &start_point);
  void setEndPoint(const sf::Vector2f &end_point);
  const sf::Vector2f &getStartPoint() const;
  const sf::Vector2f &getEndPoint() const;
};
