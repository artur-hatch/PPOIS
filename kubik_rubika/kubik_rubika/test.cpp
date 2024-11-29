#include "pch.h" 
#include "C:\Users\artur\source\repos\����� ������ 2.0\����� ������ 2.0\kubik.h"
#include "C:\Users\artur\source\repos\����� ������ 2.0\����� ������ 2.0\kubik.cpp"

// ����� �����, ������� ����� ������������ Google Test
class CubeTest : public ::testing::Test {
protected:
    Cube cube; 

    void SetUp() override {
        cube = Cube();
    }
};

// �������� ���������� ��������� ������ (�� ������ ���� ���������)
TEST_F(CubeTest, TestInitialState) {
    EXPECT_FALSE(cube.is_solved());  // ����� �� ������ ���� ������ ����� ����� ��������
}

// �������� ������������� ������
TEST_F(CubeTest, TestRandomize) {
    Cube randomized_cube = cube;
    randomized_cube.randomize();  
    EXPECT_FALSE(randomized_cube.is_solved());  // ����� �� ������ ���� ������ ����� �������������
}

// �������� �������� ������� ������� �� ������� �������
TEST_F(CubeTest, TestRotateFaceClockwise) {
    Cube rotated_cube = cube;
    rotated_cube.rotate_face(0, true);  // ������� ������� ������� �� ������� �������
    EXPECT_FALSE(rotated_cube.is_solved());  // ����� �� ������ ���� ������ ����� ��������
}

// �������� �������� ������� ������� ������ ������� �������
TEST_F(CubeTest, TestRotateFaceCounterClockwise) {
    Cube rotated_cube = cube;
    rotated_cube.rotate_face(0, false);  
    EXPECT_FALSE(rotated_cube.is_solved());  // ����� �� ������ ���� ������ ����� ��������
}

// �������� ������������� ������ ��������� �������
TEST_F(CubeTest, TestShuffle) {
    Cube shuffled_cube = cube;
    shuffled_cube.randomize();  // ������������ �����
    EXPECT_FALSE(shuffled_cube.is_solved());  // ����� �� ������ ���� ������ ����� ���������� �������������
}


// �������� ����, ��� ����� �� ��������� ����� ������ ��������
TEST_F(CubeTest, TestNotSolvedAfterOneMove) {
    Cube move_cube = cube;
    move_cube.rotate_face(0, true);  
    EXPECT_FALSE(move_cube.is_solved());  // ����� �� ������ ���� ������ ����� ������ ��������
}

// �������� ����, ��� ����� �� ��������� ����� ���������� ��������
TEST_F(CubeTest, TestNotSolvedAfterMultipleMoves) {
    Cube move_cube = cube;
    move_cube.rotate_face(0, true);  
    move_cube.rotate_face(1, true);  
    EXPECT_FALSE(move_cube.is_solved());  // ����� �� ������ ���� ������ ����� ���������� ��������
}

// �������� �������� ���� ������
TEST_F(CubeTest, TestRotateAllFaces) {
    Cube rotated_cube = cube;
    for (int i = 0; i < 6; ++i) {
        rotated_cube.rotate_face(i, true);  
        EXPECT_FALSE(rotated_cube.is_solved());  // ����� �� ������ ���� ������ ����� �������� ������ �������
    }
}

// �������� ���������� �������������
TEST_F(CubeTest, TestMultipleShuffles) {
    Cube shuffled_cube = cube;
    for (int i = 0; i < 10; ++i) {
        shuffled_cube.randomize();  
    }
    EXPECT_FALSE(shuffled_cube.is_solved());  // ����� �� ������ ���� ������ ����� ��������� �������������
}

// ������� ������� ��� ������� ���� ������
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);  // ������������� Google Test
    return RUN_ALL_TESTS();  // ������ ���� ������
}