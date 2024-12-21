/ Заголовочный файл: ambulance.h
#ifndef AMBULANCE_H
#define AMBULANCE_H

#include <string>
#include <vector>
#include "medicine.h"

class Ambulance {
private:
    std::string driverName;
    std::string licensePlate;
    std::vector<Medicine> medicines;
public:
    Ambulance(const std::string& driverName, const std::string& licensePlate);

    std::string getDriverName() const;
    std::string getLicensePlate() const;
    std::vector<Medicine> getMedicines() const;

    void setDriverName(const std::string& driverName);

    void addMedicine(const Medicine& medicine);
    void listMedicines() const;
};
