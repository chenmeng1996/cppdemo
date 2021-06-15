//
// Created by admin on 2021/6/14.
//
#include <gtest/gtest.h>
#include "vector.h"

using namespace std;

class VectorTests : public ::testing::Test {

};


// 拷贝，移动
Vector<double> f() {
    Vector<double> x(100);
    Vector<double> y(100);
    Vector<double> z(100);
    z = x; // 拷贝
    y = std::move(x); // 移动
    return z; // 移动
}

TEST(VectorTests, test1) {

}