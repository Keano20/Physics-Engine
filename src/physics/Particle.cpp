#include "../../include/physics/Particle.h"

// Constructor: initializes position, mass, and lifespan
Particle::Particle(sf::Vector2f startPosition, float mass, float lifespan)
    : RigidBody(startPosition, mass), lifespan(lifespan) {}

// Updates the particle's physics and reduces its lifespan
void Particle::update(float deltaTime) {
  RigidBody::update(deltaTime); // Call base class update
  lifespan -= deltaTime;        // Reduce lifespan over time
}

// Renders the particle as a white circle on the window
void Particle::draw(sf::RenderWindow& window) {
  sf::CircleShape shape(7.f); // Create a small circle
  shape.setPosition(getPosition()); // Get inherited position from RigidBody
  shape.setFillColor(sf::Color::White);
  window.draw(shape);
}

// Returns true if the particle is still alive
bool Particle::isActive() const {
  return lifespan > 0;
}
