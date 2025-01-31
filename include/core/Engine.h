#ifndef PHYSICS_ENGINE_ENGINE_H
#define PHYSICS_ENGINE_ENGINE_H

#include <SFML/Graphics.hpp>

class Engine {
public:
    Engine();
    void run();

private:
    sf::RenderWindow window;
    void processEvents();
    void update();
    void render();
};

#endif //PHYSICS_ENGINE_ENGINE_H
