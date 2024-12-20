#include <gtest/gtest.h>

#include "user.hpp"

TEST(UserTest, GetUsernameTest) {
    User user("2024-10-31", "test_user", "test@example.com", "password123");
    EXPECT_EQ(user.GetUsername(), "test_user");
}

TEST(UserTest, GetEmailTest) {
    User user("2024-10-31", "test_user", "test@example.com", "password123");
    EXPECT_EQ(user.GetEmail(), "test@example.com");
}

TEST(UserTest, GetPasswordTest) {
    User user("2024-10-31", "test_user", "test@example.com", "password123");
    EXPECT_EQ(user.GetPassword(), "password123");
}

TEST(UserTest, SetAndGetBioTest) {
    User user("2024-10-31", "test_user", "test@example.com", "password123");
    user.SetBio("Developer and tester");
    EXPECT_EQ(user.GetBio(), "Developer and tester");
}

TEST(UserTest, GetMailboxTest) {
    User user("2024-10-31", "test_user", "test@example.com", "password123");
    EXPECT_NE(user.GetMailbox(), nullptr);
}

TEST(UserTest, CreatePostAndGetPostsTest) {
    User user("2024-10-31", "test_user", "test@example.com", "password123");
    user.CreatePost("Hello, this is my first post!");
    
    auto posts = user.GetPosts();
    ASSERT_EQ(posts.size(), 1);
    
    auto it = posts.begin();
    EXPECT_EQ(it->second->GetContent(), "Hello, this is my first post!");
}

TEST(UserTest, GetPostsTest) {
    User user("2024-10-31", "test_user", "test@example.com", "password123");
    user.CreatePost("Post 1");
    user.CreatePost("Post 2");
    
    auto posts = user.GetPosts();
    EXPECT_EQ(posts.size(), 2);
}

TEST(UserTest, ReceiveMessageTest) {
    User sender("2024-10-31", "sender_user", "sender@example.com", "password123");
    User receiver("2024-10-31", "receiver_user", "receiver@example.com", "password123");

    receiver.ReceiveMessage("Hello!", std::make_shared<User>(sender));
    auto mailbox = receiver.GetMailbox();

    EXPECT_EQ(mailbox->GetMessages().size(), 1);
    EXPECT_EQ(mailbox->GetMessages()[0]->GetText(), "Hello!");
}

TEST(UserTest, SerialiseAndDeserialiseTest) {
    User user("2024-10-31", "test_user", "test@example.com", "password123");
    user.SetBio("Developer and tester");
    user.CreatePost("Hello, this is my first post!");

    json userJson = user.Serialise();
    User newUser;
    newUser.Deserialise(userJson);

    EXPECT_EQ(newUser.GetUsername(), user.GetUsername());
    EXPECT_EQ(newUser.GetEmail(), user.GetEmail());
    EXPECT_EQ(newUser.GetBio(), user.GetBio());
    EXPECT_EQ(newUser.GetPosts().size(), user.GetPosts().size());
}
