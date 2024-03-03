#include <division.h>
#include <gtest/gtest.h>


TEST(division, bothPositive) {
    int a = 30527235, b = 12342;
    EXPECT_EQ(divide(a, b), a/b);
    a = 2184;
    b = 985;
    EXPECT_EQ(divide(a, b), a/b);
    a = 452184;
    b = 123;
    EXPECT_EQ(divide(a, b), a/b);
    a = 2184;
    b = 352823;
    EXPECT_EQ(divide(a, b), a/b);
    a = 1238;
    b = 1;
    EXPECT_EQ(divide(a, b), a/b);
}

TEST(division, oneNegative) {
    int a = -30527235, b = 12342;
    EXPECT_EQ(divide(a, b), a/b);
    a = -2184;
    b = 985;
    EXPECT_EQ(divide(a, b), a/b);
    a = 2184;
    b = -123;
    EXPECT_EQ(divide(a, b), a/b);
    a = -2184;
    b = 352823;
    EXPECT_EQ(divide(a, b), a/b);
    a = 1238;
    b = -1;
    EXPECT_EQ(divide(a, b), a/b);
}

TEST(division, bothNegative) {
    int a = -30527235, b = -12342;
    EXPECT_EQ(divide(a, b), a/b);
    a = -2184;
    b = -985;
    EXPECT_EQ(divide(a, b), a/b);
    a = -2184;
    b = -123;
    EXPECT_EQ(divide(a, b), a/b);
    a = -2184;
    b = -352823;
    EXPECT_EQ(divide(a, b), a/b);
    a = -1238;
    b = -1;
    EXPECT_EQ(divide(a, b), a/b);
}
