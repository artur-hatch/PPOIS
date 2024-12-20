#include "user.hpp"

std::string User::GetUsername() const
{
    return username;
}

std::string User::GetBio() const
{
    return bio;
}

std::string User::GetEmail() const
{
    return email;
}

std::string User::GetPassword() const
{
    return password;
}

std::shared_ptr<Mailbox> User::GetMailbox() const
{
    return mailbox;
}

std::unordered_map<std::string, std::shared_ptr<Post>> User::GetPosts() const
{
    return posts;
}

void User::Display() const
{
    std::cout << "Account " << username << " with email " << email << "\n";
    if(!bio.empty())
    {
        std::cout << "Your bio: " << bio;
    }

    std::cout << std::endl;

    Utils::PauseTerminal();
}

json User::Serialise() const
{
    json userJson = Entity::Serialise();
    userJson["username"] = username;
    userJson["email"] = email;
    userJson["password"] = password;
    userJson["bio"] = bio;

    json postsJson = json::object();
    for (const auto& postPair : posts) {
        const std::string& id = postPair.first;
        const auto& post = postPair.second;
        postsJson[id] = post->Serialise();
    }

    userJson["posts"] = postsJson;

    if (mailbox) {
        userJson["mailbox"] = mailbox->Serialise();
    }

    return userJson;
}

void User::Deserialise(const json& userJson)
{
    created_at = userJson["createdAt"].get<std::string>();
    username = userJson["username"].get<std::string>();
    email = userJson["email"].get<std::string>();
    password = userJson["password"].get<std::string>();
    bio = userJson.value("bio", "");

    mailbox = std::make_shared<Mailbox>();

    if (userJson.contains("mailbox")) {
        mailbox->Deserialise(userJson["mailbox"]);
    }

    if (userJson.contains("posts")) {
        for (auto& item : userJson["posts"].items()) {
            const auto& postId = item.key();
            const auto& postJson = item.value();
            
            auto post = std::make_shared<Post>();
            post->Deserialise(postJson);
            posts[postId] = post;
        }
    }
}

void User::CreatePost(std::string const & _content)
{
    std::string const _created_at = Utils::GetTimeNow();
    auto const _id = Utils::GenerateId(_content, _created_at);

    std::shared_ptr<Post> post = std::make_shared<Post>(_id ,_created_at, _content, GetEmail());
    posts[_id] = post;
}

void User::SetBio(std::string const & _bio)
{
    bio = _bio;
}

void User::ReceiveMessage(std::string const& _text, std::shared_ptr<User> _sender) const
{
    std::string const _created_at = Utils::GetTimeNow();
    std::shared_ptr<Message> _message = std::make_shared<Message>(_created_at, _text, _sender->GetEmail(), this->GetEmail());

    this->GetMailbox()->AddMessage(_message);
}
