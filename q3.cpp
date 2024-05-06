
#include <iostream>
#include <dlfcn.h>

typedef long double (*PoissonFunc)(int, int);

int main33() {
    void *lib_handle = dlopen("./libpoisson.so", RTLD_LAZY);
    if (!lib_handle) {
        std::cerr << "Error: Cannot load dynamic library." << std::endl;
        return 1;
    }

    PoissonFunc poisson = reinterpret_cast<PoissonFunc>(dlsym(lib_handle, "poisson"));
    if (!poisson) {
        std::cerr << "Error: Cannot find function 'poisson' in the dynamic library." << std::endl;
        dlclose(lib_handle);
        return 1;
    }

    std::pair<int, int> combos[5];
    for (int i = 0; i < 5; ++i) {
        int lambda, k;
        std::cout << "Enter lambda for combo " << i+1 << ": ";
        std::cin >> lambda;
        std::cout << "Enter k for combo " << i+1 << ": ";
        std::cin >> k;

        if (lambda < 0 || k < 0) {
            std::cerr << "Error: Lambda and k must be non-negative integers." << std::endl;
            dlclose(lib_handle);
            return 1;
        }

        combos[i] = std::make_pair(lambda, k);
    }

    for (int i = 0; i < 5; ++i) {
        long double result = poisson(combos[i].first, combos[i].second);
        std::cout << "Poisson(" << combos[i].first << ", " << combos[i].second << ") = " << result << std::endl;
    }

    dlclose(lib_handle);
    return 0;
}
