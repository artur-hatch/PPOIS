#include <gtest/gtest.h>
#include "../include/FullName.h"

class FullNameTest : public ::testing::Test {
protected:
    FullName* fullName1;
    FullName* fullName2;
    FullName* fullName3;

    FullNameTest() {
        fullName1 = new FullName("John", "Middle", "Doe");
        fullName2 = new FullName("Jane", "Middle", "Smith");
        fullName3 = new FullName("John", "Middle", "Doe");
    }

    ~FullNameTest() {
        delete fullName1;
        delete fullName2;
        delete fullName3;
    }
};

TEST_F(FullNameTest, ConstructorTest) {
// Проверяем, что конструктор правильно присваивает значения
ASSERT_EQ(fullName1->retrieveFirstName(), "John");
ASSERT_EQ(fullName1->retrieveMiddleName(), "Middle");
ASSERT_EQ(fullName1->retrieveFamilyName(), "Doe");
}

TEST_F(FullNameTest, AssignAndRetrieveTest) {
// Проверяем методы assign и retrieve
fullName1->assignFirstName("Michael");
fullName1->assignMiddleName("James");
fullName1->assignFamilyName("Smith");

ASSERT_EQ(fullName1->retrieveFirstName(), "Michael");
ASSERT_EQ(fullName1->retrieveMiddleName(), "James");
ASSERT_EQ(fullName1->retrieveFamilyName(), "Smith");
}

TEST_F(FullNameTest, IsEqualToTest) {
// Проверяем метод isEqualTo
ASSERT_TRUE(fullName1->isEqualTo(*fullName3));  // Должны быть равны
ASSERT_FALSE(fullName1->isEqualTo(*fullName2)); // Должны быть не равны
}

TEST_F(FullNameTest, CopyFromTest) {
// Проверяем метод copyFrom
fullName2->copyFrom(*fullName1);
ASSERT_EQ(fullName2->retrieveFirstName(), "John");
ASSERT_EQ(fullName2->retrieveMiddleName(), "Middle");
ASSERT_EQ(fullName2->retrieveFamilyName(), "Doe");
}

TEST_F(FullNameTest, EmptyConstructorTest) {
// Проверяем конструктор по умолчанию
FullName fullNameEmpty;
ASSERT_EQ(fullNameEmpty.retrieveFirstName(), "");
ASSERT_EQ(fullNameEmpty.retrieveMiddleName(), "");
ASSERT_EQ(fullNameEmpty.retrieveFamilyName(), "");
}

TEST_F(FullNameTest, AssignSingleNameTest) {
// Проверяем работу методов для присваивания только одного имени
fullName1->assignFirstName("Alice");
ASSERT_EQ(fullName1->retrieveFirstName(), "Alice");
ASSERT_EQ(fullName1->retrieveMiddleName(), "Middle");
ASSERT_EQ(fullName1->retrieveFamilyName(), "Doe");

fullName1->assignFamilyName("Johnson");
ASSERT_EQ(fullName1->retrieveFirstName(), "Alice");
ASSERT_EQ(fullName1->retrieveMiddleName(), "Middle");
ASSERT_EQ(fullName1->retrieveFamilyName(), "Johnson");
}

