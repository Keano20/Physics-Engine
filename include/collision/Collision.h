#ifndef PHYSICS_ENGINE_COLLISION_H
#define PHYSICS_ENGINE_COLLISION_H
#include <SFML/Graphics.hpp>
#include "../../include/physics/Particle.h"

class Collision {
public:
    static void resolveParticleCollision(Particle& particleA, Particle& ParticleB);
    static void resolveBorderCollision(Particle& particle, const sf::RenderWindow& window);
};


#endif //PHYSICS_ENGINE_COLLISION_H
