#pragma once

#include <entity.hpp>
#include <user.hpp>
#include <comment.hpp>
#include "../utils/utils.hpp"

#include <vector>
#include <unordered_map>
#include <memory>

class Comment;
class User;

class Post : public Entity{
private:
    std::string content;
    std::string id;
    std::string authorEmail;

    std::unordered_map<std::string, std::shared_ptr<Comment>> comments;

public:
    Post() = default;

    Post(std::string const & _id, std::string const & _created_at, std::string const & _content, std::string _authorEmail):
        Entity(_created_at), content(_content), authorEmail(_authorEmail), id(_id) {};

    std::string GetContent() const;

    void Display() const override;
    json Serialise() const override;
    void Deserialise(const json& postJson) override;

    void AddComment(std::string const & _text, std::string _authorEmail);
    std::unordered_map<std::string, std::shared_ptr<Comment>> GetComments() const;
    std::string GetAuthorEmail() const;
};
