#include "../include/Chamber.h"
#include <iostream>

Unit::Unit()
{
    genderCategory = new Identity();
    capacity = 0;
}

Unit::Unit(const Identity& genderCategory_, int capacity_)
{
    genderCategory = new Identity();
    setGenderCategory(genderCategory_);
    setCapacity(capacity_);
}

Unit::Unit(const std::string& genderType_, int capacity_)
{
    genderCategory = new Identity(genderType_);
    setCapacity(capacity_);
}

void Unit::setGenderCategory(const Identity& gender_)
{
    *genderCategory = gender_;
}

void Unit::setCapacity(int size_)
{
    capacity = size_;
}

Identity* Unit::getGenderCategory() const
{
    return genderCategory;
}

int Unit::getCapacity() const
{
    return capacity;
}

int Unit::findResidentIndex(Client* client_) const
{
    for (size_t i = 0; i < residents.size(); i++)
        if (residents[i] == client_)
            return static_cast<int>(i);
    return -1;
}

bool Unit::hasResident(Client* client_) const
{
    return findResidentIndex(client_) != -1;
}

void Unit::addResident(Client* client_)
{
    if (*(client_->getIdCard()->getGender()) == *genderCategory)
        if (residents.size() < capacity)
            if (!hasResident(client_))
                residents.push_back(client_);
}

void Unit::removeResident(Client* client_)
{
    int index = findResidentIndex(client_);
    if (index != -1)
        residents.erase(residents.begin() + index);
}

void Unit::hostUnitEvent()
{
    for (auto& resident : residents)
        resident->setLifeStatus(resident->getLifeStatus() * 1.02);
}

Unit& Unit::operator=(const Unit& other)
{
    if (this != &other) {
        setGenderCategory(*(other.getGenderCategory()));
        setCapacity(other.getCapacity());
    }
    return *this;
}

bool Unit::operator==(const Unit& other) const
{
    return (*genderCategory == *(other.getGenderCategory())) && (capacity == other.getCapacity());
}