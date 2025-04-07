#ifndef PARTICLE_H
#define PARTICLE_H

#include"../../include/physics/RigidBody.h" // Include our RigidBody class for inheritence

// Class for particles that inherit physics behaviour and expire after a set duration.
class Particle : public RigidBody { //
  private:
    float lifespan; // Time in seconds before the particle becomes inactive

    public:
      // Constructs a Particle with position, mass, and lifespan
      Particle(sf::Vector2f startPosition, float mass, float lifespan);

      void update(float deltaTime); // Updates the particle’s position and lifespan
      void draw(sf::RenderWindow& window); // Draws the particle to the screem
      bool isActive() const; // Check if the particle is still active
};



#endif //PARTICLE_H
