#include <iostream>
#include <vector>
#include <map>
#include <set>
#include<algorithm>
class Solution {
public:

	void insertUnique(std::vector<int> input, std::set<std::vector<int>>& container) {
		// whether we can find the two sums in the vector of vector
		sort(input.begin(), input.end());
		container.insert(input);
	}

	void twoSum(std::vector<int>& nums, int target, std::map<int, std::set<std::vector<int>>>& twoSums) {
		std::set<std::vector<int>> answers;
		// key is complement
		// value is index that contains it
		std::set<int> complementIds;
		for (int num : nums)
		{
			int complement = target - num;
			auto answer = complementIds.find(complement);
			if (answer == complementIds.end())
			{
				complementIds.insert(num);
				continue;
			}
			insertUnique({ *answer, num }, answers);
		}
		twoSums.insert(std::pair<int, std::set<std::vector<int>>>(target, answers));
	}

	std::vector<std::vector<int>> threeSum(std::vector<int>&& nums) {
		std::set<std::vector<int>> answers;
		if (nums.size() < 3) {
			return std::vector<std::vector<int>>();
		}
		// sort(nums.begin(), nums.end());
		// key is compliment
		// value is a vector of a vector of the two sums forming the compliments
		std::map<int, std::set<std::vector<int>>> twoSums;
		int index = 0;
		for (int num : nums)
		{
			int compliment = 0 - num;
			auto answer = twoSums.find(compliment);
			if (answer == twoSums.end())
			{
				std::vector<int> withoutCurrentNum = nums;
				withoutCurrentNum.erase(withoutCurrentNum.begin() + index);
				// adding the two sum to the list of two sums
				twoSum(withoutCurrentNum, compliment, twoSums);

				// adding the two sums to the list of answers
				for (auto complimentFormer : twoSums.at(compliment)) {
					if (complimentFormer.size() > 0)
					{
						complimentFormer.push_back(num);
						insertUnique(complimentFormer, answers);
					}
				}
				index++;
				continue;
			}
			for (auto iAnswer : answer->second)
			{
				iAnswer.push_back(num);
				insertUnique(iAnswer, answers);
			}
			index++;
		}

		for (std::vector<int> w : answers) {
			for (int s : w) {
				std::cout << s << ", ";
			}
			std::cout << std::endl;
		}
		return std::vector<std::vector<int>>(answers.begin(), answers.end());
	}
};

/***********************
 Description :   Loads main scene and activates loading screen
********************/
int main(int argc, char** argv)
{
	Solution solution;
	solution.threeSum({ -1,0,1,2,-1,-4,-2,-3,3,0,4 });
	int input;
	std::cin >> input;
}