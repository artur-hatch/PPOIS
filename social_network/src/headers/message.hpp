#pragma once

#include <entity.hpp>
#include <user.hpp>

class User;

class Message : public Entity
{
private:
    std::string senderEmail;
    std::string recipientEmail;
    std::string text;

public:
    Message() = default;

    Message(std::string const & _created_at, std::string const & _text, std::string const & _senderEmail, std::string const & _recipientEmail):
        Entity(_created_at), text(_text), senderEmail(_senderEmail), recipientEmail(_recipientEmail) {};

    std::string GetText() const;

    void Display() const override;
    json Serialise() const override;
    void Deserialise(const json& messageJson) override;
};