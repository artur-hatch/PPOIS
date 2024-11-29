#include "pch.h" 
#include "C:\Users\artur\source\repos\ убик рубика 2.0\ убик рубика 2.0\kubik.h"
#include "C:\Users\artur\source\repos\ убик рубика 2.0\ убик рубика 2.0\kubik.cpp"

//  ласс теста, который будет использовать Google Test
class CubeTest : public ::testing::Test {
protected:
    Cube cube; 

    void SetUp() override {
        cube = Cube();
    }
};

// ѕроверка начального состо€ни€ кубика (он должен быть перемешан)
TEST_F(CubeTest, TestInitialState) {
    EXPECT_FALSE(cube.is_solved());  //  убик не должен быть собран сразу после создани€
}

// ѕроверка перемешивани€ кубика
TEST_F(CubeTest, TestRandomize) {
    Cube randomized_cube = cube;
    randomized_cube.randomize();  
    EXPECT_FALSE(randomized_cube.is_solved());  //  убик не должен быть собран после перемешивани€
}

// ѕроверка вращени€ верхней стороны по часовой стрелке
TEST_F(CubeTest, TestRotateFaceClockwise) {
    Cube rotated_cube = cube;
    rotated_cube.rotate_face(0, true);  // ¬ращаем верхнюю сторону по часовой стрелке
    EXPECT_FALSE(rotated_cube.is_solved());  //  убик не должен быть собран после поворота
}

// ѕроверка вращени€ верхней стороны против часовой стрелки
TEST_F(CubeTest, TestRotateFaceCounterClockwise) {
    Cube rotated_cube = cube;
    rotated_cube.rotate_face(0, false);  
    EXPECT_FALSE(rotated_cube.is_solved());  //  убик не должен быть собран после поворота
}

// ѕроверка перемешивани€ кубика случайным образом
TEST_F(CubeTest, TestShuffle) {
    Cube shuffled_cube = cube;
    shuffled_cube.randomize();  // ѕеремешиваем кубик
    EXPECT_FALSE(shuffled_cube.is_solved());  //  убик не должен быть собран после случайного перемешивани€
}


// ѕроверка того, что кубик не соберетс€ после одного движени€
TEST_F(CubeTest, TestNotSolvedAfterOneMove) {
    Cube move_cube = cube;
    move_cube.rotate_face(0, true);  
    EXPECT_FALSE(move_cube.is_solved());  //  убик не должен быть собран после одного движени€
}

// ѕроверка того, что кубик не соберетс€ после нескольких движений
TEST_F(CubeTest, TestNotSolvedAfterMultipleMoves) {
    Cube move_cube = cube;
    move_cube.rotate_face(0, true);  
    move_cube.rotate_face(1, true);  
    EXPECT_FALSE(move_cube.is_solved());  //  убик не должен быть собран после нескольких движений
}

// ѕроверка вращени€ всех сторон
TEST_F(CubeTest, TestRotateAllFaces) {
    Cube rotated_cube = cube;
    for (int i = 0; i < 6; ++i) {
        rotated_cube.rotate_face(i, true);  
        EXPECT_FALSE(rotated_cube.is_solved());  //  убик не должен быть собран после вращени€ каждой стороны
    }
}

// ѕроверка нескольких перемешиваний
TEST_F(CubeTest, TestMultipleShuffles) {
    Cube shuffled_cube = cube;
    for (int i = 0; i < 10; ++i) {
        shuffled_cube.randomize();  
    }
    EXPECT_FALSE(shuffled_cube.is_solved());  //  убик не должен быть собран после множества перемешиваний
}

// √лавна€ функци€ дл€ запуска всех тестов
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);  // »нициализаци€ Google Test
    return RUN_ALL_TESTS();  // «апуск всех тестов
}