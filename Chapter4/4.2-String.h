//
// Created by xl on 2017/8/25.
//

/**
 * 字符串
 */

#ifndef C_PROGRAMMING_LANGUAGE_4_2_STRING_H
#define C_PROGRAMMING_LANGUAGE_4_2_STRING_H

#include <string>
#include <iostream>
using namespace std;


//使用 + 表示字符串连接操作
string s = "hello ";
string cs = s + "world!";

//string 类型还支持下标操作和子串操作
void f(){
    string sub_s = cs.substr(6,5);// 第一个参数指出原字符串的一个起始位置，第二个参数指出所需子串长度 sub_s = "world"
    cs.replace(0,5,"hi"); // 从cs 的位置0开始替换长度为5的子串为“hi” cs= "hi world!"
    cs[0] = toupper(cs[0]);
    cout << sub_s<<" "<<cs;
}

#endif //C_PROGRAMMING_LANGUAGE_4_2_STRING_H
