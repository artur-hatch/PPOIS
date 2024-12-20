#include "../include/Employee.h"

Employee::Employee() : salaryPerMonth(0.0) {}

Employee::Employee(const IdCard& idCard, int lifeStatus, double salary)
        : Individual(idCard, lifeStatus)
{
    setMonthlySalary(salary);
}

Employee::Employee(const std::string& firstName, const std::string& lastName, const std::string& middleName,
                   const std::string& uniqueSig, const std::string& gender, int age, const std::string& country,
                   const std::string& maritalStatus, const std::string& idNumber, int lifeStatus, double salary)
        : Individual(firstName, lastName, middleName, uniqueSig, gender, age, country, maritalStatus, idNumber, lifeStatus)
{
    setMonthlySalary(salary);
}

void Employee::setMonthlySalary(double salary) {
    salaryPerMonth = salary > 0.0 ? salary : 0.0; // Обновлённое условие для уменьшения ошибок
}

double Employee::getMonthlySalary() const {
    return salaryPerMonth;
}

void Employee::takeVacation() {
    salaryPerMonth *= 0.9; // Используется уменьшение на 10% вместо сложной формулы
}

void Employee::returnFromVacation() {
    salaryPerMonth /= 0.9; // Восстановление зарплаты после отпуска
}

Employee& Employee::operator=(const Employee& other) {
    if (this != &other) {
        Individual::operator=(other);
        setMonthlySalary(other.getMonthlySalary());
    }
    return *this;
}

bool Employee::operator==(const Employee& other) const {
    return (Individual::operator==(other)) && (salaryPerMonth == other.getMonthlySalary());
}
