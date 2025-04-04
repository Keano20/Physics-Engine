cmake_minimum_required(VERSION 3.30)
project(Physics_engine)

set(CMAKE_CXX_STANDARD 20)

add_executable(Physics_engine
        main.cpp
        tests/TestPhysicsWorld.cpp
        src/core/Engine.cpp
        src/core/PhysicsWorld.cpp
        src/physics/Gravity.cpp
        src/physics/RigidBody.cpp
        src/physics/Particle.cpp
        src/collision/Collision.cpp
)

if(APPLE)
    # macOS specific settings
    # NOTE: The SFML path below may vary depending on how SFML was installed
    set(SFML_DIR "/opt/homebrew/Cellar/sfml/lib/cmake/SFML")
    include_directories("/opt/homebrew/Cellar/sfml/include/SFML")
elseif(WIN32)
    # Windows specific settings
    # Update the file paths based on where SFML is installed on your Windows system
    set(SFML_DIR "C:/SFML/lib/cmake/SFML")
    include_directories("C:/SFML/include")
endif()

find_package(SFML 3 REQUIRED COMPONENTS System Window Graphics Audio)

target_link_libraries(Physics_engine
        SFML::System
        SFML::Window
        SFML::Graphics
        SFML::Audio
)