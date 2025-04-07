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

class PhysicsWorld {
public:
    PhysicsWorld();

    void setParticlesReference(std::vector<std::unique_ptr<Particle>>& particlesRef);
    void update(float deltaTime, sf::RenderWindow& window);

private:
    std::vector<std::unique_ptr<Particle>>* particles = nullptr;
    Gravity gravity;
};


#endif //PHYSICS_ENGINE_PHYSICSWORLD_H
