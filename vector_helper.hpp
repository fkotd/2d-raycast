#pragma once

#include <SFML/System/Vector2.hpp>
#include <cmath>

inline float dot_product(const sf::Vector2f &u, const sf::Vector2f &v) {
  return u.x * v.x + u.y * v.y;
}

inline float norm(const sf::Vector2f &v) {
  return std::sqrt(v.x * v.x + v.y * v.y);
}
