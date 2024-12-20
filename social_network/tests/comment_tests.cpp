#include <gtest/gtest.h>
#include "comment.hpp"

class CommentTest : public ::testing::Test {
protected:
    Comment comment;

    CommentTest() 
        : comment("2024-10-31 12:00:00", "This is a test comment.", "test@example.com", "1") {}
};

TEST_F(CommentTest, GetText) {
    EXPECT_EQ(comment.GetText(), "This is a test comment.");
}

TEST_F(CommentTest, Display) {
    testing::internal::CaptureStdout();
    comment.Display();
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("This is a test comment."), std::string::npos);
    EXPECT_NE(output.find("test@example.com"), std::string::npos);
    EXPECT_NE(output.find("Comment id: 1"), std::string::npos);
}

TEST_F(CommentTest, SerialiseAndDeserialise) {
    json serializedComment = comment.Serialise();

    json commentJson = {
        {"createdAt", "2024-10-31 12:00:00"},
        {"text", "This is a test comment."},
        {"authorEmail", "test@example.com"}
    };

    comment.Deserialise(commentJson);
    
    EXPECT_EQ(serializedComment["text"], "This is a test comment.");
    EXPECT_EQ(serializedComment["authorEmail"], "test@example.com");

    EXPECT_EQ(comment.GetText(), "This is a test comment.");
    EXPECT_EQ(comment.GetAuthorEmail(), "test@example.com");
}