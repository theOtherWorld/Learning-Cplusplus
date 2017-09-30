//
// Created by xl on 2017/9/3.
//

#ifndef C_PROGRAMMING_LANGUAGE_16_2_INTRODUCTIONOFCLASS_H
#define C_PROGRAMMING_LANGUAGE_16_2_INTRODUCTIONOFCLASS_H

#include <iostream>
#include <string>
using namespace std;

namespace ioc{

    /**
     * explict 构造函数
     */
    // 默认情况下 用一个单一参数调用构造函数 其行为类似于从该参数类型到类类型的隐式转换
    // complex<int> c {1}; c==1+0i
    //但这有时也会带来含混 故我们可以使用explict 关键字指明该构造函数不能做隐式类型转换 只能初始化和显示类型转换
    // 省略 = 会将初始化变为显示的初始化
    class Date{
        int d,m,y;
    public:
        explicit Date(int);
        Date(int _d, int _m, int _y){d=_d; m = _m; y = _y;}
    };
    Date::Date(int _d) {d = _d;} // 类外定义不需要再加上explict

    Date d {15}; // OK 被看作显示转换
    Date d2 = Date{16}; // OK 显示类型转换
    // Date d3 = {17}; // Error 隐式类型转换
    Date d4 = {15,9,2017}; // OK 隐式类型转换


    /**
     * 类内函数
     * 如果一个类的成员函数不仅在在类中声明还在类中定义
     * 那么它被当作内联函数处理
     */


    /**
     * 逻辑常量性
     * 有时一个成员函数逻辑上是const的，但它仍需要改变成员的值
     * 即函数看起来不会改变其对象的状态，但它更新了用户不能直接观察的某些细节
     */
     // 我们可以将类成员定义为mutable表示即使在const对象中也可以改变它
    class Date_1{
    public:
        string str_rep() const;

    private:
        mutable bool cache_valid;
        mutable string cache;
        void compute_cache() const;
    };

    string Date_1::str_rep() const {
        if(!cache_valid){
            compute_cache();
            cache_valid = true;
        }
        return cache;
    }
    void Date_1::compute_cache() const {
        string tmp = "Sep 4th 2017";
        cache = tmp;
    }

    // 或者 将需要改变的数据放在一个单独的对象中，间接地访问它 以实现可变性
    struct cache{
        bool cache_valid;
        string _cache;
    };

    class Date_2{
    private:
        cache* c;
        void compute_cache() const;

    public:
        string str_rep() const;
    };

    string Date_2::str_rep() const {
        if(!c->cache_valid){
            compute_cache();
            c->cache_valid = true;
        }
        return c->_cache;
    }
    void Date_2::compute_cache() const {
        c->_cache = "hello world!";
    }


    /**
     * 自引用
     */


    bool leap_year(int y){
        if(y % 4 == 0) {
            if(y % 100 == 0){
                if(y % 400 == 0)
                    return true;
                else
                    return false;
            } else
                return true;
        } else
            return false;
    }

    class Date_3{
        int d,m,y;
    public:
        Date_3& add_year(int);
    };

    Date_3& Date_3::add_year(int _y) {
        if(d == 29 && m == 2 && leap_year(y+_y)){
            d = 1;
            m = 3;
        }
        y += _y;
        return *this;
    }
    // 在类的非static成员函数中，关键字this是指向调用该函数的对象的指针，但是this被看作是一个右值
    // 因此我们无法获取this的地址或是给它赋值 在const成员函数中,this的类型是 const X* 非const成员函数中
    // this的类型是 X*   this的使用大多数是隐式的


    /**
     * 成员类型
     */

    // 类型和类型别名也可以作为类的成员

    template <typename T>
    class Tree{
        using value_type = T; // 类型别名
        class Node{
            Node* right;
            Node* left;
            value_type value;
        public:
            void f(Tree*);
        };
        Node* top;
    public:
        void g(Tree::Node*);

    };
    // 成员类 又称嵌套类 成员类可以访问其所属类的成员(包括private),但它没有当前类的概念
    template <typename T>
    void Tree<T>::Node::f(Tree<T>* t){
        // top = right; Error! 没有指定Tree类型的对象
        t->top = right; // OK
        value_type v = left->value; // OK
    }
    // 相反 一个类并没有权限访问其成员类的private成员
    template <typename T>
    void Tree<T>::g(Tree<T>::Node* p) {
        // value_type v = left->value; Error!
        //   value_type v2 = p->left->value;Error!
        p->f(this); // OK
    }


}
#endif //C_PROGRAMMING_LANGUAGE_16_2_INTRODUCTIONOFCLASS_H
