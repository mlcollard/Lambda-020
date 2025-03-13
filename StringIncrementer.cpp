/*  
    StringIncrementer.cpp

    Implements the StringIncrementer class with methods for processing string input
*/

#include "StringIncrementer.hpp"

// increment the length of the string while logging
int StringIncrementer::incrementLengthWithLogging(std::string_view s) {

    auto result = s.size() + 2;

    log.push_back(result);

    return result;
}

// increment the length of the string with no logging
int StringIncrementer::incrementLength(std::string_view s) {

    return s.size() + 2;
}
