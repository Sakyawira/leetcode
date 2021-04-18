#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include<algorithm>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
class Solution {
public:
    Solution(std::vector<int>& nums) {
        srand(time(NULL));
        originalVector.clear();
        inputVector.clear();
        originalVector = nums;
        inputVector = originalVector;
    }

    /** Resets the array to its original configuration and return it. */
    std::vector<int> reset() {
        inputVector = originalVector;
        return inputVector;
    }

    /** Returns a random shuffling of the array. */
    std::vector<int> shuffle() { 
        reset();
        std::vector<int> newRandom;
        while (inputVector.size() > 0) {
            // Pick a number from 1 - size of of randomVector
            int randomIndex = rand() % inputVector.size();
            // Get the number on that index from the input vector and push it to the new vector
            newRandom.push_back(inputVector[randomIndex]);
            // Deallocated the number on the same index from the input vector
            inputVector.erase(inputVector.begin() + randomIndex);
        }
        return newRandom;
    }
private:
    std::vector<int> originalVector;
    std::vector<int> inputVector;
};

/***********************
 Description :   Loads main scene and activates loading screen
********************/
int main(int argc, char** argv)
{
   
   // Your Solution object will be instantiated and called as such:
    std::vector<int> myVector({ 1,2,3 });
    Solution* obj = new Solution(myVector);
    std::vector<int> param_1 = obj->reset();
    std::vector<int> param_2 = obj->shuffle();
    for (auto num : param_2) {
        std::cout << num << std::endl;
   }

	int input;
	std::cin >> input;
}