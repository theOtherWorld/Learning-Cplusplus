//
// Created by xl on 2017/8/24.
//

/**
 * 模板
 *  A template is a “pattern” that the compiler uses to generate a family of classes or functions
 * 且模板是一种编译时机制 并不会产生任何运行时开销
 */


#ifndef C_PROGRAMMING_LANGUAGE_TEMPLAT_H
#define C_PROGRAMMING_LANGUAGE_TEMPLAT_H


#include <iostream>
#include <stdexcept>

namespace tl {

    /**
     * 3.4.1 参数化类型
     */
    template<typename T>
    class Vector {
    private:
        T *elem;
        int sz;
    public:
        Vector(int);

        Vector(std::initializer_list<T>);

        ~Vector(){ delete[] elem; }

        // 移动和拷贝操作
        // .....

        T &operator[](int);

        int size() const{ return sz; }

        T* begin(){ return elem;} //为让我们的Vector支持范围for循环 需要为其定义适当的begin() 和 end() 函数
        T* end(){ return elem + sz;}

    };

    template<typename T>
    Vector<T>::Vector(int s) {
        if (s < 0) throw std::logic_error{"Negative Size in Vector(int)"};
        elem = new T[s];
        sz = s;
    }

    template<typename T>
    Vector<T>::Vector(std::initializer_list<T> lst) : elem{new T[lst.size()]}, sz{lst.size()} {
        std::copy(lst.begin(), lst.end(), elem);
    }

    template<typename T>
    T& Vector<T>::operator[](int i) {
        if (i < 0 || i > sz) throw std::out_of_range{"our of range in Vector[]!"};
        return elem[i];
    }


    /**
     * 函数模板
     */
    template<typename Container, typename Value>
    Value sum(Container &c, Value res) {
        for (auto e: c) {
            res += e;
        }
        return res;
    };


    /**
     * 函数对象
     */
    template<typename T>
    class Less_Than {
    private:
        const T val;
    public:
        Less_Than(T v) : val{v} {}

        bool operator()(const T &ct) { return ct < val; }
    };

    Less_Than<int> lti{10}; // lyi(10) 亦可
    bool b = lti(3);

    //这样的函数对象经常作为算法的实参出现 可称为谓词predicate
    template<typename T, typename P>
    int count(T& t, P pred) {
        int cnt = 0;
        for(auto& e:t){
            if(pred(e)) ++cnt;
        }
        return cnt;
    }

    // 还有一种隐式生成函数对象的方法:lambda表达式
    Vector<int> vi {1,2,3,4,5,6};
    Vector<int> vii {7,8,9,0,10};
    int cnt = count(vii,[&](int x){return x < 6;});
    int cnt_ = count(vi,Less_Than<int>{5});
    // 这里的 [&](int x){return x < 4;} 即lambda表达式 其生成一个函数表达式 就像Less_Than<int>{4}一样
    // [&] 是一个捕获列表(capture list) 它指明所用局部变量将通过引用访问 [&x] 表示只“捕获”x []什么也不捕获
    // [=] 捕获所有以值访问的局部变量


    /**
     * 可变参数 模板
     * 定义模板时可令其接受任意数量任意类型的实参
     */
    void printf(){return;} // 必须定义在printf(T t, Tail... tail) 之前

    template <typename T>
    void sub_printf(T t){std::cout<<t<<" ";}

     template <typename T, typename... Tail>
     void printf(T head, Tail... tail){
         sub_printf(head);
         printf(tail...);
     };


    /**
     * 别名
     */
    template <typename Key, typename Value>
    class Map{
    private:
        Key key;
        Value value;
    public:
        Map(Key k, Value v){ key = k; value = v; }
        Value operator[] (Key k){
            if (k != key) throw std::logic_error{"No Match value with key"};
            return value;
        }
        // ...
    };

    template <typename Value>
    using string_map = Map<std::string,Value>; // 别名
    string_map<int> m {"mike",30}, n {"bob", 23};

};

#endif //C_PROGRAMMING_LANGUAGE_TEMPLAT_H

