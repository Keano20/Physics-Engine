#include "../../include/core/Engine.h"
#include "../../include/physics/Particle.h"

Engine::Engine() :window(sf::VideoMode(sf::Vector2u(720, 500)), "Physics Playground") {
    window.setFramerateLimit(60); // sets the frame rate
    particles.push_back(std::make_unique<Particle>(sf::Vector2f(100.f, 100.f), 1.f, 15.f));
}

void Engine::run() {
    while (window.isOpen()){
        processEvents();
        update();
        render();
    }
}

void Engine::processEvents() {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }
}

void Engine::update() {
    float deltaTime = clock.restart().asSeconds();
    for (auto& particle : particles) {
        if (particle-> isActive()) {
            particle->update(deltaTime);
        }
    }
}

void Engine::render() {
            window.clear(sf::Color(100, 100, 100));
            for (auto& particle : particles) {
                if (particle-> isActive()) {
                    particle-> draw(window);
                }
            }
            window.display();
        }