//
// Created by 陈濛 on 2021/4/20.
//

#ifndef C__DEMO_BASE_H
#define C__DEMO_BASE_H
#include <iostream>
using namespace std;

class base {

};


#endif //C__DEMO_BASE_H


class Vector {
public:
    Vector(int sz) : elem{new double[sz]}, sz{sz} {}
    double& operator[](int i) {return elem[i];} // 通过下标访问元素
    int size() {return sz;}
private:
    double* elem;
    int sz;
};

enum class Traffic_light {green, yellow, red};
Traffic_light& operator++(Traffic_light& t) { // 前置运算符
    switch (t) {
        case Traffic_light::green:
            return t=Traffic_light::yellow;
        case Traffic_light::yellow:
            return t=Traffic_light::red;
        case Traffic_light::red:
            return t=Traffic_light::green;
    }
}