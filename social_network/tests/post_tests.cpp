#include <gtest/gtest.h>

#include "post.hpp"

class PostTest : public ::testing::Test {
protected:
    void SetUp() override {
        post = std::make_shared<Post>("1", "2024-10-31", "This is a test post.", "author@example.com");
    }

    std::shared_ptr<Post> post;
};

TEST_F(PostTest, GetContentTest) {
    EXPECT_EQ(post->GetContent(), "This is a test post.");
}

TEST_F(PostTest, GetAuthorEmailTest) {
    EXPECT_EQ(post->GetAuthorEmail(), "author@example.com");
}

TEST_F(PostTest, AddCommentTest) {
    post->AddComment("This is a comment.", "commenter@example.com");
    auto comments = post->GetComments();
    EXPECT_EQ(comments.size(), 1);
    EXPECT_EQ(comments.begin()->second->GetText(), "This is a comment.");
}

TEST_F(PostTest, DisplayTest) {
    testing::internal::CaptureStdout();
    post->Display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("This is a test post.") != std::string::npos);
}

TEST_F(PostTest, SerialiseAndDeserialiseTest) {
    post->AddComment("This is a comment.", "commenter@example.com");
    
    json serialized = post->Serialise();
    
    EXPECT_EQ(serialized["content"], "This is a test post.");
    EXPECT_EQ(serialized["authorEmail"], "author@example.com");
    EXPECT_EQ(serialized["comments"].size(), 1);
    
    json postJson = {
        {"id", "1"},
        {"createdAt", "2024-10-31"},
        {"content", "Deserialized post content."},
        {"authorEmail", "author@example.com"},
        {"comments", json::object()}
    };
    
    post->Deserialise(postJson);
    
    EXPECT_EQ(post->GetContent(), "Deserialized post content.");
    EXPECT_EQ(post->GetAuthorEmail(), "author@example.com");
}
