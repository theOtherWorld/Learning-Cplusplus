//
// Created by xl on 2017/9/2.
//

#ifndef C_PROGRAMMING_LANGUAGE_5_6_MATHCOMPUTING_H
#define C_PROGRAMMING_LANGUAGE_5_6_MATHCOMPUTING_H

#include <iostream>
#include <random>
#include <cmath>
#include <functional> // bind() 函数定义处

using namespace std;

namespace mc{
    /**
     * 随机数
     * 定义在头文件<random>中
     * 随机数生成器包含两部分:
     *    [1]: 一个引擎(engine) 负责生成一组随机值或伪随机值
     *    [2]: 一个分布(distribution) 负责把引擎产生的值映射到某个数学分布上
     * 常用分布包括: uniform_int_distribution(生成所有整数概率相等) normal_distribution(正态分布)
     *             exponential_distribution(指数分布)
     */
    // 标准库函数bind()生成一个函数对像,它会把第二个参数作为实参绑定到第一个参数的调用中
    // using my_engine = default_random_engine;
    // using my_distribution = uniform_int_distribution<>;
    // my_engine en {};
    // my_distribution one2six {1,6}
    // auto die = bind(one2six,en)
    //调用 die() 等价于调用 one2six(re)
    auto throwing = bind(normal_distribution<>{1,100}, default_random_engine{});
    auto x = throwing();

    class Rnd_int{ // 函数对象
    private:
        uniform_int_distribution<> dist;
        default_random_engine en{};
    public:
        Rnd_int(int low, int high): dist{low,high} {}
        int operator() (){ return dist(en);}
    };

    Rnd_int rnd_int {0,6};
    auto y = rnd_int();

};
#endif //C_PROGRAMMING_LANGUAGE_5_6_MATHCOMPUTING_H
