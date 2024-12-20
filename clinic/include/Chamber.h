#pragma once
#include <vector>
#include "../include/Client.h"
#include "../include/Identity.h"

class Unit
{
private:
    Identity* genderCategory;
    int capacity;
    std::vector<Client*> residents;

public:
    Unit();
    Unit(const Identity& genderCategory_, int capacity_);
    Unit(const std::string& genderType_, int capacity_);

    void setGenderCategory(const Identity& gender_);
    void setCapacity(int size_);
    Identity* getGenderCategory() const;
    int getCapacity() const;
    int findResidentIndex(Client* client_) const;
    bool hasResident(Client* client_) const;
    void addResident(Client* client_);
    void removeResident(Client* client_);
    void hostUnitEvent();

    Unit& operator=(const Unit& other);
    bool operator==(const Unit& other) const;
};