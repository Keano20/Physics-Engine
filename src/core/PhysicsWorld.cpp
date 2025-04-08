#include "../../include/core/PhysicsWorld.h"

PhysicsWorld::PhysicsWorld() {}

void PhysicsWorld::setParticlesReference(std::vector<std::unique_ptr<Particle>>& particlesRef) {
    particles = &particlesRef;
}

void PhysicsWorld::spawnParticles(int particleCount) {
    for (int i = 0; i < particleCount; i++) {
        float x = 100.f + static_cast<float>(std::rand() % 500);
        float y = 100.f + static_cast<float>(std::rand() % 300);
        sf::Vector2f particlePosition(x, y);
        particles->push_back(std::make_unique<Particle>(particlePosition, 1.5f, 15.f));
    }
}

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