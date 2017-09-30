//
// Created by xl on 2017/8/25.
//

/**
 * io 数据流
 */


#ifndef C_PROGRAMMING_LANGUAGE_4_3_IOSTREAM_H
#define C_PROGRAMMING_LANGUAGE_4_3_IOSTREAM_H


#include <string>
#include <iostream>
#include <ios>
using namespace std;
namespace i_o_s{

    /**
     * 用户自定义类型的I/O
     */
    struct Entry{
        string name;
        int number;
    };

    ostream& operator<< (ostream& os, const Entry& e){
        return os<<"{"<<e.name<<","<<e.number<<"}";
    }

    istream& operator>> (istream& is, Entry& e){
        char c1,c2;
        if(is>>c1 && c1 == '{' && is >>c2 && c2 == '"'){
            string name;
            while(is.get(c1) && c1 != '"') name += c1;

            if(is>>c2 && c2 == ','){
                int num = 0;
                if(is>>num>>c2 && c2 == '}'){
                    e = {name,num};
                    return is;
                }
            }
        }

        is.setstate(ios_base::failbit); // 置输入流状态为失败
        return is;
    }
}
#endif //C_PROGRAMMING_LANGUAGE_4_3_IOSTREAM_H
