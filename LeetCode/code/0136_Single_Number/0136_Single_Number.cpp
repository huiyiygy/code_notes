/*
输入: [4,1,2,1,2]
输出: 4
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int result = nums[0];
		for (size_t i = 1; i < nums.size(); i++) {
			result = result ^ nums[i];
		}
		return result;
	}
};

int main(){
	vector<int> nums = { 4, 1, 2, 1, 2, 4, 5 };
	Solution s;
	int result = s.singleNumber(nums);
	cout << result << endl;
	
	system("pause");
	return 0;
}