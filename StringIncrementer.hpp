/*
    StringIncrementer.hpp

    Include file for StringIncrementer class
*/

#ifndef STRING_INCREMENTER_HPP
#define STRING_INCREMENTER_HPP

#include <string_view>
#include <vector>

class StringIncrementer {
public:

    // increment the length of the string while logging
    int incrementLengthWithLogging(std::string_view s);

    // increment the length of the string with no logging
    static int incrementLength(std::string_view s);

private:
    std::vector<int> log;
};

#endif
