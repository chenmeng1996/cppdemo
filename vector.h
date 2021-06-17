//
// Created by admin on 2021/6/14.
//

#ifndef C__DEMO_VECTOR_H
#define C__DEMO_VECTOR_H

#endif //C__DEMO_VECTOR_H
using namespace std;

template<typename T>
class Vector {
private:
    T* elem;
    size_t sz;
public:
    Vector(size_t s) : elem{new T[s]},sz{s} { // 构造函数：请求资源
    }
    Vector(initializer_list<T> lst); // 构造函数：初始化器列表
    Vector(const Vector<T>& a); // 拷贝构造函数
    Vector(Vector<T>&& a); // 移动构造函数

    Vector<T>& operator=(const Vector<T>& a); // 拷贝赋值运算符
    Vector<T>& operator=(Vector<T>&& a); // 移动赋值运算符
    const T& operator[](int i) const; // 返回指定下标元素

    // 实现迭代器遍历
    T * begin();
    T* end();
    int size();

    ~Vector() { // 析构函数：释放资源
        delete[] elem;
    }
};

template<typename T>
Vector<T>::Vector(initializer_list<T> lst): elem{new T[lst.size()]},sz{lst.size()} {
    copy(lst.begin(), lst.end(), elem); // 从lst复制内容到elem
}

template<typename T>
Vector<T>::Vector(const Vector<T> &a) :elem{new T[a.sz]}, sz{a.sz} {
    for (int i=0; i<sz; i++)
        elem[i] = a.elem[i];
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& a) {
    T* p = new T[a.sz];
    for (int i=0; i<a.sz; i++)
        p[i] = a.elem[i];
    delete[] elem; // 释放旧数组的内存
    elem = p;
    sz = a.sz;
    return *this;
}

template<typename T>
Vector<T>::Vector(Vector<T>&& a) :elem{a.elem},sz{a.sz} {
    a.elem = nullptr; // 现在a没有元素了
    a.sz = 0;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& a) {
    delete[] elem;
    elem = a.elem;
    sz = a.sz;
    a.elem = nullptr;
    a.sz = 0;
    return *this;
}

template<typename T>
const T &Vector<T>::operator[](int i) const {
    if (i<0 || sz<=i)
        throw out_of_range("Vector::operator[]");
    return elem[i];
}

template<typename T>
T * Vector<T>::begin() {
    return &elem[0];
}

template<typename T>
T* Vector<T>::end() {
    return begin() + size();
}

template<typename T>
int Vector<T>::size() {
    return sz;
}