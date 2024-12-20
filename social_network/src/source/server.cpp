#include "server.hpp"

std::shared_ptr<User> Server::currentUser = nullptr; 

bool Server::Login(std::string const & _email, std::string const & _password)
{
    auto const & users = Data::GetUsers();

    auto it = users.find(_email);
    if (it != users.end()) {
        auto foundUser = it->second;
        if(foundUser->GetPassword() == _password)
        {
            currentUser = it->second; 
            std::cout << "User " << currentUser->GetUsername() << " logged in :)" << std::endl;
            return true;
        }
        else
        {
            std::cout << "Uncorrect password :(";
            return false;
        }
    }
    std::cout << "User not found!" << std::endl;
    return false;
}

bool Server::CreateNewAccount(std::string const & _email, std::string const & _username, std::string const & _password)
{
    auto const & users = Data::GetUsers();

    if (users.find(_email) != users.end())
    {
        std::cerr << "User already exists!" << std::endl;
        return false;
    }

    auto newUser = std::make_shared<User>(Utils::GetTimeNow(), _username, _email, _password);
    Data::AddUser(_email, newUser);

    return true;
}

bool Server::Logout()
{
    if (currentUser)
    { 
        currentUser.reset(); 
        return true; 
    }
    return false; 
}

std::shared_ptr<User> Server::GetCurrentUser()
{
    return currentUser;
}

void Server::DeleteAccount(std::shared_ptr<User> _user)
{
    if(_user == nullptr)
    {
        return;
    }
    currentUser.reset();
    Data::RemoveUser(_user->GetEmail());
}
