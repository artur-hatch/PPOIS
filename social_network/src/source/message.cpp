#include "message.hpp"

std::string Message::GetText() const
{
    return text;
}

void Message::Display() const
{
    std::cout << "You've received a message from " << senderEmail << ": " << std::endl;
    std::cout << text << std::endl;
    std::cout << created_at; 
}

json Message::Serialise() const
{
    json messageJson;
    messageJson["created_at"] = created_at;    
    messageJson["text"] = text;
    messageJson["senderEmail"] = senderEmail;
    messageJson["recipientEmail"] = recipientEmail;
    return messageJson;
    return json();
}

void Message::Deserialise(const json& messageJson)
{
    created_at = messageJson.at("created_at").get<std::string>();
    text = messageJson.at("text").get<std::string>();
    senderEmail = messageJson.at("senderEmail").get<std::string>();
    recipientEmail = messageJson.at("recipientEmail").get<std::string>();
}
