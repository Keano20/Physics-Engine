cmake_minimum_required(VERSION 3.30)
project(Physics_engine)

set(CMAKE_CXX_STANDARD 20)

add_executable(Physics_engine
        main.cpp
        src/core/Engine.cpp
        src/core/PhysicsWorld.cpp
        src/physics/Gravity.cpp
        src/physics/RigidBody.cpp
        src/collision/Collision.cpp
        src/physics/Particle.cpp
)

# MacOS
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
include_directories(/opt/homebrew/Cellar/sfml/2.6.2/include/SFML)
target_link_libraries(Physics_engine sfml-system sfml-window sfml-graphics sfml-audio)