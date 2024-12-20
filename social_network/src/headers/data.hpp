#pragma once

#include <user.hpp>
#include <post.hpp>

#include <unordered_map>
#include <memory>
#include <fstream>

class User;
class Post;

class Data
{
private:
    static std::unordered_map<std::string, std::shared_ptr<User>> users;
    // <user_email, user>

public:
    static std::unordered_map<std::string, std::shared_ptr<Post>> GetPosts();

    static std::unordered_map<std::string, std::shared_ptr<User>> GetUsers();
    static void AddUser(std::string const & _email, std::shared_ptr<User> _user);
    static void RemoveUser(std::string const & _email);

    static bool Serialization();
    static bool Deserialization();
};