#include "ray.hpp"
#include <SFML/Window/Mouse.hpp>
#include <angle_helper.hpp>
#include <cmath>
#include <iostream>
#include <vector_helper.hpp>

static const float CIRCLE_RADIUS = 4.f;
static const float SHAPE_LENGHT = 100.f;
static const float SHAPE_HEIGHT = 2.f;

Ray::Ray(const sf::Vector2f &start_point, float direction) {
  sf::Vector2f end_point = start_point + sf::Vector2f(SHAPE_LENGHT, 0.f);

  sf::Vector2f ray_indicator = end_point - start_point;

  // TODO: extract a function
  // float radian = direction * (M_PI / 180);
	float radian = degree_to_radian(direction);

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

  m_shape.setSize(sf::Vector2f(SHAPE_LENGHT, SHAPE_HEIGHT));
  m_shape.setPosition(start_point);
  m_shape.setRotation(direction);
}

void Ray::draw(sf::RenderWindow &window) {
  window.draw(m_shape);
  window.draw(m_start_circle);
  window.draw(m_end_circle);
  window.draw(m_intersection_circle);
}

void Ray::setSegmentEndPoint(const sf::Vector2f &end_point) {
  m_segment.setEndPoint(end_point);
}

void Ray::cast(const Segment &segment) {
  sf::Vector2f s1 = segment.getStartPoint();
  sf::Vector2f s2 = segment.getEndPoint();

  sf::Vector2f r1 = m_segment.getStartPoint();
  sf::Vector2f r2 = m_segment.getEndPoint();

  float denom = (r1.x - r2.x) * (s1.y - s2.y) - (r1.y - r2.y) * (s1.x - s2.x);

  float rt =
      ((r1.x - s1.x) * (s1.y - s2.y) - (r1.y - s1.y) * (s1.x - s2.x)) / denom;
  float st =
      ((r2.x - r1.x) * (r1.y - s1.y) - (r2.y - r1.y) * (r1.x - s1.x)) / denom;

  if (!isIntersecting(rt, st)) {
    std::cout << "Not intersecting" << std::endl;
    return;
  }
  std::cout << "Intersecting" << std::endl;

  // TODO: extract function
  float intersection_x = r1.x + rt * (r2.x - r1.x);
  float intersection_y = r1.y + rt * (r2.y - r1.y);
  m_intersection_circle.setRadius(CIRCLE_RADIUS);
  m_intersection_circle.setPosition(intersection_x, intersection_y);
  m_intersection_circle.setFillColor(sf::Color::Green);
}

bool Ray::isIntersecting(float ray_parameter, float segment_parameter) {
  return ray_parameter > 0 && segment_parameter > 0 && segment_parameter < 1;
}

void Ray::update(const sf::RenderWindow &window,
                 const std::vector<Obstacle> &obstacles) {
  sf::Vector2i localMousePosition = sf::Mouse::getPosition(window);
  setSegmentEndPoint(sf::Vector2f(localMousePosition));

  for (Obstacle obstacle : obstacles) {
    for (Segment segment : obstacle.getSegments()) {
      cast(segment);
    }
  }

  sf::Vector2f u = m_segment.getEndPoint() - m_segment.getStartPoint();
  std::cout << "u: (" << u.x << ", " << u.y << ")" << std::endl;

  sf::Vector2f v = m_segment.getStartPoint() + m_shape.getSize() - m_segment.getStartPoint();
  std::cout << "v: (" << v.x << ", " << v.y << ")" << std::endl;

  float dp = dot_product(u, v);
  std::cout << "dot product: " << dp << std::endl;

  float nu = norm(u);
  std::cout << "u norm: " << nu << std::endl;
  float nv = norm(v);
  std::cout << "v norm: " << nv << std::endl;

  double cos_theta = dp / (nu * nv);
  std::cout << "cos theta: " << cos_theta << std::endl;

  double angle = std::acos(cos_theta);
	std::cout << "angle (radian): " << angle << std::endl;
	angle = radian_to_degree(angle);
	std::cout << "angle (degree): " << angle << std::endl;

	m_shape.setRotation(angle);
}
