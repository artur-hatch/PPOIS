#pragma once

#include <string>
#include <chrono>
#include <ctime>

#include <json.hpp>
using json = nlohmann::json;

class Entity 
{
protected:
    std::string created_at;

public:
    Entity() = default;

    Entity(std::string const & _created_at):
        created_at(_created_at){};

    virtual ~Entity() = default;

    virtual void Display() const = 0;
    virtual json Serialise() const;
    virtual void Deserialise(json const & j) = 0;

    std::string GetCreatedAt() const;
};
