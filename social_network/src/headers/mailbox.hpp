#pragma once

#include <entity.hpp>
#include <message.hpp>

#include <vector>

class Message;

class Mailbox: public Entity
{
public:
    void AddMessage(std::shared_ptr<Message> _message);

    std::vector<std::shared_ptr<Message>> GetMessages();

    void Display() const override;
    json Serialise() const override;
    void Deserialise(json const & mailboxJson) override;

private:
    std::vector<std::shared_ptr<Message>> messages;
};