#ifndef DO_SOMETHINGABLE_HPP
#define DO_SOMETHINGABLE_HPP

#define PATTERN1 false
#define PATTERN2 true

#if PATTERN1

class do_somethingable {

    struct vtable {
        void (*do_something)(void*);
    };

    template <class T>
    struct vtable_initializer {
        static vtable vtbl_;

        static void do_something(void* this_)
        {
            static_cast<T*>(this_)->do_something();
        }
    };

    void* this_;
    vtable* vptr_;

public:

    template <class T>
    do_somethingable(T& other) : this_(&other), vptr_(&vtable_initializer<T>::vtbl_) {}

    void do_something() const
    {
        vptr_->do_something(this_);
    }

};

template <class T>
do_somethingable::vtable do_somethingable::vtable_initializer<T>::vtbl_ = {
    &do_somethingable::vtable_initializer<T>::do_something
};

#endif
#if PATTERN2

#include <functional>

class do_somethingable {

public:
    const std::function<void()> do_something;

    template <class T>
    do_somethingable(T& obj) : do_something([&obj](){ obj.do_something(); }) {}
};

#endif

#endif // DO_SOMETHINGABLE_HPP
