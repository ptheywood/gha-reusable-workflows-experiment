#include "grwe/grwe.h"

#include <iostream>

namespace grwe {

std::string get_info() {
    std::string info = "grew info: \n";
    info += "  GRWE_LIBOPT_A = " + std::string(GRWE_LIBOPT_A) + "\n";
    info += "  GRWE_LIBOPT_B = " + std::string(GRWE_LIBOPT_B) + "\n";

    return info;
}

void print_info() {
    std::cout << get_info() << std::endl;
    return;
}

}  // namespace grwe
