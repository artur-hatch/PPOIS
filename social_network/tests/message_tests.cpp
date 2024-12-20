#include <gtest/gtest.h>

#include "message.hpp"

class MessageTest : public ::testing::Test {
protected:
    void SetUp() override {
        message = std::make_shared<Message>("2024-10-31", "Hello, this is a test message.", "sender@example.com", "recipient@example.com");
    }

    std::shared_ptr<Message> message;
};

TEST_F(MessageTest, GetTextTest) {
    EXPECT_EQ(message->GetText(), "Hello, this is a test message.");
}

TEST_F(MessageTest, DisplayTest) {
    testing::internal::CaptureStdout();
    message->Display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_TRUE(output.find("You've received a message from sender@example.com:") != std::string::npos);
}

TEST_F(MessageTest, SerialiseAndDeserialiseTest) {
    json messageJson = {
        {"created_at", "2024-10-31"},
        {"text", "Hello, this is a test message."},
        {"senderEmail", "sender@example.com"},
        {"recipientEmail", "recipient@example.com"}
    };
    
    message->Deserialise(messageJson);
    
    json serialized = message->Serialise();
    
    EXPECT_EQ(serialized["text"], "Hello, this is a test message.");
    EXPECT_EQ(serialized["senderEmail"], "sender@example.com");
    EXPECT_EQ(serialized["recipientEmail"], "recipient@example.com");
    
    EXPECT_EQ(message->GetText(), "Hello, this is a test message.");
}
