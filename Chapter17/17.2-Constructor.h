//
// Created by xl on 2017/9/6.
//

/**
 *构造函数与析构函数
 */

#ifndef C_PROGRAMMING_LANGUAGE_17_2_CONSTRUCTOR_H
#define C_PROGRAMMING_LANGUAGE_17_2_CONSTRUCTOR_H

#include <iostream>
#include <stdexcept>
using namespace std;

namespace cd{

    /**
     * 一个类所需的完整函数
     * 除了普通构造函数，其余特殊函数都可以由编译器自动生成
     */
    template <typename T>
    class X{
    public:
        X(T t); // 普通构造函数
        //....
        X(); // 默认构造函数
        X(const X&); // 拷贝构造函数
        X(X&&); // 移动构造函数
        X&operator=(const X&); // 拷贝赋值运算符: 清理目标对象并进行拷贝
        X&operator=(X&&); // 移动赋值运算符:清理目标对象并进行移动
        ~X(); // 析构函数:清理

    };

    /**
     * 构造函数与不变式
     * 构造函数就是初始化一个类的对象，而初始化操作必须建立一个类不变式(class invariant)
     * 所谓不变式就是成员函数被调用时必须保持的某些东西
     * 如果类构造函数创建类不变式失败则不应创建对象且必须确保没有资源泄露
     */
    template <typename T>
     class Vec{
     public:
         Vec(int size){
             if(size < 0) throw bad_alloc{};
             elem = new T[size]; // 如果new操作未获取足够内存则会抛出一个std::bad_alloc异常
             sz = size;
         }

     private:
         T* elem;
         int sz;
     };
    // 这里的不变式: elem指向一个保数组，数组保存sz个T类型的数值;以及sz非负.构造函数必须保证这两点为真


    /**
     * 析构函数
     * 当一个对象离开所在作用于或者通过delete运算符操作，析构函数会被隐式调用，只有极少数情况会被显式调用
     * 如果程序员为一个类声明的析构函数，那么他必须还要决定类对象是否可以拷贝或移动
     */



    /**
     * 基类和成员析构函数
     * 构造函数会"自顶向下"地创建一个类对象
     *  [1] 首先调用其基类的构造函数
     *  [2] 然后调用其成员的构造函数
     *  [3] 最后执行其自身的函数体
     *析构函数则会按相反顺序来执行
     *  [1] 首先执行自身的函数体
     *  [2] 然后调用其成员的析构函数
     *  [3] 最后调用其基类的析构函数
     */
    struct S1{ // 如果需要初始化器，则可以使用逐成员初始化
        int x;
        // S1(){};
        S1(int _x){x = _x;};
    };

    struct S2{
        S1 s;
    };

    S2 ss {1}; // OK ss.s用 1初始化
    // S2 sss; // Error 没有为sss.s 提供初始化值，除非S1显式定义了默认构造函数S1(){};
    int xx = ss.s.x;


    /**
     * virtual析构函数
     * 之所以需要一个virtual析构函数是因为，如果通过基类的接口来操作一个对象，那么也应该通过该接口delete它
     */
    class Shape{
    public:
        Shape(){};
        virtual void draw() = 0;
        virtual ~Shape(){};
    };

    class Circle: public Shape{
        void draw(){cout<<"Circle draw!!";};
        ~Circle(){cout<<"Circle 虚构函数";};
    };
    // 如果这里Shape的析构函数不是virtual的，则delete在这尝试调用恰当的派生类的析构函数~Circle()时就会失败
    // 这样就会导致资源泄露
    void use(Shape* p){
        p->draw(); // 调用恰当的draw();
        //...

        delete p; // 调用恰当的析构函数
    }

}
#endif //C_PROGRAMMING_LANGUAGE_17_2_CONSTRUCTOR_H
