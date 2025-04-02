// TestPhysicsWorld.cpp
// This file provides a basic test environment for isolated physics debugging.
// Not part of the main runtime system.

#include "TestPhysicsWorld.h"
#include "../include/physics/Particle.h"
#include <SFML/Graphics.hpp>

void TestPhysicsWorld::runTestEnvironment() {
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(720, 500)), "TESTING ENVIRONMENT");
    sf::Clock clock;

    std::unique_ptr<Particle> particle = std::make_unique<Particle>(sf::Vector2f(100.f, 100.f), 1.f, 5.f);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()){
                window.close();
        }
    }

        float deltaTime = clock.restart().asSeconds();
        particle->update(deltaTime);

        window.clear();
        if (particle->isActive()) {
            particle->draw(window);
        }
        window.display();
    }
}