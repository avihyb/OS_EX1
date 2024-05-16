#include <iostream>

void infiniteRecursion() {
    infiniteRecursion();
}

void divideByZero() {
    int a = 1;
    int b = 0;
    int result = a / b;  // This will cause a divide by zero error
    std::cout << result << std::endl; // This line is added so that the compiler doesn't optimize out the division
}

void readFromUnknownMemory() {
    // Function attempting to read from unknown memory
    int* ptr = nullptr;
    std::cout << *ptr << std::endl; // Attempting to dereference a null pointer
}

int main() {
    // Call each function to trigger different types of crashes
    //infiniteRecursion();    // Uncomment to trigger infinite recursion
    divideByZero();      // Uncomment to trigger divide by zero
    //readFromUnknownMemory(); // Uncomment to trigger reading from unknown memory

    return 0;
}
