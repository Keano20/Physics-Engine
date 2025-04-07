#ifndef PHYSICS_ENGINE_PHYSICSWORLD_H
#define PHYSICS_ENGINE_PHYSICSWORLD_H

#pragma once

#include <vector>
#include <memory>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "../physics/Particle.h"
#include "../physics/Gravity.h"
#include "../collision/Collision.h"

// Manages core physics behavior for the simulation
class PhysicsWorld {
public:
    PhysicsWorld(); // Constructor

    // Sets a reference to the particle list managed externally
    void setParticlesReference(std::vector<std::unique_ptr<Particle>>& particlesRef);

    // Updates particle states and resolves collisions
    void update(float deltaTime, sf::RenderWindow& window);

private:
    // Pointer to particle list (does not own the particles)
    std::vector<std::unique_ptr<Particle>>* particles = nullptr;

    // Gravity force applied to all particles
    Gravity gravity;
};


#endif //PHYSICS_ENGINE_PHYSICSWORLD_H
