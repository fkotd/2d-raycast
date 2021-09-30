#include "segment.hpp"

Segment::Segment() {}

Segment::Segment(const sf::Vector2f &start_point, const sf::Vector2f &end_point)
    : m_start_point(start_point), m_end_point(end_point) {}

void Segment::setPoints(const sf::Vector2f &start_point,
                        const sf::Vector2f &end_point) {
  m_start_point = start_point;
  m_end_point = end_point;
}

void Segment::setStartPoint(const sf::Vector2f &start_point) {
  m_start_point = start_point;
}

void Segment::setEndPoint(const sf::Vector2f &end_point) {
  m_end_point = end_point;
}

const sf::Vector2f &Segment::getStartPoint() const { return m_start_point; }

const sf::Vector2f &Segment::getEndPoint() const { return m_end_point; }
