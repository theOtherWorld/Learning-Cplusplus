//
// Created by xl on 2017/8/14.
//

/**
 * 用户自定义类型
 */


#include <iostream>
/**
 * c++抽象机制的目的让程序员
 设计并实现他们自己的数据类型
 */


namespace udt{

/**
 * 结构
 */
    struct vector{
        int sz;
        double* elem; // elem = new double[sz] new 操作符从名为自由存储(free store) 亦称堆(heap)获取内存分配
    };


/**
 * 把类型的接口与其实现分离开来 实现这样目的的语言机制称为类
 */


    class Vector{
    public: //公开接口
        Vector(int s): elem{new double[sz]},sz{s}{};//使用 成员初始化器列表 来初始化 类成员
        ~Vector(){delete[] elem;}; //归还 通过new 获取的自由存储空间
        double& operator[](int i){return elem[i];};
        int size(){return sz;};
    private:
        int sz;
        double* elem;
    };


/**
 * 强类型枚举
 */

    enum class Color {red, green, yellow}; // red green, yellow 称为枚举值 枚举值不会隐式地转换成其他类型
    enum class TrafficLight {red, green, yellow}; // 虽同有red 但两者所属作用域不同，代表的意义也不同
    Color c = Color::red;//OK
    TrafficLight tl = TrafficLight ::yellow; //OK
//Color cl = TrafficLight ::green; //NO
//int c = Color::green; //NO Color::green 不是一个int 类型的值

    enum Colour {red, green, yellow}; //他的枚举值名字与枚举值本身位于同一作用域 枚举值会隐式地转换成整型
// int cc = Colour::yellow; // cc = 2

// 带class 的enum 可以定义自己的运算符 T& operator op(para...){}
};

