#include "comment.hpp"

std::string Comment::GetText() const
{
    return text;
}

std::string Comment::GetAuthorEmail() const
{
    return authorEmail;
}

void Comment::Display() const
{
    std::cout << text << "\n";
    std::cout << "This comment was created at " << created_at << " by " << authorEmail << std::endl;
    std::cout << "Comment id: " << id << "\n";
}

json Comment::Serialise() const
{
    json commentJson = Entity::Serialise(); 
    commentJson["text"] = text;             
    commentJson["authorEmail"] = authorEmail; 

    return commentJson;
}

void Comment::Deserialise(const json& commentJson)
{
    created_at = commentJson["createdAt"].get<std::string>();
    text = commentJson["text"].get<std::string>();
    authorEmail = commentJson["authorEmail"].get<std::string>();
}
