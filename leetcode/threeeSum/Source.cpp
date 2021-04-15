#include <iostream>
#include <vector>
#include <map>
#include<algorithm>
class Solution {
public:

	std::vector<std::vector<int>> twoSum(std::vector<int>& nums, int target) {
		std::vector<std::vector<int>> answers;
		// key is complement
		// value is index that contains it
		std::map<int, int> complementIds;
		int index = 0;
		for (int num : nums)
		{
			int complement = target - num;
			// 
			auto answer = complementIds.find(complement);
			if (answer == complementIds.end())
			{
				complementIds.insert(std::pair<int, int>(num, index));
			}
			else
			{
				// whether we can find the two sums in the vector of vector
				std::vector<int> ivec = { answer->first, num };
				sort(ivec.begin(), ivec.end());
				if (find(answers.begin(), answers.end(), ivec) == answers.end()) {
					answers.push_back(ivec);
				}
			}
			index++;
		}
		return answers;
	}

	std::vector<std::vector<int>> threeSum(std::vector<int>&& nums) {
		std::vector<std::vector<int>> answers;
		if (nums.size() < 3) {
			return answers;
		}
		// sort(nums.begin(), nums.end());
		// key is compliment
		// value is a vector of a vector of the two sums forming the compliments
		std::map<int, std::vector<std::vector<int>>> twoSums;
		int index = 0;
		for (int num : nums)
		{
			int compliment = 0 - num;
			auto answer = twoSums.find(compliment);
			if (answer == twoSums.end())
			{
				std::vector<int> withoutCurrentNum = nums;
				withoutCurrentNum.erase(withoutCurrentNum.begin() + index);
				std::vector<std::vector<int>> complimentFormers = twoSum(withoutCurrentNum, compliment);
				twoSums.insert(std::pair<int, std::vector<std::vector<int>>>(compliment, complimentFormers));

				for (auto complimentFormer : complimentFormers) {
					if (complimentFormer.size() > 0)
					{
						complimentFormer.push_back(num);
						sort(complimentFormer.begin(), complimentFormer.end());
						if (find(answers.begin(), answers.end(), complimentFormer) == answers.end())
						{
							answers.push_back(complimentFormer);
						}
					}
				}
			}
			else
			{
				std::vector<std::vector<int>> iAnswers = answer->second;
				for (auto iAnswer : iAnswers)
				{
					iAnswer.push_back(num);
					sort(iAnswer.begin(), iAnswer.end());
					if (find(answers.begin(), answers.end(), iAnswer) == answers.end())
					{
						answers.push_back(iAnswer);
					}
				}
			}
			index++;
		}

		for (std::vector<int> w : answers) {
			for (int s : w) {
				std::cout << s << ", ";
			}
			std::cout << std::endl;
		}
		return answers;
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