//
// Created by yaros on 11.05.2021.
//

#include "gtest/gtest.h"
#include "../Linear.h"

TEST(Linear, sum) {
    Linear<float> Lin1 = {1, 2, 3};
    Linear<float> Lin2 = {1, 2, 3, 10};
    Linear<float> Lin3;
    Lin3 = Lin1 + Lin2;
    ASSERT_EQ(Lin3.GetDimension(), 4);
    EXPECT_EQ(Lin3[0], 2);
    EXPECT_EQ(Lin3[1], 4);
    EXPECT_EQ(Lin3[2], 6);
    EXPECT_EQ(Lin3[3], 10);
}

TEST(Linear, Subt) {
    Linear<float> Lin1 = {1, 2, 3, 10};
    Linear<float> Lin2 = {-1, 2, 4};
    Linear<float> Lin3;
    Lin3 = Lin1 - Lin2;
    ASSERT_EQ(Lin3.GetDimension(), 4);
    EXPECT_EQ(Lin3[0], 2);
    EXPECT_EQ(Lin3[1], 0);
    EXPECT_EQ(Lin3[2], -1);
    EXPECT_EQ(Lin3[3], 10);
}

TEST(Linear, mult) {
    Linear<float> Lin1 = {1, 2, 3};
    float a = 3;
    Linear<float> Lin3;
    Lin3 = Lin1 * a;
    ASSERT_EQ(Lin3.GetDimension(), 3);
    EXPECT_EQ(Lin3[0], 3);
    EXPECT_EQ(Lin3[1], 6);
    EXPECT_EQ(Lin3[2], 9);
}

TEST(Linear, Calc) {
    Linear<float> Lin1 = {1, 2, 3, 10};
    float arr[3] = {5,2,3};
    DynamicArray<float> arrOtv(arr,3);
    float ot = Lin1.calc(arrOtv);
    ASSERT_EQ(ot, 47);
}