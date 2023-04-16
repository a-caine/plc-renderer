#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "filereader.h"

const int WINDOW_SIZE = 1000;

int main(int argc, char* argv[]) {


    // First argument supplied to the program will be the path to a file to read
    std::string input_path = argv[1];
    std::string line;

    std::cout << input_path << std::endl;

    FileReader *fReader = new FileReader(input_path);

    if (!fReader->readLine(&line)) {
        std::cerr << "Invalid file!" << std::endl;
        return -1;
    }

    // Figure out the dimensions of the grid

    // Create a window
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "PLC Renderer", sf::Style::Titlebar | sf::Style::Close);

    int gridSize = line.length();
    // Dynamically create the SFML objects

    int tileSize = WINDOW_SIZE / gridSize;

    sf::RectangleShape tiles[gridSize][gridSize];

    for (int y = 0; y < gridSize; y++) {
        for (int x = 0; x < gridSize; x++) {
            tiles[x][y].setPosition(sf::Vector2f(x * tileSize, y * tileSize));
            tiles[x][y].setSize(sf::Vector2f(tileSize, tileSize));

            if(line.at(x) == '0') {
                tiles[x][y].setFillColor(sf::Color::White);
            } else {
                tiles[x][y].setFillColor(sf::Color::Black);
            }
        }

        // If we run out of lines, exit this for loop
        if (!fReader->readLine(&line)) {
            break;
        }
    }

    

    // Handle closing the window
    while(window.isOpen()) {
        sf::Event Event;
        while(window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                window.close();
            if (Event.type == sf::Event::KeyPressed) {
                if (Event.key.code == sf::Keyboard::Escape)
                    window.close();
                if (Event.key.code == sf::Keyboard::R) {
                    
                }
            }
        }
        window.clear(sf::Color::Blue);
        for (int y = 0; y < gridSize; y++) {
            for (int x = 0; x < gridSize; x++) {
                window.draw(tiles[x][y]);
            }
        }
        window.display();
    }

    delete fReader;
    
    return 0;
}