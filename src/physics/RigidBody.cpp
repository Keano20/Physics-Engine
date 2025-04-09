#include "../../include/physics/RigidBody.h"

// Constructor: sets initial position and mass, and zeroes velocity/acceleration
RigidBody::RigidBody(sf::Vector2f startPosition, float mass)
    : position(startPosition), velocity(0.f, 0.f), acceleration(0.f, 0.f), mass(mass) {}

// Applies a force to the object (adds to acceleration)
void RigidBody::applyForce(const sf::Vector2f& force) {
  acceleration += force / mass;
}

// Updates velocity and position using acceleration and delta time
void RigidBody::update(float deltaTime) {
  velocity += acceleration * deltaTime;
  position += velocity * deltaTime;
  acceleration = {0.f, 0.f};
}

// Returns the current position
sf::Vector2f RigidBody::getPosition() const {
  return position;
}

// Sets a new position
void RigidBody::setPosition(const sf::Vector2f& newPosition){
  position = newPosition;
}

// Returns the current velocity
sf::Vector2f RigidBody::getVelocity() const {
  return velocity;
}

// Sets a new velocity
void RigidBody::setVelocity(const sf::Vector2f& newVelocity) {
  velocity = newVelocity;
}