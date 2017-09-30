//
// Created by xl on 2017/8/26.
//
/**
 * 算法
 */

#ifndef C_PROGRAMMING_LANGUAGE_4_5_ALGORTHM_H
#define C_PROGRAMMING_LANGUAGE_4_5_ALGORTHM_H

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <fstream>
#include <iterator>
using namespace std;
namespace al{
    /**
     * 使用迭代器
     */
    struct Book{
        string name;
        string isbn;
    };

    bool operator< (const Book& x, const Book& y){
        return x.name < y.name;
    }

    bool operator== (const Book& x, const Book& y){ // 原书里并没有==运算符这里需要加上这样sort()函数才能正确运行
        return x.name == y.name;
    }

    void cp(vector<Book>& vb, list<Book>& lb){ // 会覆盖旧元素
        sort(vb.begin(),vb.end()); // 用重载的 < 和 == 确定元素的序
        unique_copy(vb.begin(),vb.end(),lb.begin()); // 若vb中元素不止一个，则后续元素会覆盖lb中lb.begin()之后的元素
    }

    list<Book> cp(vector<Book>& vb){// 返回新元素
        list<Book> res;
        sort(vb.begin(),vb.end());
        unique_copy(vb.begin(),vb.end(),back_inserter(res));
        return res;
    }


    template <typename C, typename V>
    vector<typename C::iterator> find_all (C& c, V v){ // 在容器c中查找值v出现的所有位置

        // 这里typename C::iterator还可以采用别名方式
        vector<typename C::iterator> res; // 这里的typename必不可少 因为它通知编译器 C的iterator是一种类型而非某种类型的值
        for(auto p = c.begin(); p != c.end(); ++p){
            if(*p == v)
                res.push_back(p);
        }

        return res;
    };

    // 别名方式
//    template<typename T>
//    using iterator<T> = typename T::iterator;
//
//    template <typename C, typename V>
//    vector<iterator<C>> v_find_all(){
//        //...
//    };


    /**
     * 迭代器类型
     * 迭代器类型与某个特定容器类型相关，它保存一些必要信息以便对容器执行特定操作
     */


    /**
     * 流迭代器
     */

    // 为创建一个ostream_iterator对象，我们需要指出使用哪个流输出，以及输出的对象类型
    ostream_iterator<string> osi{cout}; // 将字符串写入cout流

    //必须指明使用哪个流作为输入流读取数据以及数据的类型
    istream_iterator<int> isi{cin}; // 这里使用cin做输入流 输入数据int类型
    // 为表示一个序列，需要一个表示输入结束的istream_iterator
    istream_iterator<int> iof{}; // 即默认的istream_iterator起到这样的作用

    int iter_func(){ // 从文件中读取数据，并对其值进行排序，去除重复值，然后存入另外一个文件中
        string from, to;
        cin>>from>>to; // 输入文件名

        from = "D:\\xl\\c++\\C++ Programming Language\\" + from;
        to = "D:\\xl\\c++\\C++ Programming Language\\" + to;

        ifstream ifs{from}; // 对应文件from的输入流
        ofstream ofs{to}; // 对应文件to的输出流

        // 这里用set既能保存不重复的值又能维护值的顺序
        set<string> vec_s{istream_iterator<string>{ifs},istream_iterator<string>{}}; //从输入流序列中读取数据至vec_s
        copy(vec_s.begin(),vec_s.end(),ostream_iterator<string>{ofs,"\n"}); // 拷贝到输出流对应的文件to中

        return !ifs.eof() || !ofs; // 返回流的错误状态
    }


    /**
     * 谓词
     * 同函数对象
     */


    /**
     * 算法概述
     * 以下b,e 均表示半开序列[b,e) 且均在 <algorthm>头文件 和 命名空间std 中
     *
     *  p = find(b,e,x)         p 为[b,e)中第一个满足*p ==x 的迭代器
     *  p = find_if(b,e,f)      p 为[b,e)中第一个满足f(*p) == true 的迭代器
     *  n = count(b,e,x)        n 为[b,e)中满足*p == true *p的数量
     *  n = count_if(b,e,x)     n 为[b,e)中满足f(*p) == true *p的数量
     *  replace(b,e,x,y)        将[b,e)中满足*p ==x 的元素替换为y
     *  replace_if(b,e,f,y)     将[b,e)中满足f(*p) ==true 的元素替换为y
     *  p = copy(b,e,out)       将[b,e)中拷贝到[out:p)中
     *  p = copy_if(b,e,out,f)  将[b,e)中f(*p) ==true 拷贝到[out:p)中
     *  p = unique_copy(b,e,out,f)  将[b,e)拷贝到[out:p)中,不拷贝重复元素
     *  sort(b,e)
     *  sort(b,e,f)
     *  p = merge(b,e,b2,e2,out) 将两个序列[b,e)，[b2,e2)合并到[out:p)中
     *  [p1,p2) = equal_range(b,e,v) [p1,p2)是一排序序列[b,e)的子序列，其值都等于v  本质上是二分查找v
     *
     */
};

#endif //C_PROGRAMMING_LANGUAGE_4_5_ALGORTHM_H
