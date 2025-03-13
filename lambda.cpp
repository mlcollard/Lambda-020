/*
    lambda.cpp

    Examples of captures in lambda functions and use of std::function
*/

#include <functional>
#include <string_view>
#include <iostream>
#include <sstream>
#include <cassert>
#include "Framework.hpp"
#include "IncrementLength.hpp"
#include "StringIncrementer.hpp"

int main(int argc, char* argv[]) {

    // function
    {
        Framework framework;

        std::function<int(std::string_view)> f = incrementLength;

        if (f) {
            assert(framework.apply(f, "a") == 3);
        }
    }

    // empty capture
    {
        Framework framework;

        std::function<int(std::string_view)> f = [](std::string_view s)->int {
            return s.size() + 2;
        };

        if (f) {
            assert(framework.apply(f, "a") == 3);
        }
    }

    // const variable capture reference
    {
        Framework framework;

        const int INCREMENT = 2;
        std::function<int(std::string_view)> f = [](std::string_view s)->int {
            return s.size() + INCREMENT;
        };

        if (f) {
            assert(framework.apply(f, "a") == 3);
        }
    }

    // capture variable because not constexpr
    {
        Framework framework;

        int size = 2;
        const int INCREMENT = size;
        std::function<int(std::string_view)> f = [INCREMENT](std::string_view s)->int {
            return s.size() + INCREMENT;
        };

        if (f) {
            assert(framework.apply(f, "a") == 3);
        }
    }

    // non-const variable capture value
    {
        Framework framework;

        int increment = 2;
        std::function<int(std::string_view)> f = [increment](std::string_view s)->int {
            return s.size() + increment;
        };

        if (f) {
            assert(framework.apply(f, "a") == 3);
        }
    }

    // capture the number of times the function is executed
    {
        Framework framework;

        int numberOfCalls = 0;
        std::function<int(std::string_view)> f;

        if (f) {
            assert(framework.apply(f, "a") == 3);
            assert(numberOfCalls == 1);
        }
    }

    // pass complex object and use inside lambda
    {
        Framework framework;

        std::istringstream input("2");

        std::function<int(std::string_view)> f;

        if (f) {
            assert(framework.apply(f, "a") == 3);
        }
    }

    // pass static method of a class
    {
        Framework framework;

        std::function<int(std::string_view)> f;

        if (f) {
            assert(framework.apply(f, "a") == 3);
        }
    }

    // pass non-static method of a class
    {
        Framework framework;
        StringIncrementer incrementer;

        std::function<int(std::string_view)> f;

        if (f) {
            assert(framework.apply(f, "a") == 3);
        }
    }

    return 0;
}
