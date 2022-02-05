/*
 * @Author: huiyiygy
 * @Date: 2021-11-28 16:28:27
 * @LastEditors: huiyiygy
 * @LastEditTime: 2022-02-05 21:47:46
 * @Description: 非递减数列
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	bool checkPossibility(vector<int> &nums)
	{
		int n = nums.size();
		if (n <= 2)
		{
			return true;
		}
		int t = 0;
		if (nums[0] > nums[1])
		{
			nums[0] = nums[1];
			t++;
		}
		for (int i = 1; i < n - 1; i++)
		{
			if (nums[i] > nums[i + 1])
			{
				t++;
				if (t > 1)
				{
					return false;
				}
				if (nums[i - 1] > nums[i + 1])
				{
					nums[i + 1] = nums[i];
				}
				else
				{
					nums[i] = nums[i - 1];
				}
			}
		}
		return true;
	}
};

int main()
{
	vector<int> nums = {2, 15, 11, 7};
	Solution s;
	bool result = s.checkPossibility(nums);
	if (result)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
	system("pause");
	return 0;
}