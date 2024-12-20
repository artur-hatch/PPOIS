#include <gtest/gtest.h>
#include "../include/CustomDate.h"

class CustomDateTest : public ::testing::Test {
protected:
    CustomDate date1;
    CustomDate date2;

    CustomDateTest() {
        date1 = CustomDate(15, 5, 2023);  // 15 мая 2023 года
        date2 = CustomDate(20, 8, 2024);  // 20 августа 2024 года
    }
};

TEST_F(CustomDateTest, DefaultConstructorTest) {
// Проверка конструктора по умолчанию
CustomDate defaultDate;
ASSERT_EQ(defaultDate.getYear(), 0);
ASSERT_EQ(defaultDate.getMonth(), 1);
ASSERT_EQ(defaultDate.getDay(), 1);
}

TEST_F(CustomDateTest, ParameterizedConstructorTest) {
// Проверка конструктора с параметрами
ASSERT_EQ(date1.getYear(), 2023);
ASSERT_EQ(date1.getMonth(), 5);
ASSERT_EQ(date1.getDay(), 15);

ASSERT_EQ(date2.getYear(), 2024);
ASSERT_EQ(date2.getMonth(), 8);
ASSERT_EQ(date2.getDay(), 20);
}

TEST_F(CustomDateTest, SetGetYearTest) {
// Проверка метода setYear и getYear
date1.setYear(2025);
ASSERT_EQ(date1.getYear(), 2025);

date1.setYear(-5);  // Проверка на отрицательное значение, которое должно быть проигнорировано
ASSERT_EQ(date1.getYear(), 0);
}

TEST_F(CustomDateTest, SetGetMonthTest) {
// Проверка метода setMonth и getMonth
date1.setMonth(12);
ASSERT_EQ(date1.getMonth(), 12);

date1.setMonth(13);  // Проверка на недопустимое значение месяца
ASSERT_EQ(date1.getMonth(), 1);  // Месяц должен быть 1 по умолчанию
}

TEST_F(CustomDateTest, SetGetDayTest) {
// Проверка метода setDay и getDay
date1.setDay(30);
ASSERT_EQ(date1.getDay(), 30);

date1.setDay(31);  // Проверка на недопустимое значение дня
ASSERT_EQ(date1.getDay(), 1);  // День должен быть 1 по умолчанию
}

TEST_F(CustomDateTest, ComputeDifferenceTest) {
// Проверка вычисления разницы между датами
CustomDate diff = date2.computeDifference(date1, date2);

ASSERT_EQ(diff.getYear(), 1);  // Разница в годах: 1 год
ASSERT_EQ(diff.getMonth(), 3); // Разница в месяцах: 3 месяца
ASSERT_EQ(diff.getDay(), 5);   // Разница в днях: 5 дней
}

TEST_F(CustomDateTest, EqualsTest) {
// Проверка метода equals
CustomDate date3(15, 5, 2023);
CustomDate date4(20, 8, 2024);

ASSERT_TRUE(date1.equals(date3));  // Даты одинаковые
ASSERT_FALSE(date1.equals(date2)); // Даты разные
}

TEST_F(CustomDateTest, CopyTest) {
// Проверка метода copy
CustomDate copiedDate;
copiedDate.copy(date2);

ASSERT_EQ(copiedDate.getYear(), date2.getYear());
ASSERT_EQ(copiedDate.getMonth(), date2.getMonth());
ASSERT_EQ(copiedDate.getDay(), date2.getDay());
}
