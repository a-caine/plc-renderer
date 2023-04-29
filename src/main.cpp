#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "filereader.h"

const int WINDOW_SIZE = 800;

int main(int argc, char* argv[]) {


    // First argument supplied to the program will be the path to a file to read
    std::string input_path = argv[1];
    std::string line;

    std::cout << input_path << std::endl;

    FileReader *fReader = new FileReader(input_path);

    // If there are no lines in the file then return an errors
    if (!fReader->readLine(&line)) {
        std::cerr << "Invalid file!" << std::endl;
        return -1;
    }

    // Otherwise read the lines into a vector of bools
    int outputWidth = line.length();
    int outputHeight = 1;

    std::vector<bool*> tiles;

    tiles.push_back((bool*)calloc(outputWidth, sizeof(bool)));

    for (int cx = 0; cx < outputWidth; cx++) {
        if(line.at(cx) == '0') {
            tiles.at(0)[cx] = false;
        } else {
            tiles.at(0)[cx] = true;
        }
    }
    

    // Create a window
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Tile Renderer", sf::Style::Titlebar | sf::Style::Close);

    

    while (fReader->readLine(&line)) {
        tiles.push_back((bool*)calloc(outputWidth, sizeof(bool)));

        for (int cx = 0; cx < outputWidth; cx++) {
            if(line.at(cx) == '0') {
                tiles.at(outputHeight)[cx] = false;
            } else {
                tiles.at(outputHeight)[cx] = true;
            }
        }

        outputHeight++;
    }

    int tileSize;

    if (outputHeight > outputWidth) {
        tileSize = WINDOW_SIZE / outputHeight;
    } else {
        tileSize = WINDOW_SIZE / outputWidth;
    }

    sf::RectangleShape tile;
    tile.setSize(sf::Vector2f(tileSize, tileSize));

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
        for (int y = 0; y < outputHeight; y++) {
            for (int x = 0; x < outputWidth; x++) {
                tile.setPosition(sf::Vector2f(x * tileSize, y * tileSize));
                if (tiles[y][x]) {
                    tile.setFillColor(sf::Color::Black);
                } else {
                    tile.setFillColor(sf::Color::White);
                }
                window.draw(tile);
            }
        }
        window.display();
    }

    delete fReader;
    
    return 0;
}