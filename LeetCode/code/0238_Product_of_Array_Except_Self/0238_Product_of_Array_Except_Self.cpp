/*
输入: [1,2,3,4]
输出: [24,12,8,6]
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		vector<int> left_product(n);
		left_product[0] = nums[0];
		int right = nums[n - 1];
		for (int i = 1; i < n - 1; ++i) {
			left_product[i] = nums[i] * left_product[i - 1];
		}
		left_product[n - 1] = left_product[n - 2];
		for (int i = n - 2; i > 0; --i) {
			left_product[i] = left_product[i - 1] * right;
			right *= nums[i];
		}
		left_product[0] = right;
		return left_product;
	}
};

int main(){
	vector<int> nums = { 1, 2, 3, 4 };
	Solution s;
	vector<int> result = s.productExceptSelf(nums);
	for (size_t i = 0; i < result.size(); i++)
	{
		cout << result[i] << "  ";
	}
	system("pause");
	return 0;
}