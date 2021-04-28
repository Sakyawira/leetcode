#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>

class Solution {
public:
    void merge(std::vector<int>&& nums1, int m, std::vector<int>&& nums2, int n) {
        nums1.resize(m);
        std::copy(nums2.begin(), nums2.end(), std::back_inserter(nums1));
        for (int i : nums1) {
            std::cout << i << std::endl;
        }
        std::cout << "---------------------------------------------------------- " << std::endl;
        std::sort(nums1.begin(), nums1.end(), [](int a, int b) {    
            return a < b;
        });
        for (int i : nums1) {
            std::cout << i << std::endl;
        }
    }
};

int main() {
    Solution sol;
    
    sol.merge({ 0,0,0,3,4,5, 0,0,0 }, 6,{ 1, 2, 3 }, 3);


}
