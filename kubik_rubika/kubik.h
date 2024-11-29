#ifndef CUBE_H
#define CUBE_H

class Cube {
public:
    Cube();  // ����������� ��� ������������� ������
    void print() const;  // ����� ��� ������ ��������� ������
    bool is_solved() const;  // ����� ��� �������� ����������� ������
    void rotate_face(int face_index, bool clockwise);  // ����� ��� �������� ������� ������
    void randomize();  // ����� ��� ������������� ������
private:
    int faces[6][3][3];  // ������ ��� �������� ������ ������
    void shuffle();  // ����� ��� ���������� ������������� ������
    void rotate_layer(int face_index, bool clockwise);  // ������� ���� ������
};

#endif  