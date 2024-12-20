#pragma once
#include <vector>
#include <iostream>
#include "../include/Employee.h"
#include "../include/IDCard.h"
#include "../include/Client.h"

class HealthProfessional : public Employee
{
protected:
    std::vector<Client*> patientList;

public:
    HealthProfessional();
    HealthProfessional(const IdCard& idCard, int lifeStatus, double salary);
    HealthProfessional(const std::string& firstName, const std::string& lastName, const std::string& middleName,
                       const std::string& uniqueSig, const std::string& gender, int age, const std::string& country,
                       const std::string& maritalStatus, const std::string& idNumber, int lifeStatus, double salary);

    void addClient(Client* patient);
    void removeClient(Client* patient);
    void updateMedicalRecord(Client* patient, const std::string& note) const;
    void terminateClient(Client* patient) const;
    void provideTherapy(Client* patient) const;
    void administerMedication(Client* patient) const;
};