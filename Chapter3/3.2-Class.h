//
// Created by xl on 2017/8/23.
//


#include <iostream>
#include <memory>

namespace cl {

    class Complex { // 具体类
        double re, im;

    public:
        Complex(double r, double i) : re{r}, im{i} {}

        Complex(double r) : re{r}, im{0} {}

        Complex() : re{0}, im{0} {}


        double real() const { return re; }

        void set_real(double r) { re = r; }

        double imag(double i) { return im; }

        void set_imag(double i) { im = i; }


        Complex &operator+=(Complex c) {
            re += c.re;
            im += c.im;
            return *this;
        }

        Complex &operator*=(Complex c) {
            re = re * c.re - (im * c.im);
            im = im * c.re + (re * c.im);
            return *this;
        }

    };

    Complex &operator+(Complex a, Complex b) { return a += b; } // 该操作有时并不需要直接访问类的表现形式，故其定义可与类定义分离

    /**
     * 尽量规避 裸new 和 裸delete 操作
     */


    /**
     * 初始化容器 使用初始化器列表构造函数(Initializer-list constructor) 使用元素的列表进行初始化
     */

    class Vector {
    public:
        Vector(std::initializer_list<double> ls) :
                elem{new double[ls.size()]}, sz{ls.size()} { std::copy(ls.begin(), ls.end(), elem); }

        Vector(int n) : elem{new double[n]}, sz{n} {}

        Vector() {
            sz = 0;
            elem = nullptr;
        }

        ~Vector() { delete[] elem; }

        double &operator[](int i) { return elem[i]; } // 返回元素的引用
        const double&operator[](int i)const {return elem[i];} // 返回常量元素的引用 即const Vector v {1,3,4,5}

        int size() const { return sz; }

        void push_back(double d) {}

        std::unique_ptr<double> get_elem() { return std::unique_ptr<double>{elem}; }

    private:
        double *elem;
        int sz;

    };

    Vector read(std::istream &in) {
        Vector v;
        for (double d; in >> d;) {
            v.push_back(d);
        }
        return v;

    };



    /**
     * 抽象类
     * 具体类之所以称为具体类 因它们的表现形式属于定义的一部分
     * 相反，抽象类 则将 使用者 与  类的具体实现 完全隔离开
     * 为做到这一点，我们分离接口与表现形式并 放弃纯局部变量
     * 因为对抽象类的表现形式一无所知，所以必须从自由存储区为对象分配空间
     * 然后通过指针或者引用访问对象
     */


    // 含有纯虚函数的类称为抽象类
    // 我们不能单纯定义一个Container类对象，Container类只是作为 接口，它的派生类负责具体实现operator[] 和size()
    // 如果一个类负责为其他一些类提供接口，把前者称为多态类型(polymorphic type)
    // 作为一个抽象类 Container没有构造函数毕竟没有数据需要初始化，且含有一个virtual 的析构函数，
    // 因为抽象类需要通过指针或是引用操作，当摧毁Container时，我们并不知道它的实现部分到底拥有哪些资源
    // 对于抽象类，其派生类
    class Container {
    public:
        virtual double &operator[](int) = 0; // “= 0” 表示纯虚函数  意味着其派生类必须定义该函数(接口)
        virtual int size() const = 0;

        virtual ~Container() {} //虚函数

    };

    class Vector_Container : public Container {
        Vector v;
    public:
        Vector_Container(std::initializer_list<double> lst) : v(lst) {}

        Vector_Container(int n) : v(n) {}

        ~Vector_Container() {} // 该析构函数覆盖了基类的析构函数 ~Container() 成员v的析构函数~Vector()被~Vector_Container()
        // 隐式地调用

        double &operator[](int i) { return v[i]; }

        int size() const { return v.size(); }
    };


    void use(Container &c) { // use(Container& c) 并不清楚它的实参是Vector_Container类型还其他派生自Container的类型
        // 事实上它根本不需要知道 它只要了解Container定义的接口就行了
        int sz = c.size();

        for (int i = 0; i != sz; ++i) {
            std::cout << c[i] << std::endl;
        }
    }


    /**
     * 虚函数
     * use() 中的c[i] 是如何正确解析到对应派生类的operator[] 函数中去的呢
     * 常见方法是编译器将虚函数的名字转换成函数指针表中对应的索引值，该表即虚函数表(virtual function table),简称vtbl
     * 每个含有虚函数的类都有它自己的vtbl辨识虚函数
     * 调用函数只需要知道Container类中vtbl指针的位置和每个虚函数在vtbl中的索引
     * 故该类的每个对象需要一个额外的指针和一张vtbl
     * 当我们使用基类指针释放一个派生类对象时 该 虚函数调用机制 确保我们调用正确的析构函数 该析构函数再隐式地调用基类的析构函数和成员的析构函数
     */





    /**
     * 类层次
     * 类层次提供两种便利：
     *    1.接口继承(Interface inheritance):派生类对象可以用在任何需要基类地对象地地方，此时基类看起来好像派生类的 “接口“ 一样
     *    2.实现继承(Implementation inheritance):派生类使用基类的构造函数，或是基类的成员函数
     * 由于具体类好像内置类型一样，我们可以通过名字使用他们，相反在类层次中，我们倾向于通过new 在自由存储区为其分配空间，
     * 然后通过指针或引用访问它们
     */


    class Shape {
    public:
        virtual double center() const = 0; // 在实轴上
        virtual void move(double) = 0;

        virtual ~Shape() {}

    };

    class Circle : public Shape {
    public:
        Circle(double p, double rr) : loc{p}, r{rr} {}

        Circle() : loc{0}, r{1} {}


        double center() const { return loc; }

        void move(double m) { loc += m; }

    private:
        double loc;
        double r;
    };

    // 函数返回一个指向自由存储区的指针是很危险的，一个解决方案是不要返回一个裸指针，而是返回一个标准库unique_ptr智能指针
    // 即 unique_ptr<Shape>
    Shape *read_shape(std::istream &in) {
        int k = 0;
        in >> k;
        switch (k) {
            case 0:
                return new Circle(1.0, 2.0); // return unique_ptr<Shape>{new Circle{1.0,2.0}}
            case 1:
                return new Circle{2.0, 2.0};
            default:
                return new Circle{};
        }
    }

};
