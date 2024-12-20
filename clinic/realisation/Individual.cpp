#include "../include/Individual.h"

Individual::Individual() {
    idCardPtr = new IdCard();
    lifeStatus = 0;
}

Individual::Individual(const IdCard& idCard, int status) {
    idCardPtr = new IdCard();
    setIdCard(idCard);
    setLifeStatus(status);
}

Individual::Individual(const std::string& firstName, const std::string& middleName, const std::string& lastName,
                       const std::string& uniqueSignature, const std::string& gender, int age, const std::string& country,
                       const std::string& maritalStatus, const std::string& idNumber, int status) {
    idCardPtr = new IdCard(firstName, middleName, lastName, uniqueSignature, gender, age, country, maritalStatus, idNumber);
    setLifeStatus(status);
}


void Individual::setIdCard(const IdCard& idCard) {
    *idCardPtr = idCard;
}

IdCard* Individual::getIdCard() const {
    return idCardPtr;
}

void Individual::setLifeStatus(int status) {
    lifeStatus = (status < 0) ? 0 : (status > 100 ? 100 : status);
}

int Individual::getLifeStatus() const {
    return lifeStatus;
}

Individual& Individual::operator=(const Individual& other) {
    if (this != &other) {
        setIdCard(*(other.getIdCard()));
        setLifeStatus(other.getLifeStatus());
    }
    return *this;
}

bool Individual::operator==(const Individual& other) const {
    return (*idCardPtr == *(other.getIdCard())) && (lifeStatus == other.getLifeStatus());
}
