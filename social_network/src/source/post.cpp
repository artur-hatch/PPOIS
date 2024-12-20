#include "post.hpp"

std::string Post::GetContent() const
{
    return content;
}

void Post::Display() const
{
    std::cout << content << "\nThis post was created by " << authorEmail << " at " << created_at << "\n";
    std::cout << "Post id: " << id << "\n";
    if(!comments.empty())
    {
        std::cout << "== Comments ==\n";
        for(auto const & commentPair : comments)
        {
            auto const & comment = commentPair.second;
            comment->Display();
        }
    }
}

json Post::Serialise() const
{
    json postJson = Entity::Serialise();
    postJson["id"] = id;
    postJson["content"] = content;
    postJson["authorEmail"] = authorEmail;

    json commentsJson = json::object();
    for (const auto& commentPair : comments)
    {
        auto const & id = commentPair.first;
        auto const & comment = commentPair.second;
        commentsJson[id] = comment->Serialise();
    }
    postJson["comments"] = commentsJson;

    return postJson;
}

void Post::Deserialise(const json& postJson)
{
    id = postJson["id"].get<std::string>();
    created_at = postJson["createdAt"].get<std::string>();
    content = postJson["content"].get<std::string>();
    authorEmail = postJson["authorEmail"].get<std::string>();

    if (postJson.contains("comments")) {
        for (auto& item : postJson["comments"].items()) {
            const std::string& commentId = item.key().c_str();
            const auto& commentJson = item.value();
            
            auto comment = std::make_shared<Comment>();
            comment->Deserialise(commentJson);
            comments[commentId] = comment;
        }
    }
}

void Post::AddComment(std::string const& _text, std::string _authorEmail)
{
    std::string _created_at = Utils::GetTimeNow();
    std::string _id = Utils::GenerateId(_text, _created_at);

    auto comment = std::make_shared<Comment>(_created_at,_text, _authorEmail, _id);
    comments[_id]= comment;
}

std::unordered_map<std::string, std::shared_ptr<Comment>> Post::GetComments() const
{
    return comments;
}

std::string Post::GetAuthorEmail() const
{
    return authorEmail;
}
