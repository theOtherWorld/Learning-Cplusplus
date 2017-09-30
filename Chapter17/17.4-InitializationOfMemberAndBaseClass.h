//
// Created by xl on 2017/9/12.
//

#ifndef C_PROGRAMMING_LANGUAGE_17_4_INITIALIZATIONOFMEMBERANDBASECLASS_H
#define C_PROGRAMMING_LANGUAGE_17_4_INITIALIZATIONOFMEMBERANDBASECLASS_H

#include<iostream>
#include <string>
#include <vector>

using namespace std;
namespace imb{

    /**
     * 成员初始化
     */
    // 成员的构造函数按成员在类中的声明顺序依次执行，而不是按成员在初始化器列表的出现顺序
    // 引用成员和const 成员必须初始化，虽然可以使用赋值初始化，但更倾向于使用初始化器
    class X{
        string name;
        const int number;
        vector<string>& addr;
    public:
        X(string n, int num, vector<string>& _addr):name{n},number{num},addr{_addr} {
            /* addr = _addr; */ // 这里addr首先被初始化为一个空向量 然后被赋值_addr
        }
    };

    /**
    * 委托构造函数(转发构造函数)
    */
    class Z{
        int a;
        void validate(int n){if(n > 0) a = n; else clog<<"bad para n in call validate(int n)";}

    public:
        Z(int x){validate(x);}
        Z(){validate(40);}

    };
    // 上述代码的另一种替代方案是用一个构造函数定义另一个
    // 即，使用一个成员风格的初始化器，但用的是类自身的名字，它会调用另一个构造函数-
    //-作为这个构造过程的一部风
    class ZZ{
        int a;
    public:
        ZZ(int x) {if(x > 0) a = x; else clog<<"bad para x < 0 in call ZZ(int x)";}
        ZZ():ZZ{40}{}
        // ZZ():ZZ{40},a{40}{} //Error 你不能同时显示初始化和委托初始化一个成员
        // 在构造函数体中显示调用其它构造函数可能会带来错误
        // ZZ(){ZZ{40}} //Error ZZ{40}创建一个无名临时对象
    };


    /**
     * 我们可以在类声明中为非static数据成员指定初始化器
     */
    class Y{
    public:
        Y(){}
        Y(int _i):i{_i} {}
        Y(string _s):s{_s} {}

    private:
        int i {5};
        string s {"hello"};
        string state{"constructor running!"};
    };

    /**
     *static成员初始化
     */
    // static声明充当类外定义的声明
    class Node{
    private:
        static int count;
    };
    int Node::count = 10;
}
#endif //C_PROGRAMMING_LANGUAGE_17_4_INITIALIZATIONOFMEMBERANDBASECLASS_H
