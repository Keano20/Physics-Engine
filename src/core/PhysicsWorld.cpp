#include "../../include/core/PhysicsWorld.h"

// Constructor
PhysicsWorld::PhysicsWorld() {}

// Sets a reference to the external particle list managed by Engine
void PhysicsWorld::setParticlesReference(std::vector<std::unique_ptr<Particle>>& particlesRef) {
    particles = &particlesRef;
}

// Spawns a specified number of particles at random positions
void PhysicsWorld::spawnParticles(int particleCount) {
    for (int i = 0; i < particleCount; i++) {
        float x = 100.f + static_cast<float>(std::rand() % 500);
        float y = 100.f + static_cast<float>(std::rand() % 300);
        sf::Vector2f particlePosition(x, y);
        particles->push_back(std::make_unique<Particle>(particlePosition, 1.5f, 15.f));
    }
}

// Updates all particles: applies gravity, updates position, handles border collision
void PhysicsWorld::update(float deltaTime, sf::RenderWindow& window) {
    if (!particles) return;

    for (auto& particle : *particles) {
        if (particle->isActive()) {
            particle->applyForce(gravity.getForce());
            particle->update(deltaTime);
            Collision::resolveBorderCollision(*particle, window);
        }
    }
}