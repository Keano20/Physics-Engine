#ifndef PHYSICS_ENGINE_GRAVITY_H
#define PHYSICS_ENGINE_GRAVITY_H
#include <SFML/System/Vector2.hpp>

// Provides a constant gravity force vector for use in the simulation.
class Gravity {
public:
    // Constructs a Gravity object with an optional custom force
    Gravity(sf::Vector2f force = sf::Vector2f(0.f, 200.f));

    // Returns the current gravity force vector
    sf::Vector2f getForce() const;

private:
    // The gravity force applied to particles
    sf::Vector2f gravityForce;
};


#endif //PHYSICS_ENGINE_GRAVITY_H
