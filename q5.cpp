#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <algorithm>

int maxSubArraySumLinear(const std::vector<int>& nums) {
    int maxSum = nums[0], currSum = nums[0];
    for (size_t i = 1; i < nums.size(); ++i) {
        currSum = std::max(nums[i], currSum + nums[i]);
        maxSum = std::max(maxSum, currSum);
    }
    return maxSum;
}

int maxSubArraySumQuadratic(const std::vector<int>& nums) {
    int maxSum = INT_MIN;
    for (size_t i = 0; i < nums.size(); ++i) {
        int currSum = 0;
        for (size_t j = i; j < nums.size(); ++j) {
            currSum += nums[j];
            maxSum = std::max(maxSum, currSum);
        }
    }
    return maxSum;
}

int maxSubArraySumCubic(const std::vector<int>& nums) {
    int maxSum = INT_MIN;
    for (size_t i = 0; i < nums.size(); ++i) {
        for (size_t j = i; j < nums.size(); ++j) {
            int currSum = 0;
            for (size_t k = i; k <= j; ++k) {
                currSum += nums[k];
            }
            maxSum = std::max(maxSum, currSum);
        }
    }
    return maxSum;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <seed> <size>" << std::endl;
        return 1;
    }

    int seed = std::stoi(argv[1]);
    int size = std::stoi(argv[2]);

    std::srand(seed);

    std::vector<int> nums(size);
    for (int i = 0; i < size; ++i) {
        nums[i] = std::rand() % 100 - 25; 
    }

    std::cout << "Array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Max subarray sum (O(N)): " << maxSubArraySumLinear(nums) << std::endl;
    std::cout << "Max subarray sum (O(N^2)): " << maxSubArraySumQuadratic(nums) << std::endl;
    std::cout << "Max subarray sum (O(N^3)): " << maxSubArraySumCubic(nums) << std::endl;

    return 0;
}
