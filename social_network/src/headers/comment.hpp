#pragma once

#include <entity.hpp>
#include <user.hpp>

#include <memory>

class User;

class Comment :  Entity
{
private:
    std::string authorEmail;
    std::string text;
    std::string id;

public:
    Comment() = default;

    Comment(std::string const & _created_at, std::string const & _text, std::string _authorEmail, std::string const & _id)
        :Entity(_created_at), text(_text), authorEmail(_authorEmail), id(_id){};
        
    
    std::string GetText() const;
    std::string GetAuthorEmail() const;
    

    void Display() const override;
    json Serialise() const override;
    void Deserialise(const json& commentJson) override;
};