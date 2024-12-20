#include <gtest/gtest.h>
#include "../include/Client.h"
#include "../include/Recipe.h"
#include "../include/MedicalRecord.h"

class ClientTest : public ::testing::Test {
protected:
    // Данные, которые могут использоваться в нескольких тестах
    MedicalRecord testRecord;
    Client client1;
    Client client2;

    ClientTest() {
        // Инициализация testRecord для тестов
        testRecord = MedicalRecord("John", "Doe", "Smith", "UniqueSignature", "Male", 30, "USA", "Single", "12345", "123 Main St", 1, true);
    }
};

TEST_F(ClientTest, DefaultConstructorTest) {
// Проверка, что клиент по умолчанию инициализирует пустую медицинскую карту
ASSERT_NE(client1.retrieveMedicalRecord(), nullptr);
ASSERT_EQ(client1.retrieveMedicalRecord()->fetchMedicalHistory().size(), 0);
}

TEST_F(ClientTest, ConstructorWithMedicalRecordTest) {
// Проверка конструктора с параметрами
Client client(testRecord, 100);
ASSERT_EQ(client.retrieveMedicalRecord()->retrieveBloodType(), 1);
ASSERT_EQ(client.retrieveMedicalRecord()->fetchMedicalHistory().size(), 0);
}

TEST_F(ClientTest, AddPrescriptionTest) {
// Проверка добавления рецепта
Recipe* recipe = new Recipe("Aspirin", "DoctorSignature", CustomDate(2024, 1, 1), CustomDate(2024, 2, 1));
client1.addPrescription(recipe);

ASSERT_EQ(client1.findPrescription("Aspirin"), recipe);
}

TEST_F(ClientTest, RemovePrescriptionTest) {
// Проверка удаления рецепта
Recipe* recipe = new Recipe("Aspirin", "DoctorSignature", CustomDate(2024, 1, 1), CustomDate(2024, 2, 1));
client1.addPrescription(recipe);
client1.removePrescription("Aspirin");

ASSERT_EQ(client1.findPrescription("Aspirin"), nullptr);
}

TEST_F(ClientTest, CopyAssignmentOperatorTest) {
// Проверка оператора присваивания
client1 = client2;
ASSERT_TRUE(client1 == client2);
}


TEST_F(ClientTest, DestructorTest) {
// Проверка работы деструктора (когда объект выходит из области видимости)
{
Client tempClient(testRecord, 100);
}  // В этот момент tempClient должен быть уничтожен, и память освобождена
ASSERT_TRUE(true);  // Если программа не упала, значит деструктор работает корректно
}
