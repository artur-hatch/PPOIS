#include <gtest/gtest.h>
#include "../include/IDCard.h"
#include "../include/DocumentSignature.h"
#include "../include/Identity.h"
#include "../include/FullName.h"

class IdCardTest : public ::testing::Test {
protected:
    // Заготовим тестовые данные
    DocumentSignature docSign;
    Identity gender;
    FullName fullName;
    IdCard* idCard1;
    IdCard* idCard2;

    IdCardTest() {
        // Инициализируем объекты, которые будем использовать в тестах
        docSign = DocumentSignature("ID123", "John", "Middle", "Doe");
        gender = Identity("Male");
        fullName = FullName("John", "Middle", "Doe");

        // Создаем два объекта IdCard
        idCard1 = new IdCard(docSign, gender, 30, "USA", "Single", "ID123");
        idCard2 = new IdCard(docSign, gender, 30, "USA", "Single", "ID123");
    }

    ~IdCardTest() {
        delete idCard1;
        delete idCard2;
    }
};

TEST_F(IdCardTest, ConstructorTest) {
// Проверяем, что конструкторы создают объекты правильно
ASSERT_EQ(idCard1->getAge(), 30);
ASSERT_EQ(idCard1->getCountry(), "USA");
ASSERT_EQ(idCard1->getMaritalStatus(), "Single");
ASSERT_EQ(idCard1->getIdNumber(), "ID123");
ASSERT_NE(idCard1->getSignature(), nullptr);
ASSERT_NE(idCard1->getGender(), nullptr);
}

TEST_F(IdCardTest, SetNameTest) {
// Проверяем метод setName
FullName newName("Alice", "Middle", "Smith");
idCard1->setName(newName);
const FullName* retrievedName = idCard1->getName();
ASSERT_NE(retrievedName, nullptr);
ASSERT_EQ(retrievedName->retrieveFirstName(), "Alice");
ASSERT_EQ(retrievedName->retrieveMiddleName(), "Middle");
ASSERT_EQ(retrievedName->retrieveFamilyName(), "Smith");
}

TEST_F(IdCardTest, SetAgeTest) {
// Проверяем метод setAge
idCard1->setAge(45);
ASSERT_EQ(idCard1->getAge(), 45);

// Проверка ограничения возраста (максимум 130 лет)
idCard1->setAge(200);
ASSERT_EQ(idCard1->getAge(), 70);  // 200 % 130 = 70
}

TEST_F(IdCardTest, SetAndGetSignatureTest) {
// Проверяем метод setSignature и getSignature
DocumentSignature newSignature("ID456", "Jane", "Middle", "Smith");
idCard1->setSignature(newSignature);
const DocumentSignature* retrievedSignature = idCard1->getSignature();
ASSERT_NE(retrievedSignature, nullptr);
ASSERT_EQ(retrievedSignature->retrieveIdentifier(), "ID456");
}

TEST_F(IdCardTest, SetCountryTest) {
// Проверяем метод setCountry
idCard1->setCountry("Canada");
ASSERT_EQ(idCard1->getCountry(), "Canada");
}

TEST_F(IdCardTest, SetMaritalStatusTest) {
// Проверяем метод setMaritalStatus
idCard1->setMaritalStatus("Married");
ASSERT_EQ(idCard1->getMaritalStatus(), "Married");
}

TEST_F(IdCardTest, SetIdNumberTest) {
// Проверяем метод setIdNumber
idCard1->setIdNumber("ID789");
ASSERT_EQ(idCard1->getIdNumber(), "ID789");
}

TEST_F(IdCardTest, OperatorEqualityTest) {
// Проверяем оператор сравнения ==
ASSERT_TRUE(*idCard1 == *idCard2);

// Изменяем данные одного объекта и проверяем снова
idCard1->setAge(35);
ASSERT_FALSE(*idCard1 == *idCard2);  // Возраст должен отличаться
}

TEST_F(IdCardTest, OperatorAssignmentTest) {
// Проверяем оператор присваивания =
IdCard idCard3;
idCard3 = *idCard1;

// Проверяем, что присваивание корректно скопировало все данные
ASSERT_EQ(idCard3.getAge(), idCard1->getAge());
ASSERT_EQ(idCard3.getCountry(), idCard1->getCountry());
ASSERT_EQ(idCard3.getMaritalStatus(), idCard1->getMaritalStatus());
ASSERT_EQ(idCard3.getIdNumber(), idCard1->getIdNumber());
}

