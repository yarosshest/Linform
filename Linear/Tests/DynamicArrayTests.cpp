//
// Created by yaros on 11.05.2021.
//

#include "gtest/gtest.h"
#include "../DynamicArray.h"

TEST(DynamicArray, CopyArray)
{
    float arr[3] = {5,2,3};
    DynamicArray<float> test(arr,3);
    ASSERT_EQ(test.GetLength(), 3);
    EXPECT_EQ(test[0], 5);
    EXPECT_EQ(test[1], 2);
    EXPECT_EQ(test[2], 3);
}

TEST(DynamicArray, newArrayLength)
{
    DynamicArray<float> test(5);
    ASSERT_EQ(test.GetLength(), 5);
}

TEST(DynamicArray, CopyConstruct)
{
    float arr[3] = {5,2,3};
    DynamicArray<float> test(arr,3);
    DynamicArray<float> copy(test);
    ASSERT_EQ(test.GetLength(), copy.GetLength());
    EXPECT_EQ(copy[0], 5);
    EXPECT_EQ(copy[1], 2);
    EXPECT_EQ(copy[2], 3);
}

TEST(DynamicArray, Get)
{
    float arr[5] = {5,6,4,45,0};
    DynamicArray<float> test(arr,5);
    EXPECT_EQ(test.GetI(3), 45);
}

TEST(DynamicArray, GetSize) {
    float arr[5] = {5,6,4,45,0};
    DynamicArray<float> test(arr,5);
    EXPECT_EQ(test.GetLength(), 5);
}

TEST(DynamicArray, Set) {
    float arr[5] = {5,6,4,45,0};
    DynamicArray<float> test(arr,5);
    test.Set(3,0);
    EXPECT_EQ(test.GetLength(), 5);
    EXPECT_EQ(test[3], 0);
}

TEST(DynamicArray, Resize) {
    DynamicArray<float> test(5);
    test.Resize(10);
    EXPECT_EQ(test.GetLength(), 10);
}
