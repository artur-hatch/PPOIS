#include <gtest/gtest.h>
#include "kubik.hpp"  // Подключаем основной класс Cube

// Test fixture для класса Cube, наследуем от Cube для доступа к защищенным полям
class TestCubeFixture : public ::testing::Test, public Cube {
protected:
    // Метод, который выполняется перед каждым тестом
    void SetUp() override {
        randomize();  // Инициализируем кубик (перемешиваем)
    }

    // Вспомогательный метод для захвата начального состояния куба
    void capture_initial_state(int initial_state[6][3][3]) {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    initial_state[i][j][k] = get_face_color(i, j, k);
                }
            }
        }
    }
};

// Тест на проверку корректности поворота граней куба
TEST_F(TestCubeFixture, RotateFace) {
    int initial_state[6][3][3];
    capture_initial_state(initial_state);  // Запоминаем начальное состояние

    // Поворачиваем верхнюю грань по часовой стрелке
    rotate_face(0, true);

    // Проверяем, что куб изменился
    bool changed = false;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (get_face_color(i, j, k) != initial_state[i][j][k]) {
                    changed = true;
                    break;
                }
            }
        }
    }
    ASSERT_TRUE(changed);
}

// Тест на проверку работы перемешивания
TEST_F(TestCubeFixture, Shuffle) {
    int initial_state[6][3][3];
    capture_initial_state(initial_state);  // Запоминаем начальное состояние

    // Перемешиваем кубик
    randomize();

    // Проверяем, что кубик изменился
    bool changed = false;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (get_face_color(i, j, k) != initial_state[i][j][k]) {
                    changed = true;
                    break;
                }
            }
        }
    }
    ASSERT_TRUE(changed);
}

// Тест на проверку работы метода randomize
TEST_F(TestCubeFixture, Randomize) {
    int initial_state[6][3][3];
    capture_initial_state(initial_state);  // Запоминаем начальное состояние

    // Перемешиваем куб
    randomize();

    // Проверяем, что куб изменился
    bool changed = false;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (get_face_color(i, j, k) != initial_state[i][j][k]) {
                    changed = true;
                    break;
                }
            }
        }
    }
    ASSERT_TRUE(changed);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); // Инициализация GoogleTest
    return RUN_ALL_TESTS(); // Запуск всех тестов
}
