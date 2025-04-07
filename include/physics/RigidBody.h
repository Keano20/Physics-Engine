#ifndef PHYSICS_ENGINE_RIGIDBODY_H
#define PHYSICS_ENGINE_RIGIDBODY_H

#include <SFML/Graphics.hpp>

// Base class for objects with mass, velocity, and acceleration in the simulation.
class RigidBody {
private:
  sf::Vector2f position;     // Current position
  sf::Vector2f velocity;     // Current velocity
  sf::Vector2f acceleration; // Current acceleration
  float mass;                // Mass of the object

public:
    // Constructs a RigidBody with position and mass
    RigidBody(sf::Vector2f startPosition, float mass);

    // Applies a force to the object, modifying acceleration
    void applyForce(const sf::Vector2f& force);

    // Updates velocity and position based on acceleration
    void update(float deltaTime);

    // Getters and setters for position and velocity
    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& newPosition);

    sf::Vector2f getVelocity() const;
    void setVelocity(const sf::Vector2f& newVelocity);
};


#endif //PHYSICS_ENGINE_RIGIDBODY_H
