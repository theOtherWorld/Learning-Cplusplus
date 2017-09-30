//
// Created by xl on 2017/8/14.
//

/**
 * 基本概念
 */


#include <iostream>

namespace fc{
    int i1 =1; // Ok
    int i2 = 1.99; // OK 但是i2 = 1 有截断
    int i3 {2}; // OK
    //int i4 {2.99}; //NO 试图将浮点型转换为整型错误


    auto a = true;
    auto b = 4.99; // 变量的类型可由初始化器推断得到，无需显示声明类型 这一点在泛型编程中很重要


    constexpr double ced = 1.99;
    const double cd = 2.99;
    double d = 3.99;
    constexpr double ff(double x) {return x*x;}; // 函数定义为constexpr类型 常量表达式
    constexpr double var1 = ff(ced); //OK
   // constexpr double var2 = ff(cd); //NO 在常量表达式中cd（d） 也必须为constexpr类型
    double var3 = ff(d); //OK d(cd)  函数ff() 根据具体语境不同(一次用于常量表达式，一个用于变量) 具有不同作用


    void print() {
        int v[6] {0,1,2,3,4,5};
        for(auto x : v) { // 将v中的元素的值拷贝到x中
           std::cout<< x << std::endl;
        }
    };

    void incr() {
        int v[6] {0,1,2,3,4,5};
        for(auto& x : v) { // 此时x指向v中的一个元素
            std::cout<< x<< " ";
        }
    };

    char* p = nullptr; //nullptr 表示没有对象可指 可用于初始化

};

//using namespace fc;

/*int main() {
    print();
    std::cout<<var1<<var3<<std::endl;
    return 0;
}*/
