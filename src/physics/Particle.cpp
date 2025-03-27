#include "../../include/physics/Particle.h"
#include <memory>

Particle::Particle(sf::Vector2f startPosition, float mass, float lifespan)
    : RigidBody(startPosition, mass), lifespan(lifespan) {}

void Particle::update(float deltaTime) {
  RigidBody::update(deltaTime); // Call base class update

  // Reduce lifespan over time
  lifespan -= deltaTime;
}

void Particle::draw(sf::RenderWindow& window) {
  sf::CircleShape shape(7.f); // Create a small circle
  shape.setPosition(getPosition()); // Get inherited position from RigidBody
  shape.setFillColor(sf::Color::White);
  window.draw(shape);
}

bool Particle::isActive() const {
  return lifespan > 0;
}
