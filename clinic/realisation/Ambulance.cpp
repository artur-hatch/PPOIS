#include "Ambulance.h"
#include <iostream>

Ambulance::Ambulance(const std::string& driverName, const std::string& licensePlate)
    : driverName(driverName), licensePlate(licensePlate) {}

std::string Ambulance::getDriverName() const {
    return driverName;
}

std::string Ambulance::getLicensePlate() const {
    return licensePlate;
}

std::vector<Medicine> Ambulance::getMedicines() const {
    return medicines;
}

void Ambulance::setDriverName(const std::string& driverName) {
    this->driverName = driverName;
}

void Ambulance::setLicensePlate(const std::string& licensePlate) {
    this->licensePlate = licensePlate;
}

void Ambulance::addMedicine(const Medicine& medicine) {
    medicines.push_back(medicine);
}

void Ambulance::listMedicines() const {
    std::cout << "Medicines in ambulance:\n";
    for (const auto& medicine : medicines) {
        medicine.displayInfo();
    }
}