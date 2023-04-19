#pragma once
#include <iostream>
#include <vector>
#include <future>

constexpr int TEST_SUCCESS = 0;
constexpr int TEST_FAILED  = 1;

// vector output
template<typename T>
static inline std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec) {
    out << '[';
    bool first = true;
    for (const auto& v : vec) {
        if (first) {
            first = false;
        } else {
            out << ",";
        }
        out << v;
    }
    out << ']';
    return out;
}

// test failed output
template<typename T>
static inline void test_failed_output(std::string_view file, int line, std::string_view name, const T& want, const T& got) {
    std::cerr << file << ":" << line << " " << name << " failed! want: " << want << " got: " << got << std::endl;
}

// R: return type
// Args: func arguments type
template<class R, class ...Args>
struct case_t {
    std::string_view name;     // test case name
    std::tuple<Args...> args;  // test case function args
    R want;                    // test case expect return
};

// run tests async
template<class ...Args, class T, class Func>
static inline int run_tests_internal(std::string_view file, int line, std::vector<case_t<T, Args...>>& cases, Func&& f) {
    std::future<int> futures[cases.size()];
    for (int i = 0; i < cases.size(); ++i) {
        // multi threads testing
        futures[i] = std::async(std::launch::async, [&f, &file, line](auto c) {
                if (auto got = std::apply(f, c.args); got != c.want) {
                    test_failed_output(file, line, c.name, c.want, got);
                    return TEST_FAILED;
                }
                return TEST_SUCCESS;
            }, cases[i]);
    }

    int result = TEST_SUCCESS;
    for (auto& fu : futures) {
        if (fu.get() == TEST_FAILED) {
            result = TEST_FAILED;
        }
    }

    return result;
}

// macro for run_tests
#define run_tests(cases, func) run_tests_internal(__FILE__, __LINE__, cases, func)
