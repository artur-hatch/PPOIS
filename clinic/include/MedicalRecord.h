#pragma once
#include "../include/IDCard.h"
#include <list>
#include <memory>
#include <string>

class MedicalRecord : public IdCard {
private:
    std::string homeAddress_;
    std::list<std::string> medicalHistory_;
    int bloodType_;
    bool hasRhFactor_;

public:
    MedicalRecord();
    MedicalRecord(const DocumentSignature& sig, const Identity& gen, int age, const std::string& nation,
                  const std::string& maritalStatus, const std::string& idCode, const std::string& address,
                  int bloodType, bool rhFactor);
    MedicalRecord(const std::string& firstName, const std::string& lastName, const std::string& middleName,
                  const std::string& uniqueId, const std::string& gender, int age, const std::string& nation,
                  const std::string& maritalStatus, const std::string& idCode, const std::string& address,
                  int bloodType, bool rhFactor);

    void updateAddress(const std::string& address);
    void appendMedicalHistory(const std::string& record);
    void deleteMedicalHistory(const std::string& record);
    void defineBloodType(int type);
    void updateRhFactor(bool rh);

    std::string retrieveAddress() const;
    std::list<std::string> fetchMedicalHistory() const;
    int retrieveBloodType() const;
    bool hasPositiveRhFactor() const;

    MedicalRecord& operator=(const MedicalRecord& other);
    bool operator==(const MedicalRecord& other) const;
};