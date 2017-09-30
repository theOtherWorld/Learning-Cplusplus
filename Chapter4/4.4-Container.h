//
// Created by xl on 2017/8/25.
//

/**
 * 容器
 */

#ifndef C_PROGRAMMING_LANGUAGE_4_3_CONTAINER_H
#define C_PROGRAMMING_LANGUAGE_4_3_CONTAINER_H


#include "4.3-IOStream.h"
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

using  namespace i_o_s;
namespace ct{

    /**
     * vector
     * 其元素在内存中是连续存放的
     */
     vector<Entry> v_phone_book = {
            {"Bob", 745902},
            {"Alice",764522 },
            {"Alan", 976320}
    };

    void print_entry(const vector<Entry>& ph_book){
        for(const auto& e: ph_book){
            cout<<e<<endl;
        }
    }

    template <typename T>
    class Vec:public std::vector<T>{
    public:
        using vector<T>::vector; // 使用标准库vector的构造函数

        T&operator[] (int i){ return vector<T>::at(i);} // vector 的at()函数同样负责下标操作 但会在参数越界时抛出类型为
                                                          // out_of_range的异常
    };


    /**
     * list
     * 它是一个双向链表
     */

    list<Entry> l_ph_book = {
            {"Wolf",653724},
            {"swift",976044},
            {"kitty",567291}
    };

    int get_num(const string& str){
        for(auto p = l_ph_book.begin(); p != l_ph_book.end(); ++p){
            if(p->name == str) return p->number;
            return 0;
        }
    }

    void op(const Entry& ce, list<Entry>::iterator p, list<Entry>::iterator q){
        l_ph_book.insert(p,ce); // 将ce添加到p所指向的元素之前
        l_ph_book.erase(q); // 删除q所指向的元素
    }

    // 当数据量较小时 应优先选用vector 相较于list


    /**
     * map(红黑树 平衡二叉树实现)
     * 对于在一个包含(key,value)结构的列表中顺序查找给定key是很低效的  除非列表很短
     */

    map<string, int> m_ph_book = {
            {"newton", 275648},
            {"alan",375821},
            {"knuth",894567}
    };

    int number = m_ph_book["alan"]; // map支持下标操作


    /**
     * unordered_map 像这类带unordered的容器称无序容器
     * 不像map查找是基于某种序函数的比较操作，unordered_map基于哈希函数 得到一张哈希表
     */

    unordered_map<string, int> um_ph_book = {
            {"newton", 275648},
            {"alan",375821},
            {"knuth",894567}
    };

    /**
     *其他容器
     * forward_list<T> 单向链表 #include <forward_list>
     * queue<T> 普通队列 #include <queue>
     * priority_queue<T> 优先级队列 #include <queue>
     * deque<T> 双端队列 #include <deque>
     * multiset<T> 允许重复值的集合 #include <set>
     * multimap<K,T> 允许重复关键字的map #include <map>
     * unordered_map<K,T> 采用哈希函数的map #include <unordered_map>
     * unordered_multimap<K,T> 采用哈希函数的multimap #include <unordered_map>
     * unordered_set<T> 采用哈希搜索的set #include <unordered_set>
     * unordered_multiset<T> 采用哈希搜索的multiset #include <unordered_set>
     *
     * array<T,N> 定长数组 N为具体数字 #include<array>
     * bitset<N>  #include<bitset>
     *
     * 这些容器均在命名空间std 中 使用时需 using namespace std;
     */
};
#endif //C_PROGRAMMING_LANGUAGE_4_3_CONTAINER_H
