#include "../../include/physics/Gravity.h"

// Constructor
Gravity::Gravity(sf::Vector2f force) : gravityForce(force) {}

// Returns the current gravity force
sf::Vector2f Gravity::getForce() const {
    return gravityForce;
}
