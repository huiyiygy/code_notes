/*
输入: [1,8,6,2,5,4,8,3,7]
输出: 49
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int n = height.size();
		int max_area=0, left=0, right=n-1;
		while (left < right){
			max_area = max(max_area, (right-left)*min(height[left], height[right]));
			if (height[left] > height[right]){
				--right;
			} else{
				++left;
			}
		}
		return max_area;
	}
};


int main() {
	vector<int> nums = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
	Solution s;
	int result = s.maxArea(nums);
	cout << result << endl;

	system("pause");
	return 0;
}