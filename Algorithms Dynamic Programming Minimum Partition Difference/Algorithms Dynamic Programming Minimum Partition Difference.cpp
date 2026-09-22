#include <iostream>
#include <vector>
int Sum(const std::vector<int> &arr) {
	int sum = 0;
	for (size_t i = 0; i < arr.size();i++) {
		sum += arr[i];
	}
	return sum;
}

int SubsetSum(std::vector <int> &nums) {
	int total = Sum(nums);
	int target = total / 2;
	std::vector <bool> dp(target + 1, false);
	dp[0] = true;
	for (int x : nums) {
		for (int i = target;i >= x;i--) {

				dp[i] = (dp[i - x]||dp[i]);

		}
	}
	for (int i = target;i >= 0;i--) {
		if (dp[i]) {
			return total - 2 * i;
		}
	}
}

int main() {
	std::vector <int> nums = { 1,6,11,1 };
	std::cout <<SubsetSum(nums) <<"\n";

	return 0;
}