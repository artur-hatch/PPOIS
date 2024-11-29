#ifndef CUBE_H
#define CUBE_H

class Cube {
public:
    Cube();  // Конструктор для инициализации кубика
    void print() const;  // Метод для печати состояния кубика
    bool is_solved() const;  // Метод для проверки собранности кубика
    void rotate_face(int face_index, bool clockwise);  // Метод для поворота стороны кубика
    void randomize();  // Метод для перемешивания кубика
private:
    int faces[6][3][3];  // Массив для хранения сторон кубика
    void shuffle();  // Метод для случайного перемешивания кубика
    void rotate_layer(int face_index, bool clockwise);  // Поворот слоя кубика
};

#endif  