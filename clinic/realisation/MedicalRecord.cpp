#include "../include/MedicalRecord.h"

MedicalRecord::MedicalRecord()
        : IdCard(), bloodType_(0), hasRhFactor_(false) {}

MedicalRecord::MedicalRecord(const DocumentSignature& sig, const Identity& gen, int age, const std::string& nation,
                             const std::string& maritalStatus, const std::string& idCode, const std::string& address,
                             int bloodType, bool rhFactor)
        : IdCard(sig, gen, age, nation, maritalStatus, idCode), homeAddress_(address), bloodType_(bloodType), hasRhFactor_(rhFactor) {}

MedicalRecord::MedicalRecord(const std::string& firstName, const std::string& lastName, const std::string& middleName,
                             const std::string& uniqueId, const std::string& gender, int age, const std::string& nation,
                             const std::string& maritalStatus, const std::string& idCode, const std::string& address,
                             int bloodType, bool rhFactor)
        : IdCard(firstName, lastName, middleName, uniqueId, gender, age, nation, maritalStatus, idCode),
          homeAddress_(address), bloodType_(bloodType), hasRhFactor_(rhFactor) {}

void MedicalRecord::updateAddress(const std::string& address) {
    homeAddress_ = address;
}

void MedicalRecord::appendMedicalHistory(const std::string& record) {
    medicalHistory_.push_back(record);
}

void MedicalRecord::deleteMedicalHistory(const std::string& record) {
    medicalHistory_.remove(record);
}

void MedicalRecord::defineBloodType(int type) {
    bloodType_ = (type >= 1 && type <= 4) ? type : 0;
}

void MedicalRecord::updateRhFactor(bool rh) {
    hasRhFactor_ = rh;
}

std::string MedicalRecord::retrieveAddress() const {
    return homeAddress_;
}

std::list<std::string> MedicalRecord::fetchMedicalHistory() const {
    return medicalHistory_;
}

int MedicalRecord::retrieveBloodType() const {
    return bloodType_;
}

bool MedicalRecord::hasPositiveRhFactor() const {
    return hasRhFactor_;
}

MedicalRecord& MedicalRecord::operator=(const MedicalRecord& other) {
    if (this != &other) {
        IdCard::operator=(other);
        homeAddress_ = other.homeAddress_;
        medicalHistory_ = other.medicalHistory_;
        bloodType_ = other.bloodType_;
        hasRhFactor_ = other.hasRhFactor_;
    }
    return *this;
}

bool MedicalRecord::operator==(const MedicalRecord& other) const {
    return IdCard::operator==(other) &&
           homeAddress_ == other.homeAddress_ &&
           medicalHistory_ == other.medicalHistory_ &&
           bloodType_ == other.bloodType_ &&
           hasRhFactor_ == other.hasRhFactor_;
}