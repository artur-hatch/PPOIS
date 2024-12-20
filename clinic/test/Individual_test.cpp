#include <gtest/gtest.h>
#include "../include/Individual.h"
#include "../include/IDCard.h"  // Подключаем IdCard, так как он используется в тестах

class IndividualTest : public ::testing::Test {
protected:
    Individual* individual1;
    Individual* individual2;
    Individual* individual3;
    IdCard* idCard1;
    IdCard* idCard2;

    IndividualTest() {
        // Инициализация объектов для тестов
        idCard1 = new IdCard("John", "Doe", "", "JD123", "Male", 30, "USA", "Single", "1234567890");
        idCard2 = new IdCard("Jane", "Smith", "", "JS456", "Female", 28, "Canada", "Married", "0987654321");

        individual1 = new Individual(*idCard1, 80);  // Создание индивидуума с idCard1 и статусом жизни 80
        individual2 = new Individual(*idCard2, 75);  // Создание индивидуума с idCard2 и статусом жизни 75
        individual3 = new Individual(*idCard1, 80);  // Создание индивидуума с idCard1 и статусом жизни 80
    }

    ~IndividualTest() {
        delete individual1;
        delete individual2;
        delete individual3;
        delete idCard1;
        delete idCard2;
    }
};

TEST_F(IndividualTest, ConstructorTest) {
// Проверяем конструктор с параметрами
ASSERT_EQ(individual1->getLifeStatus(), 80);
ASSERT_EQ(individual2->getLifeStatus(), 75);
ASSERT_EQ(individual3->getLifeStatus(), 80);
ASSERT_EQ(individual1->getIdCard()->getIdNumber(), "1234567890");
}

TEST_F(IndividualTest, DefaultConstructorTest) {
// Проверяем конструктор по умолчанию
Individual individualDefault;
ASSERT_EQ(individualDefault.getLifeStatus(), 0);
ASSERT_NE(individualDefault.getIdCard(), nullptr);
}

TEST_F(IndividualTest, SetAndGetIdCardTest) {
// Проверяем методы setIdCard и getIdCard
IdCard newIdCard("Alice", "Wonderland", "", "AW987", "Female", 25, "UK", "Single", "1122334455");
individual1->setIdCard(newIdCard);
ASSERT_EQ(individual1->getIdCard()->getIdNumber(), "1122334455");
}

TEST_F(IndividualTest, SetAndGetLifeStatusTest) {
// Проверяем методы setLifeStatus и getLifeStatus
individual1->setLifeStatus(90);
ASSERT_EQ(individual1->getLifeStatus(), 90);
individual2->setLifeStatus(110);  // Превышаем максимальный статус, должен быть ограничен
ASSERT_EQ(individual2->getLifeStatus(), 100);
individual3->setLifeStatus(-10);  // Меньше минимального статуса, должен быть ограничен
ASSERT_EQ(individual3->getLifeStatus(), 0);
}

TEST_F(IndividualTest, AssignmentOperatorTest) {
// Проверяем оператор присваивания
Individual individual4;
individual4 = *individual1;
ASSERT_EQ(individual4.getLifeStatus(), individual1->getLifeStatus());
ASSERT_EQ(individual4.getIdCard()->getIdNumber(), individual1->getIdCard()->getIdNumber());
}

TEST_F(IndividualTest, EqualityOperatorTest) {
// Проверяем оператор сравнения
ASSERT_TRUE(*individual1 == *individual3);  // Должны быть равны
ASSERT_FALSE(*individual1 == *individual2);  // Должны быть не равны
}
