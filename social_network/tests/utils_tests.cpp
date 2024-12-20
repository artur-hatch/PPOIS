#include <gtest/gtest.h>
#include "../src/utils/utils.hpp"

class UtilsTest : public ::testing::Test {
protected:
    Utils utils;
};

TEST_F(UtilsTest, GetTimeNow) {
    std::string currentTime = utils.GetTimeNow();
    EXPECT_TRUE(currentTime.find(':') != std::string::npos);
    EXPECT_TRUE(currentTime.find('.') != std::string::npos);
}

TEST_F(UtilsTest, GenerateId) {
    std::string id1 = "test1";
    std::string id2 = "test2";
    std::string id3 = "test1";
    std::string id4 = "test2";

    std::string generatedId1 = utils.GenerateId(id1, id2);
    std::string generatedId2 = utils.GenerateId(id3, id4);
    
    EXPECT_EQ(generatedId1, generatedId2);
    
    std::string id5 = "different";
    std::string generatedId3 = utils.GenerateId(id1, id5);
    EXPECT_NE(generatedId1, generatedId3);
}

TEST_F(UtilsTest, SafeStringToInt) {
    EXPECT_EQ(utils.SafeStringToInt("123"), 123);
    EXPECT_EQ(utils.SafeStringToInt("abc"), -1);
    EXPECT_EQ(utils.SafeStringToInt("123abc"), -1);
    EXPECT_EQ(utils.SafeStringToInt(""), -1);
}
