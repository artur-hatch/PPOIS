#include <iostream>
#include <set>
#include <limits>
#include "kubik.hpp"
#include <cstdlib>
#include <ctime>

Cube::Cube() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                faces[i][j][k] = i;  
            }
        }
    }
    
    randomize();
}


void Cube::print() const {
    static const std::string colors[] = { "W", "G", "R", "B", "O", "Y" };

    std::cout << "Cube state:\n";
    for (int i = 0; i < 6; ++i) {
        std::cout << colors[i] << " face:\n";
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                std::cout << colors[faces[i][j][k]] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}

bool Cube::is_solved() const {
    for (int i = 0; i < 6; ++i) {
        int color = faces[i][0][0];  
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                if (faces[i][j][k] != color)  
                    return false;
    }
    return true;
}


void Cube::rotate_face(int face_index, bool clockwise) {
    int temp[3][3];  
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            temp[i][j] = faces[face_index][i][j];

    
    if (clockwise) {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                faces[face_index][i][j] = temp[2 - j][i];
    }
    else {  
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                faces[face_index][i][j] = temp[j][2 - i];
    }

    
    rotate_layer(face_index, clockwise);
}


void Cube::rotate_layer(int face_index, bool clockwise) {
    int temp[3];
    if (clockwise) {
        
        for (int i = 0; i < 3; ++i) {
            temp[i] = faces[(face_index + 1) % 6][0][i];
            faces[(face_index + 1) % 6][0][i] = faces[(face_index + 3) % 6][2][i];
            faces[(face_index + 3) % 6][2][i] = faces[(face_index + 4) % 6][2][i];
            faces[(face_index + 4) % 6][2][i] = faces[(face_index + 2) % 6][0][i];
            faces[(face_index + 2) % 6][0][i] = temp[i];
        }
    }
    else {
        
        for (int i = 0; i < 3; ++i) {
            temp[i] = faces[(face_index + 1) % 6][0][i];
            faces[(face_index + 1) % 6][0][i] = faces[(face_index + 2) % 6][0][i];
            faces[(face_index + 2) % 6][0][i] = faces[(face_index + 3) % 6][2][i];
            faces[(face_index + 3) % 6][2][i] = faces[(face_index + 4) % 6][2][i];
            faces[(face_index + 4) % 6][2][i] = temp[i];
        }
    }
}


void Cube::shuffle() {
    for (int i = 0; i < 1000; ++i) {
        int face = rand() % 6;  
        bool clockwise = rand() % 2;  
        rotate_face(face, clockwise); 
    }
}


void Cube::randomize() {
    srand(time(0));  
    shuffle();  
}

int Cube::get_face_color(int face, int row, int col) const
{
    return faces[face][row][col];
}

void Cube::set_face_color(int face, int row, int col, int color)
{
    faces[face][row][col] = color;
}
