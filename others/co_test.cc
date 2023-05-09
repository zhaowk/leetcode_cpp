#include <coroutine>
#include <iostream>
#include <string>

template<class T>
struct resumable {
    struct promise_type{
        T val{};
        T result{};
        resumable get_return_object() {
            return resumable(std::coroutine_handle<promise_type>::from_promise(*this));
        }
        auto initial_suspend() {return std::suspend_never{};}
        auto final_suspend() noexcept {return std::suspend_always{};}

//        void return_void() {}
        void return_value(T a) {
            result = a;
        }

        auto yield_value(T a) {
            val += a;
            return std::suspend_always{};
        }

        void unhandled_exception() {std::cout << "????????" << std::endl;}
    };
    std::coroutine_handle<promise_type> _coro = nullptr;

    resumable() = default;
    explicit resumable(std::coroutine_handle<promise_type> coro) : _coro(coro) {}
    resumable(const resumable&) = delete;
    resumable(resumable&& other) noexcept : _coro(other._coro) {
        other._coro = nullptr;
    }

    resumable& operator=(const resumable& other) = delete;
    resumable& operator=(resumable&& other)  noexcept {
        if (this != &other) {
            _coro = other._coro;
            other._coro = nullptr;
        }
        return *this;
    }

    ~resumable() {
        if (_coro) _coro.destroy();
    }
    void resume() {
        std::cout << "resume..." << std::endl;
        if (_coro) _coro.resume();
    }

    bool done() {
        return _coro.done();
    }

    T value() {
        T val{};
        if (_coro && !_coro.done()) {
            val =  _coro.promise().val;
            _coro.resume();
        }
        return val;
    }
    T result() {
        return _coro.promise().result;
    }
};

resumable<int> f() {
    int i = 0;
    while (i < 2) {
        co_await std::suspend_always{};
        std::cout << i++ << std::endl;
    }

    co_return i;
}

resumable<std::string> g() {
    int i = 0;
    while(i < 4) {
        co_yield std::to_string(i);
        i++;
    }
    co_return "hello world";
}


int main() {
    auto co = f();
    while(!co.done()) {
        co.resume();
    }

    std::cout << co.result() << std::endl;
    std::cout << "<<<<<<<<<<" << std::endl;

    auto co2 = g();
    while(!co2.done()) {
        std::cout << co2.value() << std::endl;
    }

    std::cout << co2.result() << std::endl;
    return 0;
}
