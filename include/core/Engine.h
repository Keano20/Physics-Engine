#ifndef PHYSICS_ENGINE_ENGINE_H
#define PHYSICS_ENGINE_ENGINE_H

#include <SFML/Graphics.hpp>
#include "PhysicsWorld.h"
#include "../../include/physics/Particle.h"
#include "../physics/Gravity.h"

class Engine {
public:
    Engine();
    void run();

private:
    sf::RenderWindow window;
    std::vector<std::unique_ptr<Particle>> particles;
    sf::Clock clock;
    Gravity gravity;
    PhysicsWorld physicsWorld;

    void processEvents();
    void update();
    void render();
};

#endif //PHYSICS_ENGINE_ENGINE_H
