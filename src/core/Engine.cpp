#include "../../include/core/Engine.h"
#include "../../include/physics/Particle.h"

// Constructor: sets up the window and spawns particles
Engine::Engine() :window(sf::VideoMode(sf::Vector2u(720, 500)), "Physics Playground") {
    window.setFramerateLimit(60); // sets the frame rate
    physicsWorld.setParticlesReference(particles);
    physicsWorld.spawnParticles(100);
}

// Main loop
void Engine::run() {
    while (window.isOpen()){
        processEvents();
        update();
        render();
    }
}

// Handles window events (like closing the window)
void Engine::processEvents() {
    while (const std::optional<sf::Event> event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }
}

// Update the simulation state
void Engine::update() {
    float deltaTime = clock.restart().asSeconds();
    physicsWorld.update(deltaTime, window);
}

// Draw all particles and display the frame
void Engine::render() {
            window.clear(sf::Color(100, 100, 100));
            for (auto& particle : particles) {
                if (particle-> isActive()) {
                    particle-> draw(window);
                }
            }
            window.display();
        }