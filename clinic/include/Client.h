#pragma once
#include "../include/Individual.h"
#include "../include/IDCard.h"
#include "../include/MedicalRecord.h"
#include "../include/Recipe.h"
#include <vector>

class Client : public Individual
{
protected:
    MedicalRecord* healthRecord;
    std::vector<Recipe*> prescriptions;

public:
    Client();
    Client(const MedicalRecord& healthRecord_, int lifeStatus);
    Client(const std::string& firstName, const std::string& lastName, const std::string& middleName,
           const std::string& uniqueSig, const std::string& gender, int age, const std::string& country,
           const std::string& maritalStatus, const std::string& idNumber, const std::string& address,
           int bloodGroup, bool rhFactor, int lifeStatus);
    void assignMedicalRecord(const MedicalRecord&);
    MedicalRecord* retrieveMedicalRecord() const;
    void addPrescription(Recipe*);
    void removePrescription(const std::string& medicineName);
    Recipe* findPrescription(const std::string& medicineName);

    Client& operator=(const Client& other);
    bool operator==(const Client& other) const;
};