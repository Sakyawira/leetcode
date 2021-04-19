#include <iostream>

class Solution {
public:
	int hammingDistance(int x, int y) {
		int result = 0;
		while (x > 0 || y > 0) {

			// Modulus 2 will return either 1 or 0
			// It will inform us of whether x/y is even/odd, in other words whether the rightmost bit is 1 or 0

			// The result of the XOR operation can either be 1 or 0, 1 if either but not both x and y is 1
			// This will increment if x and y is different, or if both are 0
			result += (x % 2) ^ (y % 2);

			// Remove the rightmost bit value
			x >>= 1;
			y >>= 1;

			std::cout << "x = " << x << ", y = " << y << std::endl;
		}
		return result;
	}
};

int main(int argc, char** argv)
{
	Solution hammingDistance;
	std::cout << hammingDistance.hammingDistance(8, 3) << std::endl;
}