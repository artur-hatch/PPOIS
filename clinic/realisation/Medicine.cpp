#include "medicine.h"
#include <iostream>

Medicine::Medicine(const std::string& name, double dosage, const std::string& manufacturer)
    : name(name), dosage(dosage), manufacturer(manufacturer) {}

std::string Medicine::getName() const {
    return name;
}

double Medicine::getDosage() const {
    return dosage;
}

std::string Medicine::getManufacturer() const {
    return manufacturer;
}

void Medicine::setName(const std::string& name) {
    this->name = name;
}

void Medicine::setDosage(double dosage) {
    this->dosage = dosage;
}

void Medicine::setManufacturer(const std::string& manufacturer) {
    this->manufacturer = manufacturer;
}

void Medicine::displayInfo() const {
    std::cout << "Name: " << name << "\n";
    std::cout << "Dosage: " << dosage << " mg\n";
    std::cout << "Manufacturer: " << manufacturer << "\n";
}