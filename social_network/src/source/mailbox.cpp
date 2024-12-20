#include <mailbox.hpp>

void Mailbox::AddMessage(std::shared_ptr<Message> _message)
{
    if (!_message) {
        return; 
    }
    this->messages.push_back(_message);
}

std::vector<std::shared_ptr<Message>> Mailbox::GetMessages()
{
    return messages;
}

void Mailbox::Display() const
{
    for(auto const & message: messages)
    {
        message->Display();
        std::cout << std::endl;
    }
}

json Mailbox::Serialise() const
{
    json mailboxJson;
    mailboxJson["messages"] = json::array(); 

    for (const auto& message : messages)
    {
        if (message)
        {
            mailboxJson["messages"].push_back(message->Serialise());
        }
    }

    return mailboxJson;
}

void Mailbox::Deserialise(json const& mailboxJson)
{
    messages.clear();

    for (const auto& messageJson : mailboxJson["messages"]) {
        auto message = std::make_shared<Message>(); 
        message->Deserialise(messageJson); 
        messages.push_back(message);
    }
}
