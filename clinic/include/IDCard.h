#pragma once
#include "../include/Identity.h"
#include "../include/FullName.h"
#include "../include/DocumentSignature.h"
#include <memory>
#include <string>

class IdCard {
protected:
    std::unique_ptr<DocumentSignature> signature_;
    std::unique_ptr<Identity> gender_;
    int age_;
    std::string country_;
    std::string maritalStatus_;
    std::string idNumber_;

public:
    IdCard();
    IdCard(const DocumentSignature& sign, const Identity& genderType, int personAge, const std::string& residence, const std::string& status, const std::string& id);
    IdCard(const std::string& firstName, const std::string& middleName, const std::string& familyName,
           const std::string& uniqueSign, const std::string& genderType, int personAge, const std::string& residence,
           const std::string& status, const std::string& id);

    void setName(const FullName& fullName);
    void setSignature(const DocumentSignature& sign);
    void setGender(const Identity& genderType);
    void setAge(int personAge);
    void setCountry(const std::string& residence);
    void setMaritalStatus(const std::string& status);
    void setIdNumber(const std::string& id);

    const FullName* getName() const;
    const DocumentSignature* getSignature() const;
    const Identity* getGender() const;
    int getAge() const;
    std::string getCountry() const;
    std::string getMaritalStatus() const;
    std::string getIdNumber() const;

    bool operator==(const IdCard& other) const;
    IdCard& operator=(const IdCard& other);
};