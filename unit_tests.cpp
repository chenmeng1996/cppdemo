//
// Created by 陈濛 on 2021/4/20.
//

#include <gtest/gtest.h>
#include "demo.h"

class DemoTests : public ::testing::Test {

};

TEST_F(DemoTests, test1) {
    auto s = returnHello();
    std::cout << s << std::endl;
    EXPECT_EQ(s, "hello");
}