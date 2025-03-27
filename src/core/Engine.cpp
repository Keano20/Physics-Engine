#include "../../include/core/Engine.h"
#include "../../include/physics/Particle.h"

Engine::Engine() :window(sf::VideoMode(720,500), "Physics playground") {
    window.setFramerateLimit(10);
}

void Engine::run() {
    while (window.isOpen()){
        processEvents();
        update();
        render();
    }
}

void Engine::processEvents() {
    sf::Event event{};
    while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Engine::update(){
}

void Engine::render() {
    window.clear(sf::Color(100, 100, 100));
    window.display();
}