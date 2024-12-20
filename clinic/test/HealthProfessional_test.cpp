#include <gtest/gtest.h>
#include "../include/HealthProfessional.h"
#include "../include/Client.h"
#include "../include/MedicalRecord.h"

class HealthProfessionalTest : public ::testing::Test {
protected:
    HealthProfessional* healthProfessional;
    Client* client1;
    Client* client2;

    HealthProfessionalTest() {
    healthProfessional = new HealthProfessional("Dr. John", "Doe", "Middle", "uniqueSig", "Male", 40, "USA", "Single", "ID123", 1, 10000.0);
    client1 = new Client(std::string("Alice"), std::string("Smith"), std::string("Middle"), std::string("uniqueSig1"), std::string("Female"), 30, std::string("USA"), std::string("Single"), std::string("ID001"), std::string("123 Street"), 1, true, 100);
    client2 = new Client(std::string("Bob"), std::string("Jones"), std::string("Middle"), std::string("uniqueSig2"), std::string("Male"), 35, std::string("Canada"), std::string("Married"), std::string("ID002"), std::string("456 Street"), 2, false, 90);

    }
};

TEST_F(HealthProfessionalTest, ConstructorTest) {
ASSERT_EQ(healthProfessional->getMonthlySalary(), 10000.0);
}

TEST_F(HealthProfessionalTest, TerminateClientTest) {
ASSERT_TRUE(client1->getLifeStatus());
healthProfessional->terminateClient(client1);
ASSERT_FALSE(client1->getLifeStatus());
}
