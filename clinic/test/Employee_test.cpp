#include <gtest/gtest.h>
#include "../include/Employee.h"

class EmployeeTest : public ::testing::Test {
protected:
    Employee* employee1;
    Employee* employee2;
    Employee* employee3;

    EmployeeTest() {
        employee1 = new Employee("John", "Doe", "Middle", "uniqueSig1", "Male", 30, "USA", "Single", "ID123", 1, 5000.0);
        employee2 = new Employee("Jane", "Smith", "Middle", "uniqueSig2", "Female", 28, "UK", "Married", "ID456", 1, 6000.0);
        employee3 = new Employee("John", "Doe", "Middle", "uniqueSig1", "Male", 30, "USA", "Single", "ID123", 1, 5000.0);
    }

    ~EmployeeTest() {
        delete employee1;
        delete employee2;
        delete employee3;
    }
};

TEST_F(EmployeeTest, ConstructorTest) {
// Проверяем, что конструкторы правильно присваивают значения
ASSERT_EQ(employee1->getMonthlySalary(), 5000.0);
ASSERT_EQ(employee2->getMonthlySalary(), 6000.0);
}

TEST_F(EmployeeTest, SetMonthlySalaryTest) {
// Проверяем, что установка зарплаты работает правильно
employee1->setMonthlySalary(7000.0);
ASSERT_EQ(employee1->getMonthlySalary(), 7000.0);

employee1->setMonthlySalary(-100.0);  // Проверяем отрицательную зарплату
ASSERT_EQ(employee1->getMonthlySalary(), 0.0);  // Зарплата должна быть 0
}

TEST_F(EmployeeTest, TakeVacationTest) {
// Проверяем, что зарплата уменьшается на 10% при отпуске
double initialSalary = employee1->getMonthlySalary();
employee1->takeVacation();
ASSERT_EQ(employee1->getMonthlySalary(), initialSalary * 0.9);
}

TEST_F(EmployeeTest, ReturnFromVacationTest) {
// Проверяем, что зарплата восстанавливается после отпуска
employee1->takeVacation();
double reducedSalary = employee1->getMonthlySalary();
employee1->returnFromVacation();
ASSERT_EQ(employee1->getMonthlySalary(), reducedSalary / 0.9);
}

TEST_F(EmployeeTest, AssignmentOperatorTest) {
// Проверяем оператор присваивания
*employee2 = *employee1;
ASSERT_EQ(employee2->getMonthlySalary(), employee1->getMonthlySalary());
ASSERT_TRUE(*employee2 == *employee1);  // Проверяем оператор сравнения
}

TEST_F(EmployeeTest, EqualityOperatorTest) {
// Проверяем оператор равенства
ASSERT_TRUE(*employee1 == *employee3);  // Должны быть равны
ASSERT_FALSE(*employee1 == *employee2); // Должны быть не равны
}

TEST_F(EmployeeTest, DefaultConstructorTest) {
// Проверяем конструктор по умолчанию
Employee defaultEmployee;
ASSERT_EQ(defaultEmployee.getMonthlySalary(), 0.0);
}

