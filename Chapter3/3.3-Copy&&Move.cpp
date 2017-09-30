//
// Created by xl on 2017/8/18.
//

/**
 * 拷贝和移动
 */
#include "3.2-Class.h"
using namespace cl;
namespace cm {


    /**
     * 拷贝容器
     * 拷贝的默认含义是逐成员复制，然而 对于复杂的具体类和抽象类逐成员复制往往不正确
     * 类对象的拷贝操作通常可以通过两个成员来定义：拷贝构造函数和拷贝赋值运算符
     */

    void bad_copy(Vector v1){
        Vector v2 = v1; // 这里产生的一份拷贝v2中 elem所指向的元素与原来v1 elem所指元素是同一个 不符合逐成员复制的语义
        v1[0] = 1;      // 一般都会报编译警告
        v2[1] = 2;
    }



    class List{
    private:
        double* elem;
        int sz;
    public:
        List(const List& l): elem{new double[l.sz]},sz{l.sz}{for(int i = 0; i != sz; ++i) elem[i] = l.elem[i];}
        List&operator= (const List& l){ // 注意这里接受的实参是const ClassName&
            double*p = new double[l.sz];
            for(int i = 0; i != l.sz; ++i) p[i] = l.elem[i];
            delete[] elem;
            elem = p;
            sz = l.sz;
            return *this;
        }
    };
    
 
};