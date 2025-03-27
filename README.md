#  💥 Physics Engine

This is a Physics Engine built with C++ and SFML. It’s designed to simulate basic physics like gravity, movement, and collisions.

##  💡 Features

- Simulates rigid body movement.
- Detects collisions
- Applies gravity to objects.
- Visualizes the simulation with SFML.

## SFML Setup
### MacOS
1. Install Homebrew if you don't have it yet. https://brew.sh/
2. Install SFML via Homebrew:
   ```bash
   brew install sfml
   ```
## Windows
Install SFML from: https://www.sfml-dev.org/download.php
Follow instructions to set up SFML in your IDE (CLion, Visual Studio, etc.)

## Ubuntu / Linux
```bash
   sudo apt install libsfml-dev
```

## Building the project
From the root of the project:
```bash
mkdir build
cd build
cmake ..
make
./Physics_engine
```


## Future plans
-Mouse interaction (click to spawn particles)

-Particle collision detection

-Gravity toggles

-Configurable settings via UI or config file

- [SFML 2.5+](https://www.sfml-dev.org/)
