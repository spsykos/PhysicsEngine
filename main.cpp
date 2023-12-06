#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <circlesolver.h>
#include <renderer.h>

using namespace std;

int main()
{
    constexpr int32_t width = 1280;
    constexpr int32_t height = 720;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 1;

    sf::RenderWindow window(sf::VideoMode(width, height), "PhysicsEngine", sf::Style::Default, settings);

    window.setFramerateLimit(60);

    CircleSolver solver;

    Renderer renderer(window);

    sf::Vector2i mousePosition;
    sf::Vector2f coords;


    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.scancode == sf::Keyboard::Scan::R) {
                    solver.Clear();
                    window.clear();
                }
            }
        }

        window.clear();

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            mousePosition = sf::Mouse::getPosition(window);
            coords.x = (float)mousePosition.x;
            coords.y = (float)mousePosition.y;
            solver.AddObject(coords);

        }
        renderer.Render(solver);
        window.display();
    }
    return 0;
}
