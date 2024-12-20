#include "../include/IDCard.h"

IdCard::IdCard()
        : signature_(std::make_unique<DocumentSignature>()), gender_(std::make_unique<Identity>()), age_(0), country_(""), maritalStatus_(""), idNumber_("") {}

IdCard::IdCard(const DocumentSignature& sign, const Identity& genderType, int personAge, const std::string& residence,
               const std::string& status, const std::string& id)
        : IdCard() {
    setSignature(sign);
    setGender(genderType);
    setAge(personAge);
    setCountry(residence);
    setMaritalStatus(status);
    setIdNumber(id);
}

IdCard::IdCard(const std::string& firstName, const std::string& middleName, const std::string& familyName,
               const std::string& uniqueSign, const std::string& genderType, int personAge, const std::string& residence,
               const std::string& status, const std::string& id)
        : IdCard() {
    signature_ = std::make_unique<DocumentSignature>(uniqueSign, firstName, middleName, familyName);
    gender_ = std::make_unique<Identity>(genderType);
    setAge(personAge);
    setCountry(residence);
    setMaritalStatus(status);
    setIdNumber(id);
}

void IdCard::setName(const FullName& fullName) {
    if (signature_) {
        signature_->assignFirstName(fullName.retrieveFirstName());
        signature_->assignMiddleName(fullName.retrieveMiddleName());
        signature_->assignFamilyName(fullName.retrieveFamilyName());
    }
}

void IdCard::setSignature(const DocumentSignature& sign) {
    if (!signature_) {
        signature_ = std::make_unique<DocumentSignature>();
    }
    *signature_ = sign;
}

void IdCard::setGender(const Identity& genderType) {
    if (!gender_) {
        gender_ = std::make_unique<Identity>();
    }
    *gender_ = genderType;
}

void IdCard::setAge(int personAge) {
    age_ = personAge % 130; // Ограничение возраста
}

void IdCard::setCountry(const std::string& residence) {
    country_ = residence;
}

void IdCard::setMaritalStatus(const std::string& status) {
    maritalStatus_ = status;
}

void IdCard::setIdNumber(const std::string& id) {
    idNumber_ = id;
}

const FullName* IdCard::getName() const {
    return signature_ ? signature_->retrieveCreatorName() : nullptr;
}

const DocumentSignature* IdCard::getSignature() const {
    return signature_.get();
}

const Identity* IdCard::getGender() const {
    return gender_.get();
}

int IdCard::getAge() const {
    return age_;
}

std::string IdCard::getCountry() const {
    return country_;
}

std::string IdCard::getMaritalStatus() const {
    return maritalStatus_;
}

std::string IdCard::getIdNumber() const {
    return idNumber_;
}

bool IdCard::operator==(const IdCard& other) const {
    return *signature_ == *(other.getSignature()) &&
           *gender_ == *(other.getGender()) &&
           age_ == other.getAge() &&
           country_ == other.getCountry() &&
           maritalStatus_ == other.getMaritalStatus() &&
           idNumber_ == other.getIdNumber();
}

IdCard& IdCard::operator=(const IdCard& other) {
    if (this != &other) {
        setSignature(*(other.getSignature()));
        setName(*(other.getName()));  // Обновлено для работы с FullName
        setGender(*(other.getGender()));
        setAge(other.getAge());
        setCountry(other.getCountry());
        setMaritalStatus(other.getMaritalStatus());
        setIdNumber(other.getIdNumber());
    }
    return *this;
}