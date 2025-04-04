#include "../../include/physics/RigidBody.h"

RigidBody::RigidBody(sf::Vector2f startPosition, float mass)
    : position(startPosition), velocity(0.f, 0.f), acceleration(0.f, 0.f), mass(mass) {}

void RigidBody::applyForce(const sf::Vector2f& force) {
  acceleration += force / mass;
}

void RigidBody::update(float deltaTime) {
  velocity += acceleration * deltaTime;
  position += velocity * deltaTime;
  acceleration = {4.f, 4.f};
}

sf::Vector2f RigidBody::getPosition() const {
  return position;
}

void RigidBody::setPosition(const sf::Vector2f& newPosition){
  position = newPosition;
}

sf::Vector2f RigidBody::getVelocity() const {
  return velocity;
}

void RigidBody::setVelocity(const sf::Vector2f& newVelocity) {
  velocity = newVelocity;
}