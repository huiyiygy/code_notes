/*
输入: nums = [2, 6, 8, 4, 5, 9, 10], target = 16
输出: [1, 6]
*/
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
	std::vector<int> twoSum(vector<int>& nums, int target) {
		std::vector<int> result(2, 0);
		int n = nums.size(), another = 0;
		std::unordered_map<int, int> hashmap;
		for (int i = 0; i < n; i++) {
			another = target - nums[i];
			if (hashmap.find(another) != hashmap.end()) {
				result[0] = hashmap[another];
				result[1] = i;
				break;
			}
			else {
				hashmap[nums[i]] = i;
			}
		}
		return result;
	}
};

int main(){
	std::vector<int> nums = {2, 6, 8, 4, 5, 9, 10};
	int target = 16;
	Solution s;
	std::vector<int> result = s.twoSum(nums, target);
	cout << result[0] << ", " << result[1] << endl;
	
	system("pause");
	return 0;
}