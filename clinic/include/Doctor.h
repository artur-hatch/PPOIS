#pragma once
#include "../include/HealthProfessional.h"
#include "../include/Recipe.h"

class Doctor : public HealthProfessional {
public:
    Doctor();
    Doctor(const IdCard& idCard, int lifeStatus, double salary);
    Doctor(const std::string& name, const std::string& surname, const std::string& lastName,
           const std::string& uniqueSignature, const std::string& gender, int age,
           const std::string& country, const std::string& maritalStatus,
           const std::string& idNumber, double salary, int lifeStatus);
           
    void revivePatient(Client* patient) const;
    void performSurgery(Client* patient, HealthProfessional* assistant) const;
    void prescribeMedication(Client* patient, const std::string& medicineName,
                             const CustomDate& startDate, const CustomDate& endDate) const;
};