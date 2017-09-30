//
// Created by xl on 2017/9/5.
//
/**
 * 具体类
 */


#ifndef C_PROGRAMMING_LANGUAGE_16_3_CONCRETECLASS_H
#define C_PROGRAMMING_LANGUAGE_16_3_CONCRETECLASS_H

#include <iostream>
using namespace std;

namespace cc{
    /**
     * 辅助函数
     * 一个类都有一些无需定义在类中的函数，因为它们不需要直接访问类的表现形式
     */

    enum class Month{Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

    class Date{
    private:
        int d;
        Month m;
        int y;
        bool is_valid();

    public:
        explicit Date(int, int, int);
        int day() const {return d;};
        Month month() const { return m;};
        int year() const { return y;};
        string str_rep() const;

        Date& add_day(int);
        Date& add_month(int);
        Date& add_year(int);

    };

    void diff(Date& a, Date& b);
    Date defualt_date() const;
    bool is_date(int, Month, int);

    /**
     * 具体类 亦称为值类型 它与内置类型相似 具体类型的大小在编译时就已确定
     * 从而可以在运行时栈中分配对象(即无需自由存储区操作)
     * 对象的内存布局也在编译时就已知
     * 并且展现运行时多态也不是具体类的意图
     */

}
#endif //C_PROGRAMMING_LANGUAGE_16_3_CONCRETECLASS_H
