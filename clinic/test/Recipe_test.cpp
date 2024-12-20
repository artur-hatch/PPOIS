#include <gtest/gtest.h>
#include "../include/Recipe.h"
#include "../include/CustomDate.h"
#include "../include/DocumentSignature.h"

// Тест на конструктор по умолчанию
TEST(RecipeTest, DefaultConstructor) {
    Recipe recipe;

    EXPECT_EQ(recipe.getMedicineName(), "");
    EXPECT_NE(recipe.getSignature(), nullptr);
    EXPECT_NE(recipe.getStartDate(), nullptr);
    EXPECT_NE(recipe.getEndDate(), nullptr);
}


// Тест на установку имени лекарства
TEST(RecipeTest, SetMedicineName) {
    Recipe recipe;
    recipe.setMedicineName("Ibuprofen");

    EXPECT_EQ(recipe.getMedicineName(), "Ibuprofen");
}


// Тест на установку дат
TEST(RecipeTest, SetDates) {
    Recipe recipe;
    CustomDate startDate(1, 2, 2024);
    CustomDate endDate(15, 2, 2024);

    recipe.setStartDate(startDate);
    recipe.setEndDate(endDate);

    ASSERT_NE(recipe.getStartDate(), nullptr);
    EXPECT_EQ(*recipe.getStartDate(), startDate);
    ASSERT_NE(recipe.getEndDate(), nullptr);
    EXPECT_EQ(*recipe.getEndDate(), endDate);
}

// Тест на оператор сравнения
TEST(RecipeTest, EqualityOperator) {
    CustomDate startDate(1, 1, 2024);
    CustomDate endDate(10, 1, 2024);
    Recipe recipe1("Paracetamol", "Dr. Smith", startDate, endDate);
    Recipe recipe2("Paracetamol", "Dr. Smith", startDate, endDate);

    EXPECT_TRUE(recipe1 == recipe2);

    Recipe recipe3("Ibuprofen", "Dr. Jones", startDate, endDate);
    EXPECT_FALSE(recipe1 == recipe3);
}

// Тест на оператор присваивания
TEST(RecipeTest, AssignmentOperator) {
    CustomDate startDate(1, 1, 2024);
    CustomDate endDate(10, 1, 2024);
    Recipe recipe1("Paracetamol", "Dr. Smith", startDate, endDate);
    Recipe recipe2;

    recipe2 = recipe1;

    EXPECT_EQ(recipe2.getMedicineName(), recipe1.getMedicineName());
    ASSERT_NE(recipe2.getSignature(), nullptr);
    EXPECT_EQ(*recipe2.getSignature(), *recipe1.getSignature());
    ASSERT_NE(recipe2.getStartDate(), nullptr);
    EXPECT_EQ(*recipe2.getStartDate(), *recipe1.getStartDate());
    ASSERT_NE(recipe2.getEndDate(), nullptr);
    EXPECT_EQ(*recipe2.getEndDate(), *recipe1.getEndDate());
}
