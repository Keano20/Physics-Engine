#ifndef PARTICLE_H
#define PARTICLE_H

#include"../../include/physics/RigidBody.h" // Include our RigidBody class for inheritence

class Particle : public RigidBody {
  private:
    float lifespan;

    public:
      Particle(sf::Vector2f startPosition, float mass, float lifespan);

      void update(float deltaTime); //Allow overiding of the update method
      void draw(sf::RenderWindow& window); // Draw particle to the screem
      bool isActive() const; // Check if the particle is still active
};



#endif //PARTICLE_H
