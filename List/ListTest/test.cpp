#include "pch.h"
#include "../List/List.h"

TEST(ListTest, defaultListConstructor) {
    List<int> list;
    EXPECT_NO_THROW(List<int> list);
}

TEST(ListTest, insertfromBack) {
    List<int> list;
    EXPECT_NO_THROW(list.insertToTail(10));
    EXPECT_NO_THROW(list.insertToTail(20));
}