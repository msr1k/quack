#include "./do_somethingable.hpp"

#include <iostream>

class A {
public:
    void do_something() const
    {
        std::cout << "A::do_something" << std::endl;
    }
};


class B {
public:
    void do_something() const
    {
        std::cout << "B::do_something" << std::endl;
    }
};

int main(int argc, char const* argv[])
{
    A a;
    B b;

    do_somethingable dsa = a;
    dsa.do_something();

    do_somethingable dsb = b;
    dsb.do_something();

    return 0;
}
