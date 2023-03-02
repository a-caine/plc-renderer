#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "filereader.h"

int main(int argc, char* argv[]) {


    // First argument supplied to the program will be the path to a file to read
    std::string input_path = argv[1];
    std::string line;

    FileReader *fReader = new FileReader(input_path);

    if (!fReader->readLine(&line)) {
        std::cerr << "Invalid file!" << std::endl;
        return -1;
    }

    // Figure out the dimensions of the grid

    // Dynamically create the SFML objects

    // Create a window
    sf::Window window(sf::VideoMode(800, 800), "SFML Boilerplate");

    // Handle closing the window
    while(window.isOpen()) {
        sf::Event Event;
        while(window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                window.close();
            if (Event.type == sf::Event::KeyPressed) {
                if (Event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }
        window.display();
    }

    delete fReader;
    
    return 0;
}