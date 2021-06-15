//
// Created by 陈濛 on 2021/4/20.
//

#include <gtest/gtest.h>
#include "demo.h"
#include "base.h"
using namespace std;

class BaseTests : public ::testing::Test {

};

TEST_F(BaseTests, fortest) {
    int v[] = {0, 1, 2, 3};
    for (auto x : v) {
        cout << x << "\n";
    }
    for (auto& x : v) {
        cout << x << "\t" << &x << "\n";
    }

    for (auto i = 0; i < 4; i++) {
        int* s = &v[i];
        cout << s << "\t" << *s << "\n";
    }
    for (auto i = 0; i < 4; i++) {
        int* s = &v[i];
        cout << s << "\t" << *s << "\n";
    }
}

TEST_F(BaseTests, fortest1) {
    int v[] = {0, 1, 2, 3};
    for (auto i = 0; i < sizeof (v) / sizeof (v[0]); i++) {
        cout << &v[i] << "\t" << v[i] << "\n";
    }
}

TEST_F(BaseTests, fortest2) {
    int v[] = {0, 1, 2, 3};

    for (auto i = 0; i < 4; i++) {
        int* s = &v[i];
        cout << s << "\t" << *s << "\n";
    }
    for (auto i = 0; i < 4; i++) {
        int& s = v[i];
        cout << s << "\t" << &s << "\n";
    }
    for (auto i = 0; i < 4; i++) {
        int s = v[i];
        cout << &s << "\t" << s << "\n";
    }
}

TEST_F(BaseTests, fortest3) {
    auto a = new int(1);
    auto b = 1;
    cout << a << "\t" << b;

    char* c = "123";
}

TEST_F(BaseTests, enum1) {
    Traffic_light l = Traffic_light::red;
    Traffic_light next = ++l;
}