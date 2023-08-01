// Pretend test suite.
#include "grwe/grwe.h"

#include <string>
#include <iostream>

bool test_get_info() {
    // call get info, return if it is non zero as a terrible mock test suite.
    std::string info = grwe::get_info();
    return info.length() > 0;
}

int main(const int argc, const char * argv[]) {
    std::cout << "Running tests" << std::endl;
    bool result = true;
    result = result && test_get_info();
    return result == true ? 0 : 1;
}
