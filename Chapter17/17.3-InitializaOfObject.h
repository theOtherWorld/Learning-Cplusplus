//
// Created by xl on 2017/9/9.
//

#ifndef C_PROGRAMMING_LANGUAGE_17_3_INITIALIZAOFOBJECT_H
#define C_PROGRAMMING_LANGUAGE_17_3_INITIALIZAOFOBJECT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace ioo{
    /**
     * 不使用构造函数初始化
     */
    // 我么们可以使用如下方法初始化一个没有构造函数的类的对象
    // 1.逐成员初始化 2.拷贝初始化 3.默认初始化(不用初始化器  或  空初始化列表)
    struct Work{
        string name;
        string addr;
        int year;
    };

    Work w {"Alan Turing","Street 10, Nanjing Road",3}; //逐成员初始化
    Work wc(w); // 拷贝初始化
    Work none {}; //默认初始化

    //用{}进行默认初始化的效果是用{}对每个成员进行初始化


    // 如果没有声明可接受参数的构造函数，我们也可以完全省去初始化器
    // 对于静态分配的对象，这种初始化方式与使用{}一样
    // 而对于局部变量和自由存储分配对象，只对类类型的成员进行默认初始化，内置类型成员不进行初始化
    Work w1; // 值为{“”，“”，0}

    void f(){

        Work beta; //beta值为{"","",unknown} 若希望初始化或不希望意外发生，则可以提供一个初始化器，如{}
        return;
    }


    /**
     * 使用构造函数进行初始化
     */
    // 我们为类声明各式各样的构造函数，当我们创建对象时没有提供构造函数所要求的恰当的初始化器，就会导致错误
    // 当定义一个接受参数的构造函数时默认构造函数就不存在了
    struct X{
        int x;
        X(int _x){x = _x;};
    };
    // X x1; Error! 没有初始化器
    // X x2 {}; Error 空初始化器
    X x3{2};// OK
    // X x4 {"yes"};Error 错误的初始化器类型
    // X x5 {1,2}; Error 初始化器数目不对

    // 只要是在创建对象的地方，我们都可以用{}初始化语法为构造函数提供参数，故{}初始化又称通用初始化，即可以在任何地方使用
    // 相反，= 和 ()初始化语法不是通用的。注意：{}初始化语法不允许窄化转换
    vector<int> v1{10}; // 用值10初始化一个元素
    vector<int> v2(10); // 将10个元素初始化为0
    vector<string> vs1 {"hello"}; // 用值"hello"初始化一个元素
    vector<string> vs2(10); // 将10个元素初始化为""
    // vector<string> vs3("world"); // Error 没有构造函数接受单一字符串


    /**
     * 默认构造函数
     * 无参数的构造函数被称为默认构造函数。如果一个接受参数的构造函数使用了默认构造函数
     * 则也可能称为默认构造函数
     */
    class Y{
        Y(const char* p = ""){} // 默认构造函数:空字符串
        // ..
    };


    /**
     * 初始化器列表构造函数
     * 接受单一std::initializer_list参数的构造函数
     */
    // 具体规则：
    // 1.若默认构造函数和初始化器列表构造函数都匹配，则优先选用默认构造函数
    // 2.若初始化器列表构造函数和一个普通构造函数都匹配，则优先选择初始化器列表构造函数
    // 若我们真想调用一个或多个参数的构造函数则必须使用()语法

    // std::initializer_list的元素是不可变的, 且不能对其使用移动构造函数
    void ff(initializer_list<int> l, int val){
          //  *l.begin() = val; //Error
        //...
    }


}
#endif //C_PROGRAMMING_LANGUAGE_17_3_INITIALIZAOFOBJECT_H
