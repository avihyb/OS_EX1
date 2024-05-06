// poisson.cpp

#include <iostream>
#include <cmath>

extern "C" long double poisson(int lambda, int k) {
    if (lambda < 0 || k < 0) {
        std::cerr << "Error: Lambda and k must be non-negative integers." << std::endl;
        exit(1);
    }

    return expl(-lambda) * powl(lambda, k) / tgamma(k + 1);
}
