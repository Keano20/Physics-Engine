#include "../../include/core/Engine.h"
#include "../../include/physics/Particle.h"

Engine::Engine() :window(sf::VideoMode(sf::Vector2u(720, 500)), "Physics Playground") {
    window.setFramerateLimit(60); // sets the frame rate
    //particles.push_back(std::make_unique<Particle>(sf::Vector2f(100.f, 100.f), 1.f, 15.f)); //Spawns a single particle
    for (int i = 0; i < 10; i++) {
        sf::Vector2f particlePosition(360.f + i * 10.f, 250.f);
        particles.push_back(std::make_unique<Particle>(particlePosition, 1.5, 15));
    }
}

void Engine::run() {
    while (window.isOpen()){
        processEvents();
        update();
        render();
    }
}

void Engine::processEvents() {
    while (const std::optional<sf::Event> event = window.pollEvent()) {
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
    for (auto& particle : particles) {
        particle->applyForce(gravity.getForce());
        particle->update(deltaTime);
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