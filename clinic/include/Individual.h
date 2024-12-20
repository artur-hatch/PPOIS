
#pragma once
#include "../include/IDCard.h"

class Individual {
protected:
    IdCard* idCardPtr;
    int lifeStatus;

public:
    Individual();
    Individual(const IdCard& idCard, int status);
    Individual(const std::string& firstName, const std::string& lastName, const std::string& middleName,
               const std::string& uniqueSignature, const std::string& gender, int age, const std::string& country,
               const std::string& maritalStatus, const std::string& idNumber, int status);

    void setIdCard(const IdCard& idCard);
    IdCard* getIdCard() const;
    void setLifeStatus(int status);
    int getLifeStatus() const;

    Individual& operator=(const Individual& other);
    bool operator==(const Individual& other) const;
};
