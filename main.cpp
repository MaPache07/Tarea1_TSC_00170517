#include <iostream>
#include "math_tools.h"
#include "display_tools.h"
using namespace std;

int main() {
    Matrix m, rev;
    zeroes(m, 3);

    m.at(0).at(0) = 2; m.at(0).at(1) = 2; m.at(0).at(2) = 3;
    m.at(1).at(0) = 4; m.at(1).at(1) = 5; m.at(1).at(2) = 6;
    m.at(2).at(0) = 7; m.at(2).at(1) = 8; m.at(2).at(2) = 9;
    reverse(m, rev);
    showMatrix(rev);

    return 0;
}