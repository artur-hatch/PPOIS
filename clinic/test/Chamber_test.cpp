#include <gtest/gtest.h>
#include "../include/Chamber.h"

// Тест конструктора по умолчанию
TEST(UnitTest, DefaultConstructor) {
    Unit unit;
    EXPECT_EQ(unit.getCapacity(), 0);
    ASSERT_NE(unit.getGenderCategory(), nullptr);
}


// Тест установки и получения вместимости
TEST(UnitTest, SetAndGetCapacity) {
    Unit unit;
    unit.setCapacity(10);
    EXPECT_EQ(unit.getCapacity(), 10);
}

// Тест удаления жильца
TEST(UnitTest, RemoveResident) {
    Identity gender("Male");
    Unit unit("Male", 2);

    Client client1;
    client1.getIdCard()->setGender(gender);

    unit.addResident(&client1);
    unit.removeResident(&client1);
    EXPECT_FALSE(unit.hasResident(&client1));
}

