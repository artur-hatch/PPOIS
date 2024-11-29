#include "kubik.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Конструктор для инициализации кубика
Cube::Cube() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                faces[i][j][k] = i;  // Цвет стороны зависит от индекса (0 - белая, 1 - зеленая, и т.д.)
            }
        }
    }
    randomize();
}

// Метод для печати состояния кубика
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

// Метод для проверки собранности кубика
bool Cube::is_solved() const {
    for (int i = 0; i < 6; ++i) {
        int color = faces[i][0][0];  // Цвет верхнего левого элемента
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                if (faces[i][j][k] != color)  // Если хотя бы один элемент не соответствует, кубик не собран
                    return false;
    }
    return true;
}

// Метод для поворота стороны кубика
void Cube::rotate_face(int face_index, bool clockwise) {
    // Вращаем саму сторону кубика
    int temp[3][3];  // Временный массив для хранения текущего состояния стороны

    // Копируем элементы в временный массив
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            temp[i][j] = faces[face_index][i][j];

    // Крутим сторону по часовой стрелке
    if (clockwise) {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                faces[face_index][i][j] = temp[2 - j][i];
    }
    else {  // Крутим против часовой стрелки
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                faces[face_index][i][j] = temp[j][2 - i];
    }

    // Поворот смежных слоев
    rotate_layer(face_index, clockwise);
}

// Поворот слоя кубика
void Cube::rotate_layer(int face_index, bool clockwise) {
    int temp[3];
    if (clockwise) {
        // Перемещение верхних/нижних/боковых слоев в зависимости от вращаемой стороны
        for (int i = 0; i < 3; ++i) {
            temp[i] = faces[(face_index + 1) % 6][0][i];
            faces[(face_index + 1) % 6][0][i] = faces[(face_index + 3) % 6][2][i];
            faces[(face_index + 3) % 6][2][i] = faces[(face_index + 4) % 6][2][i];
            faces[(face_index + 4) % 6][2][i] = faces[(face_index + 2) % 6][0][i];
            faces[(face_index + 2) % 6][0][i] = temp[i];
        }
    }
    else {
        // Против часовой стрелки (аналогично, но с другой последовательностью)
        for (int i = 0; i < 3; ++i) {
            temp[i] = faces[(face_index + 1) % 6][0][i];
            faces[(face_index + 1) % 6][0][i] = faces[(face_index + 2) % 6][0][i];
            faces[(face_index + 2) % 6][0][i] = faces[(face_index + 3) % 6][2][i];
            faces[(face_index + 3) % 6][2][i] = faces[(face_index + 4) % 6][2][i];
            faces[(face_index + 4) % 6][2][i] = temp[i];
        }
    }
}

// Метод для случайного перемешивания кубика
void Cube::shuffle() {
    for (int i = 0; i < 1000; ++i) {
        int face = rand() % 6;  // Случайная сторона
        bool clockwise = rand() % 2;  // Случайное направление поворота
        rotate_face(face, clockwise);  // Поворачиваем выбранную сторону
    }
}

// Метод для перемешивания кубика
void Cube::randomize() {
    srand(time(0));  // Инициализация генератора случайных чисел
    shuffle();  // Перемешиваем кубик
}
