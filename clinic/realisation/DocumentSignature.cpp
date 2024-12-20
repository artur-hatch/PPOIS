#include "../include/DocumentSignature.h"

DocumentSignature::DocumentSignature() {
    creatorName_ = new FullName();
}

DocumentSignature::DocumentSignature(const std::string& identifier, const FullName& creatorName) {
    assignIdentifier(identifier);
    creatorName_ = new FullName();
    assignCreatorName(creatorName);
}

DocumentSignature::DocumentSignature(const std::string& identifier, const std::string& firstName, const std::string& middleName, const std::string& familyName) {
    assignIdentifier(identifier);
    creatorName_ = new FullName(firstName, middleName, familyName);
}

void DocumentSignature::assignIdentifier(const std::string& identifier) {
    identifier_ = identifier;
}

void DocumentSignature::assignCreatorName(const FullName& creatorName) {
    *creatorName_ = creatorName;
}

std::string DocumentSignature::retrieveIdentifier() const {
    return identifier_;
}

FullName* DocumentSignature::retrieveCreatorName() const {
    return creatorName_;
}

bool DocumentSignature::isIdenticalTo(const DocumentSignature& other) const {
    return (creatorName_->isEqualTo(*(other.retrieveCreatorName())) && (identifier_ == other.retrieveIdentifier()));
}

void DocumentSignature::copyFrom(const DocumentSignature& other) {
    assignCreatorName(*(other.retrieveCreatorName()));
    assignIdentifier(other.retrieveIdentifier());
}

// Новые методы для работы с полными именами
void DocumentSignature::assignFirstName(const std::string& firstName) {
    if (creatorName_) {
        creatorName_->assignFirstName(firstName);
    }
}

void DocumentSignature::assignMiddleName(const std::string& middleName) {
    if (creatorName_) {
        creatorName_->assignMiddleName(middleName);
    }
}

void DocumentSignature::assignFamilyName(const std::string& familyName) {
    if (creatorName_) {
        creatorName_->assignFamilyName(familyName);
    }
}

std::string DocumentSignature::retrieveFirstName() const {
    return creatorName_ ? creatorName_->retrieveFirstName() : "";
}

std::string DocumentSignature::retrieveMiddleName() const {
    return creatorName_ ? creatorName_->retrieveMiddleName() : "";
}

std::string DocumentSignature::retrieveFamilyName() const {
    return creatorName_ ? creatorName_->retrieveFamilyName() : "";
}

bool DocumentSignature::isCreatorNameEqualTo(const DocumentSignature& other) const {
    return creatorName_->isEqualTo(*(other.retrieveCreatorName()));
}

void DocumentSignature::cloneFromFullName(const FullName& other) {
    if (creatorName_) {
        creatorName_->copyFrom(other);
    }
}