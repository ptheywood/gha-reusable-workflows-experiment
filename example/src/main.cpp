// binary main method which just calls a function from the static library
#include "grwe/grwe.h"

int main(const int argc, const char * argv[]) {
    grwe::print_info();
    return 0;
}