#pragma once
#include <string>

class FullName
{
private:
    std::string firstName_;
    std::string middleName_;
    std::string familyName_;

public:
    FullName();
    FullName(const std::string& firstName, const std::string& middleName, const std::string& familyName);
    
    void assignFirstName(const std::string& firstName);
    void assignMiddleName(const std::string& middleName);
    void assignFamilyName(const std::string& familyName);

    bool operator==(const FullName& other) const {
        return firstName_ == other.firstName_ &&
               middleName_ == other.middleName_ &&
               familyName_ == other.familyName_;
    }
    std::string toString() const {
        return firstName_ + " " + middleName_ + " " + familyName_;
    }
    std::string retrieveFirstName() const;
    std::string retrieveMiddleName() const;
    std::string retrieveFamilyName() const;

    bool isEqualTo(const FullName& other) const;
    void copyFrom(const FullName& other);
};
