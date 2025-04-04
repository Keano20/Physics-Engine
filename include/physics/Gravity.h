#ifndef PHYSICS_ENGINE_GRAVITY_H
#define PHYSICS_ENGINE_GRAVITY_H
#include <SFML/System/Vector2.hpp>


class Gravity {
public:
    Gravity(sf::Vector2f force = sf::Vector2f(0.f, 200.f));
    sf::Vector2f getForce() const;

private:
    sf::Vector2f gravityForce;
};


#endif //PHYSICS_ENGINE_GRAVITY_H
