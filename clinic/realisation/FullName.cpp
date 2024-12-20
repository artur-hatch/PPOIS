#include "../include/FullName.h"

FullName::FullName() : firstName_(""), middleName_(""), familyName_("") {}

FullName::FullName(const std::string& firstName, const std::string& middleName, const std::string& familyName) {
    assignFirstName(firstName);
    assignMiddleName(middleName);
    assignFamilyName(familyName);
}

void FullName::assignFirstName(const std::string& firstName) {
    firstName_ = firstName;
}

void FullName::assignMiddleName(const std::string& middleName) {
    middleName_ = middleName;
}

void FullName::assignFamilyName(const std::string& familyName) {
    familyName_ = familyName;
}

std::string FullName::retrieveFirstName() const {
    return firstName_;
}

std::string FullName::retrieveMiddleName() const {
    return middleName_;
}

std::string FullName::retrieveFamilyName() const {
    return familyName_;
}

bool FullName::isEqualTo(const FullName& other) const {
    return (firstName_ == other.retrieveFirstName() &&
            middleName_ == other.retrieveMiddleName() &&
            familyName_ == other.retrieveFamilyName());
}

void FullName::copyFrom(const FullName& other) {
    assignFirstName(other.retrieveFirstName());
    assignMiddleName(other.retrieveMiddleName());
    assignFamilyName(other.retrieveFamilyName());
}
