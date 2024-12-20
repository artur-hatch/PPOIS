#pragma once
#include <string>
#include "../include/FullName.h"
#include <memory>

class DocumentSignature
{
private:
    std::string identifier_;
    FullName* creatorName_;

public:
    DocumentSignature();
    DocumentSignature(const std::string& identifier, const FullName& creatorName);
    DocumentSignature(const std::string& identifier, const std::string& firstName, const std::string& middleName, const std::string& familyName);
    DocumentSignature(const std::string& signature) {
        assignIdentifier(signature);  // Инициализация идентификатора или другого поля
    }

    void assignIdentifier(const std::string& identifier);
    void assignCreatorName(const FullName& creatorName);

    std::string retrieveIdentifier() const;
    FullName* retrieveCreatorName() const;

    bool isIdenticalTo(const DocumentSignature& other) const;
    bool operator==(const DocumentSignature& other) const {
        return identifier_ == other.identifier_ &&
               *creatorName_ == *(other.creatorName_);
    }
    void copyFrom(const DocumentSignature& other);

    // Новые функции для работы с полным именем
    void assignFirstName(const std::string& firstName);
    void assignMiddleName(const std::string& middleName);
    void assignFamilyName(const std::string& familyName);

    std::string retrieveFirstName() const;
    std::string retrieveMiddleName() const;
    std::string retrieveFamilyName() const;

    bool isCreatorNameEqualTo(const DocumentSignature& other) const;
    void cloneFromFullName(const FullName& other);

    // Добавлен метод для преобразования в строку
    std::string toString() const {
        // Если имя создателя существует, используем его
        std::string creatorFullName = (creatorName_ != nullptr) ? creatorName_->toString() : "Unknown";
        return "Identifier: " + identifier_ + ", Creator: " + creatorFullName;
    }
};
