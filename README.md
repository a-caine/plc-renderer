# plc-renderer
Renders the tile input and output from COMP2212 (Programming Language Concepts)

## Example:

![image](https://user-images.githubusercontent.com/66918276/235313544-cb875d59-2232-42a3-af69-8e27224e0df5.png)

## Usage:

From the root directory of the project, make a new directory to store the cmake files (e.g. build)

Enter the newly created directory and make the cmake files:
```cmake ..```

Then build the project with cmake:
```cmake --build .```

Once you have built the program, run it with the tile output file as a command line argument:
```./PCLRenderer /path/to/file```

## Dependencies
This project requires SFML to work, you can find instructions on how to install SFML ![here](https://github.com/SFML/SFML).
