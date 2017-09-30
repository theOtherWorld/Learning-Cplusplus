//
// Created by xl on 2017/8/27.
//
/**
 * 小工具组件
 */


#ifndef C_PROGRAMMING_LANGUAGE_5_4_SMALLTOOL_H
#define C_PROGRAMMING_LANGUAGE_5_4_SMALLTOOL_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <utility>
#include <tuple>
#include <chrono> // 处理时间的标准库
#include <limits> // 数值限制
#include <iterator> //迭代器相关
using namespace std;

namespace st{


    /**
     * 时间
     */
    void time_func(){
        auto t0 = chrono::high_resolution_clock::now(); // 系统时钟返还一个time_point类型的值(时间点)
        // doSomething()
        auto t1 = chrono::high_resolution_clock::now();// 不同的时钟用得到的时间单位各有不同，这里得到的单位是nanoseconds
        cout<< chrono::duration_cast<chrono::milliseconds>(t1-t0).count()<<"msec"<<endl; // 两个时间点一减的结果是一个duration(时间段)
        // 而在实际使用中最好用duration_cast把duration 统一转换成一个公认单位
    }

    /**
     * 类型函数
     * 是指在编译时求值的函数，它接受一个类型作为实参或者返回一个类型作为结果
     */
    constexpr float f_min = numeric_limits<float>::min(); // numeric_limits<float>::min() 是一个constexpr函数
    constexpr int i_sz = sizeof(int);


    /**
     * iterator_traits
     * 检查当前容器支持哪种迭代器
     */
    // 标准库函数sort()接受一对迭代器(表示一个序列的两端)作为实参，这对迭代器必须提供对序列的随机访问
    // 故称随机访问迭代器(random-access-iterator) 但某些容器无法提供满足要求的迭代器，如forward_list(单链表)
    // 对其取下标操作代价很高，但和大多数容器一样，其提供了前向迭代器(forward iterator) 故可以遍历它
    // 现在让sort()同时支持vector 和 forward_list
    template <typename R>
    void sort_helper(R beg, R end, random_access_iterator_tag){// 对于random-access-iterator的情况可以通过下标运算符访问[beg,end)内元素
        std::sort(beg, end);
    }

    template <typename F>
    void sort_helper(F beg, F end, forward_iterator_tag){// 对于forward iterator的情况能够依次遍历[beg,end)内元素
        vector<decltype(*beg)> v {beg, end}; // 用[beg,end) 内元素初始化容器v decltype()是内置类型函数 返回其实参的已声明类型
        std::sort(v.begin(), v.end());
        copy(v.begin(), v.end(), beg);
    }

//    template <typename C>
//    using iter_type = typename C::iterator;

    template <typename Iter>
    using iter_category = typename iterator_traits<Iter>::iterator_category; // Iter的类别

    template <typename C>
    void sort(C& c){ // 这里使用了两个类型函数 iter_type<C>
        using iter = typename C::iterator; // C的迭代器类型
        sort_helper(c.begin(), c.end(), iter_category<iter>{}); // iter_category<iter>{}会生成一个标签值用以表示提供的是哪种迭代器
    }


    /**
     * 标准库类型谓词
     *它是一种简单的类型函数 负责回答一个关于类型的问题
     * is_pod is_literal_type is_base_of 等等均包含在<type_traits>头文件中
     */
    struct A{};
    constexpr bool b = is_arithmetic<int>();
    bool b2 = is_class<A>::value;
    bool b3 = has_virtual_destructor<A>{};

    // 还可以定义自己的类型函数
    template <typename T>
    constexpr bool can_arithmetic(){
        return is_arithmetic<T>::value;
    }

   // bool b4 = can_arithmetic<A>();


    /**
     * pair 和 tuple
     * 定义在<utility> 头文件中
     * 只要pair 和tuple的元素支持赋值和比较操作 我们就能对整个pair 和 tuple 赋值
     */
    pair<int, double> pp {99,23.6733};

    auto p = make_pair("hello",23);
    auto ss = p.first;
    auto ii = p.second;


    tuple<int,double,char> t(5,3.09807,'r'); // 类型参数必须与值参数在个数和类型方面相匹配
    int i = get<0>(t);
    double d = get<1>(t);
    auto a = make_tuple('i',"love",19,4.98);
    string s = get<1>(a);

    string sss = R"(\\fsdfs\'\nsda)";  // 这里sss是原始字符串(raw string) 即以R"()" 包含的字符串 好处是无需转义那些反斜杠和引号


};
#endif //C_PROGRAMMING_LANGUAGE_5_4_SMALLTOOL_H
