#include <vector>
#include <optional>
#include <iostream>
#include <utility>
#include <algorithm>


class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        std::optional<int> buyPrice;
        std::optional<int> currentProfit;

        int index = 0;
        for (int price : prices) {
            // minimum price from day 0 to current day
            buyPrice = std::min(buyPrice.value_or(INT_MAX), price);

            // get the largest profit between last profit and the new one (difference between current value and current buy value) 
            currentProfit = std::max(currentProfit.value_or(0),  price - buyPrice.value_or(INT_MAX));
        }
        return currentProfit.value_or(0);
    }
};

int main() {
    std::vector<int> prices = {};

    Solution sol;
    std::cout << sol.maxProfit(prices) << std::endl;
    std::cin.get();
}