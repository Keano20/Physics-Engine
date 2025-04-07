#ifndef PHYSICS_ENGINE_ENGINE_H
#define PHYSICS_ENGINE_ENGINE_H

#include <SFML/Graphics.hpp>
#include "PhysicsWorld.h"
#include "../../include/physics/Particle.h"
#include "../physics/Gravity.h"

// Manages the main application loop, including window events,
// physics updates, and rendering.
class Engine {
public:
    Engine();   // Initializes the application window and systems
    void run(); // Starts the main simulation loop

private:
    sf::RenderWindow window; // Main application window
    std::vector<std::unique_ptr<Particle>> particles; // Collection of particles
    sf::Clock clock; // Timer used for deltaTime
    Gravity gravity; // Gravity force applied to particles
    PhysicsWorld physicsWorld; // Handles physics updates and collisions

    void processEvents(); // Handles user input and window events
    void update();        // Updates simulation state
    void render();        // Draws everything to the window
};

#endif //PHYSICS_ENGINE_ENGINE_H
