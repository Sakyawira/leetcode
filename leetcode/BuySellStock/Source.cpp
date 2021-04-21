#include <vector>
#include <optional>
#include <iostream>
#include <utility>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        std::optional<int> buyPrice;
        for (int price : prices) {
            if (buyPrice.has_value()) {
                if (price < buyPrice.value()) {
                    buyPrice = price;
                }
                continue;
            }
            buyPrice = price;
        }
        return buyPrice.value_or(0);
    }
};

int main() {
    std::vector<int> prices = {};

    Solution sol;
    std::cout << sol.maxProfit(prices) << std::endl;
    std::cin.get();
}