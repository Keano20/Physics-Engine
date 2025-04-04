#ifndef PHYSICS_ENGINE_RIGIDBODY_H
#define PHYSICS_ENGINE_RIGIDBODY_H

#include <SFML/Graphics.hpp>

class RigidBody {
private:
  sf::Vector2f position;
  sf::Vector2f velocity;
  sf::Vector2f acceleration;
  float mass;

public:
    RigidBody(sf::Vector2f startPosition, float mass);

    void applyForce(const sf::Vector2f& force);
    void update(float deltaTime);

    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f& newPosition);

    sf::Vector2f getVelocity() const;
    void setVelocity(const sf::Vector2f& newVelocity);

    void draw(sf::RenderWindow& window);
};


#endif //PHYSICS_ENGINE_RIGIDBODY_H
