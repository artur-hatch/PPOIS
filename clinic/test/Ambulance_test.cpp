#include "ambulance.h"
#include <gtest/gtest.h>

TEST(AmbulanceTest, ConstructorAndGetters) {
    Ambulance amb("John Doe", "AB-123-CD");
    EXPECT_EQ(amb.getDriverName(), "John Doe");
    EXPECT_EQ(amb.getLicensePlate(), "AB-123-CD");
}

TEST(AmbulanceTest, Setters) {
    Ambulance amb("John Doe", "AB-123-CD");
    amb.setDriverName("Jane Smith");
    amb.setLicensePlate("EF-456-GH");
    EXPECT_EQ(amb.getDriverName(), "Jane Smith");
    EXPECT_EQ(amb.getLicensePlate(), "EF-456-GH");
}

TEST(AmbulanceTest, AddAndListMedicines) {
    Ambulance amb("John Doe", "AB-123-CD");
    Medicine med1("Aspirin", 500, "Pharma Inc.");
    Medicine med2("Paracetamol", 650, "HealthCorp");
    amb.addMedicine(med1);
    amb.addMedicine(med2);

    auto medicines = amb.getMedicines();
    ASSERT_EQ(medicines.size(), 2);
    EXPECT_EQ(medicines[0].getName(), "Aspirin");
    EXPECT_EQ(medicines[1].getName(), "Paracetamol");
}
