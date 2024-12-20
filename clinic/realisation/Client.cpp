#include "../include/Client.h"
#include <algorithm>  // Add this header to use std::remove_if

Client::Client() {
    healthRecord = new MedicalRecord();
}

Client::Client(const MedicalRecord& healthRecord_, int lifeStatus) {
    healthRecord = new MedicalRecord();
    assignMedicalRecord(healthRecord_);
    setLifeStatus(lifeStatus);
}

Client::Client(const std::string& firstName, const std::string& lastName, const std::string& middleName,
               const std::string& uniqueSig, const std::string& gender, int age, const std::string& country,
               const std::string& maritalStatus, const std::string& idNumber, const std::string& address,
               int bloodGroup, bool rhFactor, int lifeStatus) {
    healthRecord = new MedicalRecord(firstName, lastName, middleName, uniqueSig, gender, age, country, maritalStatus, idNumber,
                                     address, bloodGroup, rhFactor);
    setIdCard(*healthRecord);
    setLifeStatus(lifeStatus);
}

void Client::assignMedicalRecord(const MedicalRecord& healthRecord_) {
    *healthRecord = healthRecord_;
}

MedicalRecord* Client::retrieveMedicalRecord() const {
    return healthRecord;
}

void Client::addPrescription(Recipe* recipe_) {
    prescriptions.push_back(recipe_);
}

void Client::removePrescription(const std::string& medicineName) {
    prescriptions.erase(std::remove_if(prescriptions.begin(), prescriptions.end(),
                                       [&medicineName](Recipe* recipe) { return recipe->getMedicineName() == medicineName; }), prescriptions.end());
}

Recipe* Client::findPrescription(const std::string& medicineName) {
    for (auto recipe : prescriptions) {
        if (recipe->getMedicineName() == medicineName) {
            return recipe;
        }
    }
    return nullptr;
}

Client& Client::operator=(const Client& other) {
    if (this != &other) {
        Individual::operator=(other);
        *healthRecord = *(other.retrieveMedicalRecord());
    }
    return *this;
}

bool Client::operator==(const Client& other) const {
    return (Individual::operator==(other)) && (*healthRecord == *(other.retrieveMedicalRecord()));
}