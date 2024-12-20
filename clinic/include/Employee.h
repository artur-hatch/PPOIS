#pragma once
#include "../include/Individual.h"

class Employee : public Individual
{
private:
    double salaryPerMonth;

public:
    Employee();
    Employee(const IdCard& idCard, int lifeStatus, double salary);
    Employee(const std::string& firstName, const std::string& lastName, const std::string& middleName,
             const std::string& uniqueSig, const std::string& gender, int age, const std::string& country,
             const std::string& maritalStatus, const std::string& idNumber, int lifeStatus, double salary);

    void setMonthlySalary(double salary);
    double getMonthlySalary() const;
    void takeVacation();
    void returnFromVacation();

    Employee& operator=(const Employee& other);
    bool operator==(const Employee& other) const;
};
