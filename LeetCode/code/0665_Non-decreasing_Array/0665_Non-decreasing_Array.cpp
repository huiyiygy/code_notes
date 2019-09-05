/*
输入: [4,2,1]
输出: True
解释: 你可以通过把第一个4变成1来使得它成为一个非递减数列。
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int n = nums.size();
		if (n <= 2){
			return true;
		}
		int t = 0;
		if (nums[0] > nums[1]){
			nums[0] = nums[1];
			t++;
		}
		for (int i = 1; i < n - 1; i++){
			int right = nums[i + 1];
			if (nums[i] > right){
				t++;
				if (t > 1){
					return false;
				}
				int left = nums[i - 1];
				if (left > nums[i + 1]){
					nums[i + 1] = nums[i];
				}
				else{
					nums[i] = nums[i - 1];
				}
			}
		}
		return true;
	}
};

int main(){
	vector<int> nums = { 2, 15, 11, 7 };
	Solution s;
	bool result = s.checkPossibility(nums);
	if (result){
		cout << "true" << endl;
	}
	else{
		cout << "false" << endl;
	}
	system("pause");
	return 0;
}