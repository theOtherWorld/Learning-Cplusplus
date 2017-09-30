//
// Created by xl on 2017/9/2.
//

/**
 * 指针
 */

#ifndef C_PROGRAMMING_LANGUAGE_7_1_POINTER_H
#define C_PROGRAMMING_LANGUAGE_7_1_POINTER_H

#include <iostream>
using namespace std;
namespace p{

    char** p; // 指向字符指针的指针
    int (*fp)(char*); // 指向函数的指针 接受一个char* 作为实参

    /**
     *  void*
     *  指向 未知类型对象的指针
     *  除了函数指针和指向类成员的指针，其他任意类型的指针均可以赋给void* 指针
     *  void* 指针可以赋给另一个void* 指针 两个void* 能比较是否相等
     *  我们还能显示的把void* 转换成其他类型
     */
    void f(int* pi){
        void* pv = pi; //OK 发生了从int* 到void* 的隐式转换
        ++pv; // NO 不允许执行自增 因为对象类型未知

        int* pi2 = static_cast<int*>(pv); //OK 显示转回int*

        //double* pd = pv; NO 类型不匹配
       // double* pd2 = pi; NO
        double* pd2 = static_cast<double*>(pv); //OK 显示转换double* 不安全
    }
    // void* 最主要功能是当我们无法确定对象的类型时，向函数传递指向该对象的指针 或是从函数返回未知类型对象的指针



    /**
     * 数组
     */

    int a1[10]; //数组中的元素数量必须是常量表达式 在静态存储区
    void ff(){

        int a2[20]; //在栈区

        int* p = new int[30]; // 在自由存储区
        // delete[] p;
    }
    // c++没有为数组提供内置的拷贝操作 不能用一个数组初始化另一个数组
    // int a3[10] = a1;// NO
    // a3 = a1; //NO

    bool b = sizeof("bor") == 4;  //true 字符串字面值常量以多一个'\0'结尾  字符串字面值常量是若干const字符组成的数组
    void func(){
        char* p = "Hello"; // NO c++11之后不被允许 const char* 可以
        p[2] = 'w'; // NO 试图为常量赋值
        char c[] = "Hello";
        c[2] = 'w'; //OK
    }

    template <typename T>
    unsigned byte_diff(T* p, T*q){ // 等价于sizeof(T)
        return reinterpret_cast<char*>(q) - reinterpret_cast<char*>(p);
    }

//    void mij(int m[][], int dim1, int dim2{ // NO 实参声明为m[][] 这是非法的 N维数组必须已知它的N-1维
//
//    }
    //void mij(int* m, int dim1, int dim2){int index = i*dim2 +j;} // OK
    void mijk(int m[][3][2]){} //OK


    /**
     * 指针和const
     * 指针本身涉及到两个方面: 指针本身和指针所指的对象
     * 在声明语句中前置const 将令所指的对象而非指针本身成为常量
     * 要使指针本身成为常量 用 *const 代替*
     */
     void fun(char* p){


        char s[] = "Hello";
        const char* p1 = s; // 指向常量的指针
        // p1[2] = 'r'; NO p1指向常量
        p1 = p; // OK

        char *const p2 = s;// 指针常量
        p2[2] = 'i'; //OK
        // p2 = p; NO p2是一个常量

        const char *const p3 = s;
        // p3[2] = 'i';NO
       // p3 = p; NO

        int b = 2;
        const int a = 3; // 常量的地址不能赋给某个不受限的指针
         //int* p4 = &a; //Error
         // *p4 = 4; // Error
        const int* p5 = &b; //OK
    }



    /**
     * 引用
     */





}
#endif //C_PROGRAMMING_LANGUAGE_7_1_POINTER_H
