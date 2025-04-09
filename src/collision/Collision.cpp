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

void Collision::resolveParticleCollision(Particle& firstParticle, Particle& secondParticle) {
    sf::Vector2f firstPosition = firstParticle.getPosition();
    sf::Vector2f secondPosition = secondParticle.getPosition();

    float particleRadius = 7.f;

    sf::Vector2f difference = secondPosition - firstPosition;
    float distance = std::sqrt(difference.x * difference.x + difference.y * difference.y);

    // Check for overlap
    if (distance < 2 * particleRadius && distance > 0) {
        // Simple response: just swap their velocities
        sf::Vector2f firstVelocity = firstParticle.getVelocity();
        sf::Vector2f secondVelocity = secondParticle.getVelocity();

        firstParticle.setVelocity(secondVelocity);
        secondParticle.setVelocity(firstVelocity);
    }
}
