#include <iostream>

using namespace std;

class A
{
public:
    A() = default;
    ~A() = default;
    A(int m) : i(m) {}
    virtual void getInt() const { cout << this->i << endl; }
protected:
    int i = 0;
};

class B : public A
{
public:
    B() = default;
    ~B() = default;
    B(int m) : A(m) {}
    virtual void getInt() const override{ cout << "B的虚函数getInt() 被调用。" << endl; }
};

class C : public B
{
public:
    C() = default;
    ~C() = default;
    C(int m) : j(m) {}
    virtual void getInt() const override { cout << j << endl; }
private:
    int j = 0;
};

int main()
{
    A a(1);
    B b(2);
    C c(3);
    A *aa = &a, *ab = &b, *ac = &c;
    aa->getInt();   //虚调用，调用基类A的虚函数getInt()
    ab->getInt();   //虚调用，调用基类A的虚函数getInt()
    ac->getInt();   //虚调用，调用派生类C的虚函数getInt()
    B* bb = &b;
    bb->getInt();   //普通调用，调用派生类B的虚函数getInt()
    return 0;
}
