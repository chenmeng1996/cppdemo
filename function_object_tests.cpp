//
// Created by admin on 2021/6/17.
//

#include <gtest/gtest.h>
#include "function_object.h"
#include "vector.h"

using namespace std;

class FunctionObjectTests : public ::testing::Test {

};

template<typename C, typename P>
int count(C& c, P pred) {
    int cnt = 0;
    for (const auto& x : c)
        if (pred(x))
            ++cnt;
    return cnt;
}

TEST(FunctionObjectTests, test1) {
    Less_than<int> lti {2};
    Less_than<string> lts {"ab"};

    cout << lti(1) << endl << lts("ac") << endl;

    Vector<int> vec = {1, 2, 3};
    cout << count(vec, Less_than<int>{3}) << endl;
    cout << count(vec, [&](int a){return a < 3;}) << endl; // lambda表达式，隐式生成函数对象
}