#include <gtest/gtest.h>
#include "../include/MedicalRecord.h"
#include "../include/IDCard.h"  // Подключаем IdCard, так как он используется в тестах

class MedicalRecordTest : public ::testing::Test {
protected:
    MedicalRecord* record1;
    MedicalRecord* record2;
    MedicalRecord* record3;
    DocumentSignature* signature1;
    Identity* gender1;

    MedicalRecordTest() {
        // Инициализация объектов для тестов
        signature1 = new DocumentSignature("JD123", "John", "Doe", "Smith");
        gender1 = new Identity("Male");

        // Создаем два объекта MedicalRecord с разными параметрами
        record1 = new MedicalRecord(*signature1, *gender1, 30, "USA", "Single", "12345", "123 Main St", 2, true);
        record2 = new MedicalRecord(*signature1, *gender1, 30, "USA", "Single", "12345", "123 Main St", 3, false);
        record3 = new MedicalRecord(*signature1, *gender1, 30, "USA", "Single", "12345", "123 Main St", 2, true);
    }

    ~MedicalRecordTest() {
        delete record1;
        delete record2;
        delete record3;
        delete signature1;
        delete gender1;
    }
};

TEST_F(MedicalRecordTest, ConstructorTest) {
// Проверка конструктора с параметрами
ASSERT_EQ(record1->retrieveBloodType(), 2);
ASSERT_EQ(record2->retrieveBloodType(), 3);
ASSERT_EQ(record1->hasPositiveRhFactor(), true);
ASSERT_EQ(record2->hasPositiveRhFactor(), false);
}

TEST_F(MedicalRecordTest, UpdateAddressTest) {
// Проверка метода обновления адреса
record1->updateAddress("456 Elm St");
ASSERT_EQ(record1->retrieveAddress(), "456 Elm St");
}

TEST_F(MedicalRecordTest, UpdateRhFactorTest) {
// Проверка метода обновления Rh-фактора
record1->updateRhFactor(false);
ASSERT_FALSE(record1->hasPositiveRhFactor());

record1->updateRhFactor(true);
ASSERT_TRUE(record1->hasPositiveRhFactor());
}

TEST_F(MedicalRecordTest, AssignmentOperatorTest) {
// Проверка оператора присваивания
MedicalRecord record4;
record4 = *record1;
ASSERT_EQ(record4.retrieveBloodType(), record1->retrieveBloodType());
ASSERT_EQ(record4.hasPositiveRhFactor(), record1->hasPositiveRhFactor());
ASSERT_EQ(record4.retrieveAddress(), record1->retrieveAddress());
}

TEST_F(MedicalRecordTest, EqualityOperatorTest) {
// Проверка оператора сравнения
ASSERT_TRUE(*record1 == *record3);  // Должны быть равны
ASSERT_FALSE(*record1 == *record2);  // Должны быть не равны
}

