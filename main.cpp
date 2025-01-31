#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window (sf::VideoMode(720, 500), "Physics Playground");
    window.setFramerateLimit(10);

    // Application loop
    while (window.isOpen()) {

        // Handles window events
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Sets the window background to grey
        window.clear(sf::Color(100, 100, 100));

        // Display the content
        window.display();
    }

    return 0;
}
