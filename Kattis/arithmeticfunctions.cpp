#include "arithmeticfunctions.h"
#include <algorithm>

// Compute x^3
int cube(int x){
    return x * x * x;
}

// Compute the maximum of x and y
int max(int x, int y){
    return std::max(x, y);
}

// Compute x - y
int difference(int x, int y){
    return x - y;
}