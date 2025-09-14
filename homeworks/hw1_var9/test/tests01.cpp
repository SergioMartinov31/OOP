#include <gtest/gtest.h>
#include "../include/allNumbers.h"

TEST(test_allNumbers, single_numbers) {
    ASSERT_EQ(allNumbers("abc123def"), "123");
    ASSERT_EQ(allNumbers("1a2b3c"), "1 2 3");
}

TEST(test_allNumbers, multiple_numbers_together) {
    ASSERT_EQ(allNumbers("12abc34def56"), "12 34 56");
    ASSERT_EQ(allNumbers("007bond008"), "007 008");
}

TEST(test_allNumbers, no_numbers) {
    ASSERT_EQ(allNumbers("abcdef"), "");
    ASSERT_EQ(allNumbers(""), "");
}

TEST(test_allNumbers, numbers_with_spaces_and_symbols) {
    ASSERT_EQ(allNumbers("a1! b2@ c3#"), "1 2 3");
    ASSERT_EQ(allNumbers("0-1+2=3"), "0 1 2 3");
}

TEST(test_allNumbers, leading_trailing_numbers) {
    ASSERT_EQ(allNumbers("123abc"), "123");
    ASSERT_EQ(allNumbers("abc456"), "456");
    ASSERT_EQ(allNumbers("789"), "789");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
