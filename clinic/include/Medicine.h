#pragma once
#include <string>

class Medicine {
private:
    std::string name;
    double dosage;
    std::string manufacturer;
public:
    Medicine(const std::string& name, double dosage, const std::string& manufacturer);

    std::string getName() const;
    double getDosage() const;
    std::string getManufacturer() const;

    void setName(const std::string& name);
    void setDosage(double dosage);
    void setManufacturer(const std::string& manufacturer);

    void displayInfo() const;
};
