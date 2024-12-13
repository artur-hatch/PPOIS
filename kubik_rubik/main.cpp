#include "kubik.hpp"

#include <iostream>
#include <set>

int main() {
    std::cout << "Welcome to the Rubik's Cube solver!" << std::endl;

    Cube cube;  
    cube.print(); 

    std::cout << "The cube has been shuffled. Try to solve it." << std::endl;

    while (true) {
        std::cout << "Enter a move:"<<std::endl << "Rotate the top side clockwise - U" << std::endl;
        std::cout << "Rotate bottom side clockwise - D"<<std::endl;
        std::cout << "Rotate left side clockwise - L" << std::endl;
        std::cout << "Rotate the right side clockwise - R" << std::endl;
        std::cout << "Front side rotation clockwise - F" << std::endl; 
        std::cout << "Rear side rotation clockwise - B" << std::endl;
        std::cout << "Exit - X" << std::endl;
        char move;
        std::cin >> move;

        std::set<char> valid_moves{ 'U', 'u', 'D', 'd', 'L', 'l', 'R', 'r', 'F', 'f', 'B', 'b', 'X', 'x' };

        
        if (valid_moves.find(move) == valid_moves.end()) {
            std::cout << std::endl << "Invalid move. Please enter one of the valid moves (U, D, L, R, F, B, or X)." <<std::endl << std::endl;
            continue;
        }

        
        if (move == 'X' || move == 'x') {
            std::cout << "Exiting..." << std::endl;
            break;  
        }

       
        switch (move) {
        case 'U': case 'u':
            cube.rotate_face(0, true);  
            break;
        case 'D': case 'd':
            cube.rotate_face(1, true);  
            break;
        case 'L': case 'l':
            cube.rotate_face(2, true);   
            break;
        case 'R': case 'r':
            cube.rotate_face(3, true);  
            break;
        case 'F': case 'f':
            cube.rotate_face(4, true);  
            break;
        case 'B': case 'b':
            cube.rotate_face(5, true);  
            break;
        default:
            std::cout << "Enter a move:" << std::endl << "Rotate the top side clockwise - U" << std::endl;
            std::cout << "Rotate bottom side clockwise - D" << std::endl;
            std::cout << "Rotate left side clockwise - L" << std::endl;
            std::cout << "Rotate the right side clockwise - R" << std::endl;
            std::cout << "Front side rotation clockwise - F" << std::endl;
            std::cout << "Rear side rotation clockwise - B" << std::endl;
            std::cout << "Exit - X" << std::endl;
            continue;
        }

        cube.print();  

        if (cube.is_solved()) {
            std::cout << "Congratulations! You have solved the cube!" << std::endl;
            break;
        }
    }

    return 0;
}
