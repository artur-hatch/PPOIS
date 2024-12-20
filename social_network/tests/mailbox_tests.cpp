#include <gtest/gtest.h>
#include <memory>
#include <mailbox.hpp>

class MailboxTest : public ::testing::Test {
protected:
    std::shared_ptr<Mailbox> mailbox;
    std::shared_ptr<Message> message1;
    std::shared_ptr<Message> message2;

    void SetUp() override {
        mailbox = std::make_shared<Mailbox>();
        message1 = std::make_shared<Message>("2024-10-31", "Test message 1", "sender1@example.com", "recipient@example.com");
        message2 = std::make_shared<Message>("2024-10-31", "Test message 2", "sender2@example.com", "recipient@example.com");
    }
};

TEST_F(MailboxTest, AddMessageTest) {
    mailbox->AddMessage(message1);
    EXPECT_EQ(mailbox->GetMessages().size(), 1);
    EXPECT_EQ(mailbox->GetMessages()[0]->GetText(), "Test message 1");

    mailbox->AddMessage(nullptr); 
    EXPECT_EQ(mailbox->GetMessages().size(), 1);
}

TEST_F(MailboxTest, DisplayTest) {
    mailbox->AddMessage(message1);
    mailbox->AddMessage(message2);
    testing::internal::CaptureStdout(); 
    mailbox->Display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("You've received a message from sender1@example.com:"), std::string::npos);
    EXPECT_NE(output.find("You've received a message from sender2@example.com:"), std::string::npos);
}

TEST_F(MailboxTest, SerialiseAndDeserialiseTest) {
    mailbox->AddMessage(message1);
    mailbox->AddMessage(message2);
    
    json serialized = mailbox->Serialise();
    EXPECT_EQ(serialized["messages"].size(), 2);
    
    Mailbox newMailbox;
    newMailbox.Deserialise(serialized);
    
    EXPECT_EQ(newMailbox.GetMessages().size(), 2);
    EXPECT_EQ(newMailbox.GetMessages()[0]->GetText(), "Test message 1");
    EXPECT_EQ(newMailbox.GetMessages()[1]->GetText(), "Test message 2");
}
