#include "../../include/collision/Collision.h"

void Collision::resolveBorderCollision(Particle& particle, const sf::RenderWindow& window) {
    sf::Vector2f position = particle.getPosition();
    sf::Vector2f velocity = particle.getVelocity();
    float radius = 7.f; // match the particle radius
    float dampingFactor = 0.8f; // Particles lose 20% of their speed per bounce/ border collision

    // Check collision with left and right window borders
    if (position.x - radius < 0.f) {
        position.x = radius; // Reposition inside the window
        velocity.x *= -dampingFactor; // Reverse and dampen horizontal velocity
    } else if (position.x + radius > window.getSize().x) {
        position.x = window.getSize().x - radius; // Reposition inside the window
        velocity.x *= -dampingFactor; // Reverse and dampen horizontal velocity
    }

    // Check collision with top and bottom window borders
    if (position.y - radius < 0.f) {
        position.y = radius; // Reposition inside the window
        velocity.y *= -dampingFactor; // Reverse and dampen vertical velocity
    } else if (position.y + radius > window.getSize().y) {
        position.y = window.getSize().y - radius; // Reposition inside the window
        velocity.y *= -dampingFactor; // Reverse and dampen vertical velocity
    }

    // Apply the updated position and velocity to the particle
    particle.setPosition(position);
    particle.setVelocity(velocity);
}

void Collision::resolveParticleCollision(Particle& particleA, Particle& particleB) {

}