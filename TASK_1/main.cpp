#include <iostream>
#include "cmake-build-debug/header.h"

using namespace header;

int main() {
    Line* firstLine = nullptr;
    int m, n;
    m = getRowNum();
    n = getColNum();
    erase(firstLine);
    menu_(firstLine, m, n);
    return 0;
}