#pragma once

class Cube {
public:
    Cube();  
    void print() const;  
    bool is_solved() const;  
    void rotate_face(int face_index, bool clockwise);  
    void randomize(); 

    int get_face_color(int face, int row, int col) const;  
    void set_face_color(int face, int row, int col, int color);
    
protected:
    int faces[6][3][3];  
    void shuffle();  
    void rotate_layer(int face_index, bool clockwise);  
};


