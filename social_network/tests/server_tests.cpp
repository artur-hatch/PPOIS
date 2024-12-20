#include <gtest/gtest.h>

#include "server.hpp"
#include "data.hpp"

class ServerTest : public ::testing::Test {
protected:
    void SetUp() override {
        for(auto & user: Data::GetUsers())
        {
            Data::RemoveUser(user.first);
        }
    }
};

TEST_F(ServerTest, LoginSuccessTest) {
    std::string email = "test@example.com";
    std::string username = "test_user";
    std::string password = "password123";
    
    Server::CreateNewAccount(email, username, password);
    
    EXPECT_TRUE(Server::Login(email, password));
    EXPECT_EQ(Server::GetCurrentUser()->GetEmail(), email);
}

TEST_F(ServerTest, LoginIncorrectPasswordTest) {
    std::string email = "test@example.com";
    std::string username = "test_user";
    std::string password = "password123";
    
    Server::CreateNewAccount(email, username, password);
    
    EXPECT_FALSE(Server::Login(email, "wrong_password"));
}

TEST_F(ServerTest, LoginUserNotFoundTest) {
    EXPECT_FALSE(Server::Login("unknown@example.com", "password123"));
}

TEST_F(ServerTest, CreateNewAccountSuccessTest) {
    EXPECT_TRUE(Server::CreateNewAccount("test@example.com", "test_user", "password123"));
}

TEST_F(ServerTest, CreateNewAccountAlreadyExistsTest) {
    Server::CreateNewAccount("test@example.com", "test_user", "password123");
    EXPECT_FALSE(Server::CreateNewAccount("test@example.com", "another_user", "password456"));
}

TEST_F(ServerTest, LogoutSuccessTest) {
    Server::CreateNewAccount("test@example.com", "test_user", "password123");
    Server::Login("test@example.com", "password123");
    EXPECT_TRUE(Server::Logout());
    EXPECT_EQ(Server::GetCurrentUser(), nullptr);
}

TEST_F(ServerTest, LogoutNoUserTest) {
    EXPECT_FALSE(Server::Logout());
}

TEST_F(ServerTest, DeleteAccountSuccessTest) {
    Server::CreateNewAccount("test@example.com", "test_user", "password123");
    Server::Login("test@example.com", "password123");
    auto currentUser = Server::GetCurrentUser();
    EXPECT_NO_THROW(Server::DeleteAccount(currentUser));
    EXPECT_EQ(Server::GetCurrentUser(), nullptr);
}

TEST_F(ServerTest, DeleteAccountNoUserTest) {
    EXPECT_NO_THROW(Server::DeleteAccount(nullptr));
}