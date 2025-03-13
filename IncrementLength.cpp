/*
    IncrementLength.cpp

    Implements a function to increment the length of a string
*/

#include "IncrementLength.hpp"

int incrementLength(std::string_view s) {
    return s.size() + 2;
}
