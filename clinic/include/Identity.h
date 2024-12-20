#pragma once
#include <string>

class Identity
{
private:
    std::string category_;

public:
    Identity();
    Identity(const std::string& category);

    void assignCategory(const std::string& category);
    std::string retrieveCategory() const;

    // Новый метод getGender
    std::string getGender() const {
        return category_;
    }

    bool operator==(const Identity& other) const {
        return category_ == other.category_;
    }

    void copyFrom(const Identity& other);
    bool isSameAs(const Identity& other) const;
};
