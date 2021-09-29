#include "ray.hpp"
#include <cmath>
#include <iostream>

static const float CIRCLE_RADIUS = 4.f;

Ray::Ray(const sf::Vector2f &start_point, float direction) {
  sf::Vector2f end_point = start_point + sf::Vector2f(100.f, 0.f);

  sf::Vector2f ray_indicator = end_point - start_point;

  // TODO: extract a function
  float radian = direction * (M_PI / 180);

  ray_indicator = sf::Vector2f(
      cos(radian) * ray_indicator.x - sin(radian) * ray_indicator.y,
      sin(radian) * ray_indicator.x + cos(radian) * ray_indicator.y);

  m_start_circle.setRadius(CIRCLE_RADIUS);
  m_start_circle.setPosition(start_point);
  m_start_circle.setFillColor(sf::Color::Red);

  m_end_circle.setRadius(CIRCLE_RADIUS);
  m_end_circle.setPosition(ray_indicator + start_point);
  m_end_circle.setFillColor(sf::Color::Blue);

  m_segment.setPoints(start_point, ray_indicator + start_point);

  m_shape.setSize(sf::Vector2f(100.f, 2.f));
  m_shape.setPosition(start_point);
  m_shape.setRotation(direction);
}

void Ray::draw(sf::RenderWindow &window) {
  window.draw(m_shape);
  window.draw(m_start_circle);
  window.draw(m_end_circle);
}

void Ray::cast(const Obstacle &obstacle) {
  // iterate over segments
  //
  // for now just test the front segment

  const std::vector<Segment> &segments = obstacle.getSegments();

  Segment s = segments.at(3);
  sf::Vector2f s1 = s.getStartPoint();
  sf::Vector2f s2 = s.getEndPoint();

  sf::Vector2f r1 = m_segment.getStartPoint();
  sf::Vector2f r2 = m_segment.getEndPoint();

	std::cout << "s1 (" << s1.x << ", " << s1.y << ")" << std::endl;
	std::cout << "s2 (" << s2.x << ", " << s2.y << ")" << std::endl;
	std::cout << "r1 (" << r1.x << ", " << r1.y << ")" << std::endl;
	std::cout << "r2 (" << r2.x << ", " << r2.y << ")" << std::endl;

  float denom = (r1.x - r2.x) * (s1.y - s2.y) - (r1.y - r2.y) * (s1.x - s2.x);

  float rt =
      ((r1.x - s1.x) * (s1.y - s2.y) - (r1.y - s1.y) * (s1.x - s2.x)) / denom;
  float st =
      ((r2.x - r1.x) * (r1.y - s1.y) - (r2.y - r1.y) * (r1.x - s1.x)) / denom;

	std::cout << "denom: " << denom << std::endl;
	std::cout << "rt: " << rt << std::endl;
	std::cout << "st: " << st << std::endl;

  if (!isIntersecting(rt, st)) {
    std::cout << "Not intersecting" << std::endl;
    return;
  }
  std::cout << "Intersecting" << std::endl;
}

bool Ray::isIntersecting(float ray_parameter, float segment_parameter) {
  return ray_parameter > 0 && segment_parameter > 0 && segment_parameter < 1;
}
