#include "medicine.h"
#include <gtest/gtest.h>

TEST(MedicineTest, ConstructorAndGetters) {
    Medicine med("Aspirin", 500, "Pharma Inc.");
    EXPECT_EQ(med.getName(), "Aspirin");
    EXPECT_DOUBLE_EQ(med.getDosage(), 500);
    EXPECT_EQ(med.getManufacturer(), "Pharma Inc.");
}

TEST(MedicineTest, Setters) {
    Medicine med("Aspirin", 500, "Pharma Inc.");
    med.setName("Paracetamol");
    med.setDosage(650);
    med.setManufacturer("HealthCorp");
    EXPECT_EQ(med.getName(), "Paracetamol");
    EXPECT_DOUBLE_EQ(med.getDosage(), 650);
    EXPECT_EQ(med.getManufacturer(), "HealthCorp");
}