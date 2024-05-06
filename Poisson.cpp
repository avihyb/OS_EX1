#include <iostream>
#include <cstdlib>
#include <cmath>

long double poisson(int lambda, int k) {
    if (lambda < 0 || k < 0) {
        std::cerr << "Error: Lambda and k must be non-negative integers." << std::endl;
        exit(1);
    }

    return expl(-lambda) * powl(lambda, k) / tgamma(k + 1);
}

int main2(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        exit(1);
    }

    int lambda = std::atoi(argv[1]);
    int k = std::atoi(argv[2]);

    long double result = poisson(lambda, k);
    std::cout << "P(" << lambda << ", " << k << ") = " << result << std::endl;

    return 0;
}
