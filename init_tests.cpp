//
// Created by admin on 2021/6/12.
//

#include <gtest/gtest.h>
using namespace std;

class InitTests : public ::testing::Test {

};

// 几种初始化的形式
TEST(InitTests, test1) {
    int i1 = 1;
    int i2 {1}; // 避免隐式转换

    int i3 = 1.1; // 发生隐式转换：double到int
//    int i4 {1.1}; // 错误，double不能分配给int

    // 自动类型推断，不用显示指定类型。不会隐式转换。 c++推荐
    auto i5 = 1;
    auto d1 = 1.1;
}


TEST(InitTests, test2) {
    // 声明数组
    int v1[6];
    // 声明并初始化数组
    int v2[6] {0, 1, 2, 3, 4, 5};
    // 初始化数组时，数组长度可忽略
    int v3[] {0, 1, 2};
    // 遍历数组
    for (auto x : v3) {
        cout << x << endl;
    }
    // 遍历数组，x是引用，直接操作数组元素，不发生拷贝
    for (auto& x : v3) {
        ++x;
    }

    // 指针指向数组元素
    int* p = &v3[1];
    // 指针指向下一个数组元素
    p++;
    // 引用指向数组元素
    int& r = v3[1];
    std::vector<double> x = {1, 2};
}