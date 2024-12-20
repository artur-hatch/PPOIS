#pragma once

#include <entity.hpp>
#include <post.hpp>
#include <server.hpp>
#include <message.hpp>
#include <mailbox.hpp>

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>

class Message;
class Post;
class Mailbox;

class User : public Entity 
{  
protected:
    std::string username;
    std::string email;
    std::string bio;
    std::string password;

    std::shared_ptr<Mailbox> mailbox;

    std::unordered_map<std::string, std::shared_ptr<Post>> posts;

public:
    User() = default;

    User(std::string const & _created_at, std::string const & _username, std::string const & _email, std::string const & _password):
        Entity(_created_at), username(_username), email(_email), password(_password), mailbox(std::make_shared<Mailbox>()){};
    
    std::string GetUsername() const;
    std::string GetBio() const;
    std::string GetEmail() const;
    std::string GetPassword() const;
    std::shared_ptr<Mailbox> GetMailbox() const;

    std::unordered_map<std::string, std::shared_ptr<Post>> GetPosts() const;
    
    void Display() const override;
    json Serialise() const override;
    void Deserialise(const json& userJson) override;

    void CreatePost(std::string const & _content);
    void SetBio(std::string const & _bio);

    void ReceiveMessage(std::string const & _text, std::shared_ptr<User> _recipient) const;
};

