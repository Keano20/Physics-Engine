#ifndef PHYSICS_ENGINE_COLLISION_H
#define PHYSICS_ENGINE_COLLISION_H
#include <SFML/Graphics.hpp>
#include "../../include/physics/Particle.h"

// Handles collisions between particles and window borders.
class Collision {
public:
    // Resolves a collision between two particles
    static void resolveParticleCollision(Particle& particleA, Particle& ParticleB);

    // Resolves a collision between a particle and the window borders
    static void resolveBorderCollision(Particle& particle, const sf::RenderWindow& window);
};

#endif //PHYSICS_ENGINE_COLLISION_H
