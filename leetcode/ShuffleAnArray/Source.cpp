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
        originalVector = nums;
    }

    /** Resets the array to its original configuration and return it. */
    std::vector<int> reset() {
        return originalVector;
    }

    /** Returns a random shuffling of the array. */
    std::vector<int> shuffle() { 
        // Keep the size of the original vector so we do not need to get it everytime
        int originalSize = originalVector.size();
        // Pre-allocate the vector
        std::vector<int> newRandom(originalSize);

        // A helper vector so that we do not need to reset the original vector everytime
        std::vector<int> toRandomised = originalVector;

        for (int i = 0; i < originalSize; i++) {
            // Pick a number from 1 - current size of of the helper vector (after deallocated in the previous loop)
            int randomIndex = rand() % (originalSize - i);
            // Get the number on that index from the helper vector and push it to the new vector
            newRandom[i] = (toRandomised[randomIndex]);
            // Deallocated the index from the helper vector
            toRandomised.erase(toRandomised.begin() + randomIndex);
        }
        return newRandom;
    }
private:
    std::vector<int> originalVector;
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