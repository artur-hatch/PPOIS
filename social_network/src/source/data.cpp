#include <data.hpp>

std::unordered_map<std::string, std::shared_ptr<User>> Data::users;

std::unordered_map<std::string, std::shared_ptr<Post>> Data::GetPosts()
{
    std::unordered_map<std::string, std::shared_ptr<Post>> posts;

    for(auto const & userPair: GetUsers())
    {
        auto const & user = userPair.second;

        for(auto const & post: user->GetPosts())
        {
            posts[post.first] = post.second;
        }
    }

    return posts;
}

std::unordered_map<std::string, std::shared_ptr<User>> Data::GetUsers()
{
    return users;
}

void Data::AddUser(std::string const & _user_id, std::shared_ptr<User> _user)
{
    users[_user_id] = _user;
}

void Data::RemoveUser(std::string const& _email)
{
    users.erase(_email);
}

bool Data::Serialization() {
    json dataJson = json::object();
    
    for (const auto& userPair : users) {
        const std::string& email = userPair.first;
        const auto& user = userPair.second;
        dataJson[userPair.first] = userPair.second->Serialise();
    }

    std::ofstream outFile("data.json");
    if (outFile.is_open())
    {
        outFile << dataJson.dump(4);
        outFile.close();
        return true;
    }
    else
    {
        return false;
    }
}

bool Data::Deserialization()
{
    std::ifstream file("data.json");
    if (!file.is_open())
    {
        return 0;
    }

    nlohmann::json jsonData;
    file >> jsonData;

    for (const auto& accountJson : jsonData)
    {
        std::shared_ptr<User> user = std::make_shared<User>();

        user->Deserialise(accountJson);

        users[user->GetEmail()] = user;
    }

    file.close();

    return 1;
}

