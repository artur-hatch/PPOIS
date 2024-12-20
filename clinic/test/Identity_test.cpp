#include <gtest/gtest.h>
#include "../include/Identity.h"

class IdentityTest : public ::testing::Test {
protected:
    Identity* identity1;
    Identity* identity2;
    Identity* identity3;

    IdentityTest() {
        // Инициализация объектов для тестов
        identity1 = new Identity("Male");
        identity2 = new Identity("Female");
        identity3 = new Identity("Male");
    }

    ~IdentityTest() {
        delete identity1;
        delete identity2;
        delete identity3;
    }
};

TEST_F(IdentityTest, ConstructorTest) {
// Проверяем, что конструктор с категорией правильно инициализирует объект
ASSERT_EQ(identity1->retrieveCategory(), "Male");
ASSERT_EQ(identity2->retrieveCategory(), "Female");
}

TEST_F(IdentityTest, DefaultConstructorTest) {
// Проверяем, что конструктор по умолчанию устанавливает категорию в "unknown"
Identity identityDefault;
ASSERT_EQ(identityDefault.retrieveCategory(), "unknown");
}

TEST_F(IdentityTest, AssignCategoryTest) {
// Проверяем метод assignCategory
identity1->assignCategory("Non-Binary");
ASSERT_EQ(identity1->retrieveCategory(), "Non-Binary");
}

TEST_F(IdentityTest, IsSameAsTest) {
// Проверяем метод isSameAs
ASSERT_TRUE(identity1->isSameAs(*identity3));  // Ожидаем, что категории "Male" одинаковы
ASSERT_FALSE(identity1->isSameAs(*identity2));  // Ожидаем, что категории "Male" и "Female" разные
}

TEST_F(IdentityTest, CopyFromTest) {
// Проверяем метод copyFrom
identity1->copyFrom(*identity2);
ASSERT_EQ(identity1->retrieveCategory(), "Female");  // Ожидаем, что identity1 скопирует категорию identity2
}

TEST_F(IdentityTest, OperatorEqualityTest) {
// Проверяем метод isSameAs через оператор сравнения
ASSERT_TRUE(identity1->isSameAs(*identity3));  // Категории одинаковы
ASSERT_FALSE(identity1->isSameAs(*identity2));  // Категории разные
}
