#include "TestPhysicsWorld.h"
#include "../include/physics/Particle.h"
#include <SFML/Graphics.hpp>

void TestPhysicsWorld::runTestEnvironment() {
    sf::RenderWindow window(sf::VideoMode(720, 500), "TESTING ENVIRONMENT");
    sf::Clock clock;

    std::unique_ptr<Particle> particle = std::make_unique<Particle>(sf::Vector2f(100.f, 100.f), 1.f, 5.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
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