//
// Created by yaros on 11.05.2021.
//

#include "gtest/gtest.h"
#include "../LinkedList.h"
TEST(LinkedList, CopyArray)
{
    float arr[3] = {5,2,3};
    LinkedList<float> test(arr,3);
    ASSERT_EQ(test.GetLength(), 3);
    EXPECT_EQ(test[0], 5);
    EXPECT_EQ(test[1], 2);
    EXPECT_EQ(test[2], 3);
}

TEST(LinkedList, newEpty)
{
    LinkedList<float> test =LinkedList<float>();
    ASSERT_EQ(test.GetLength(), 0);
}



TEST(LinkedList, GetFirst)
{
    float arr[3] = {5,2,3};
    LinkedList<float> test(arr,3);
    ASSERT_EQ(test.GetFirst(), 5);
}

TEST(LinkedList, GetLast)
{
    float arr[5] = {5,6,4,45,0};
    LinkedList<float> test(arr,5);
    EXPECT_EQ(test.GetLast(), 0);
}

TEST(LinkedList, Get) {
    float arr[5] = {5,6,4,45,0};
    LinkedList<float> test(arr,5);
    EXPECT_EQ(test.GetI(0), 5);
}

TEST(LinkedList, LinkedList) {
    float arr[5] = {5,6,4,45,0};
    LinkedList<float> test(arr,5);
    test.Set(3,0);
    EXPECT_EQ(test.GetLength(), 5);
}

TEST(LinkedList, Append) {
    float arr[5] = {5,6,4,45,0};
    LinkedList<float> test(arr,5);
    test.Append(10);
    EXPECT_EQ(test.GetLength(), 6);
    EXPECT_EQ(test.GetLast(), 10);
}

TEST(LinkedList, Prepend) {
    float arr[5] = {5,6,4,45,0};
    LinkedList<float> test(arr,5);
    test.Prepend(10);
    EXPECT_EQ(test.GetLength(), 6);
    EXPECT_EQ(test.GetFirst(), 10);
}