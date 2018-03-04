#include "pch.h"
#include "../List/List.h"

TEST(ListTest, defaultListConstructor) {
    List<int> list;
    ASSERT_EQ(list.size(), 0);
    EXPECT_NO_THROW(List<int> list);
    EXPECT_TRUE(list.empty());
}

TEST(ListTest, listFront) {
    List<int> list;
    list.push_back(10);
    ASSERT_EQ(list.size(), 1);
    EXPECT_EQ(list.front(), 10);
}

TEST(ListTest, listBack) {
    List<int> list;
    list.push_back(10);
    ASSERT_EQ(list.size(), 1);
    EXPECT_EQ(list.back(), 10);
}

TEST(ListTest, listFrontBack) {
    List<int> list;
    list.push_back(10);
    list.push_back(20);
    ASSERT_EQ(list.size(), 2);

    EXPECT_EQ(list.front(), 10);
    EXPECT_EQ(list.back(), 20);
}

TEST(ListTest, at) {
    List<int> list;
    ASSERT_EQ(list.size(), 0);
    EXPECT_ANY_THROW(list.at(0));

    list.push_back(10);
    list.push_back(20);
    ASSERT_EQ(list.size(), 2);

    EXPECT_EQ(list.at(0), 10);
    EXPECT_EQ(list.at(1), 20);
    EXPECT_ANY_THROW(list.at(2));
}

TEST(ListTest, operatorBracket) {
    List<int> list;
    ASSERT_EQ(list.size(), 0);
    EXPECT_ANY_THROW(list[0]);

    list.push_back(10);
    list.push_back(20);
    ASSERT_EQ(list.size(), 2);

    EXPECT_EQ(list[0], 10);
    EXPECT_EQ(list[1], 20);
    EXPECT_ANY_THROW(list[2]);
}

TEST(ListTest, iterators) {
    List<int> list;
    ASSERT_EQ(list.size(), 0);
    EXPECT_ANY_THROW(list.at(0));

    list.push_back(10);
    list.push_back(20);
    ASSERT_EQ(list.size(), 2);

    auto iter = list.begin();
    EXPECT_EQ(iter, list.begin());
    EXPECT_EQ(*iter++, 10);
    EXPECT_EQ(*iter++, 20);

    EXPECT_EQ(iter, list.end());
}