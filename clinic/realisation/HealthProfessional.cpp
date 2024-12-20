#include "../include/HealthProfessional.h"
#include <algorithm>

HealthProfessional::HealthProfessional() = default;

HealthProfessional::HealthProfessional(const IdCard& idCard, int lifeStatus, double salary)
        : Employee(idCard, lifeStatus, salary) {}

HealthProfessional::HealthProfessional(const std::string& firstName, const std::string& lastName, const std::string& middleName,
                                       const std::string& uniqueSig, const std::string& gender, int age, const std::string& country,
                                       const std::string& maritalStatus, const std::string& idNumber, int lifeStatus, double salary)
        : Employee(firstName, lastName, middleName, uniqueSig, gender, age, country, maritalStatus, idNumber, lifeStatus, salary) {}

void HealthProfessional::terminateClient(Client* patient) const {
    patient->setLifeStatus(false);
}

void HealthProfessional::provideTherapy(Client* patient) const {
    patient->setLifeStatus(static_cast<int>(patient->getLifeStatus() * 1.07));
}

void HealthProfessional::administerMedication(Client* patient) const {
    patient->setLifeStatus(static_cast<int>(patient->getLifeStatus() * 1.15));
}

void HealthProfessional::addClient(Client* patient) {
    patientList.push_back(patient);
}

void HealthProfessional::removeClient(Client* patient) {
    patientList.erase(std::remove(patientList.begin(), patientList.end(), patient), patientList.end());
}

void HealthProfessional::updateMedicalRecord(Client* patient, const std::string& note) const {
    patient->retrieveMedicalRecord()->appendMedicalHistory(note);
}
