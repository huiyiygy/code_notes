/*
输入: nums = [2, 7, 11, 15], target = 9
输出: [0, 1]
*/
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		std::vector<int> result;
		int n = nums.size();
		unordered_map<int, int> hashmap;
		for (int i = 0; i < n; i++) {
			int another = target - nums[i];
			if (hashmap.find(another) != hashmap.end()) {
				result.push_back(hashmap[another]);
				result.push_back(i);
				hashmap.clear();
				break;
			}
			else {
				hashmap.insert(pair<int, int>(nums[i], i));
			}
		}
		return result;
	}
};

int main(){
	vector<int> nums = { 2, 7, 11, 15 };
	int target = 9;
	Solution s;
	vector<int> result = s.twoSum(nums, target);
	for (size_t i = 0; i < result.size(); i++)
	{
		cout << result[i] << "  ";
	}
	system("pause");
	return 0;
}