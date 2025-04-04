#include "../../include/physics/Gravity.h"

Gravity::Gravity(sf::Vector2f force) : gravityForce(force) {}

sf::Vector2f Gravity::getForce() const {
    return gravityForce;
}
