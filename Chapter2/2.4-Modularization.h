//
// Created by xl on 2017/8/14.
//

/**
 * 模块化
 */


namespace md {

/**
 * 声明指定了某个函数或是某个类型所需的全部内容
 */

    double sqrt(double);

    class Vector {
    public:
        Vector(int s);

        double &operator[](int i);

        int size();

    private:
        int sz;
        double *elem;
    };

/**
 * c++ 支持分离编译  声明放在头文件.h文件 定义则放置在分离的源文件.cpp文件
 */


/**
 * 有关异常处理
 */
    //throw length_errorr{};
    //static_assert(4 != sizeof(int), "size of int is 4"); // 静态断言 static_assert(A,S) A不为true时 S作为编译错误输出

};