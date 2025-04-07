#include "../../include/core/PhysicsWorld.h"

PhysicsWorld::PhysicsWorld() {}

void PhysicsWorld::setParticlesReference(std::vector<std::unique_ptr<Particle>>& particlesRef) {
    particles = &particlesRef;
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