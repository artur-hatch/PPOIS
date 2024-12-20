#include <gtest/gtest.h>

#include <data.hpp>
#include <user.hpp>

class DataTest : public ::testing::Test {
protected:
    void SetUp() override {
        Data::RemoveUser("test@example.com"); 
    }

    void TearDown() override {
        Data::RemoveUser("test@example.com"); 
    }
};

TEST_F(DataTest, AddUserTest) {
    auto user = std::make_shared<User>("2024-10-31", "Test User", "test@example.com", "password");
    Data::AddUser("test@example.com", user);

    auto retrievedUser = Data::GetUsers().at("test@example.com");
    EXPECT_EQ(retrievedUser->GetEmail(), "test@example.com");
    EXPECT_EQ(retrievedUser->GetUsername(), "Test User");
}

TEST_F(DataTest, RemoveUserTest) {
    auto user = std::make_shared<User>("2024-10-31", "Test User", "test@example.com", "password");
    Data::AddUser("test@example.com", user);
    Data::RemoveUser("test@example.com");

    EXPECT_EQ(Data::GetUsers().find("test@example.com"), Data::GetUsers().end());
}

TEST_F(DataTest, SerializationTest) {
    auto user = std::make_shared<User>("2024-10-31", "Test User", "test@example.com", "password");
    Data::AddUser("test@example.com", user);
    
    EXPECT_TRUE(Data::Serialization());

    std::ifstream file("data.json");
    EXPECT_TRUE(file.is_open());
    file.close();
}

TEST_F(DataTest, DeserializationTest) {
    auto user = std::make_shared<User>("2024-10-31", "Test User", "test@example.com", "password");
    Data::AddUser("test@example.com", user);
    Data::Serialization();
    
    Data::RemoveUser("test@example.com");

    EXPECT_TRUE(Data::Deserialization());
    auto retrievedUser = Data::GetUsers().at("test@example.com");
    EXPECT_EQ(retrievedUser->GetEmail(), "test@example.com");
    EXPECT_EQ(retrievedUser->GetUsername(), "Test User");
}
