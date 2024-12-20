#pragma once

#include "../utils/utils.hpp"

#include <user.hpp>
#include <post.hpp>
#include <data.hpp>

#include <unordered_map>
#include <memory>
#include <vector>

class User;
class Post;

class Server
{
private:
    static std::shared_ptr<User> currentUser;

public:
    static bool Login (std::string const & _login, std::string const & _password);
    static bool CreateNewAccount (std::string const & _email, std::string const & _username, std::string const & _password);
    static bool Logout();

    static std::shared_ptr<User> GetCurrentUser();
    static void DeleteAccount(std::shared_ptr<User> _user);
};