/*
 * @Author: huiyiygy
 * @Date: 2022-02-04 14:09:29
 * @LastEditors: huiyiygy
 * @LastEditTime: 2022-02-04 22:15:34
 * @Description: 最长递增子序列
 */
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * @description:
     * 解法一：动态规划 时间复杂度O(n^2)，空间复杂度O(n)
     * Runtime: 617 ms, faster than 7.02%
     * Memory Usage: 10.5 MB, less than 63.05%
     * @param {vector<int>} &nums
     * @return {int} result
     */
    int lengthOfLIS_1(vector<int> &nums)
    {
        int n = nums.size(), result = 1;
        // dp存储以第i个元素结尾的最长递增子序列的长度，所以dp[len-1]不一定是整个数组的最长
        vector<int> dp(n, 1);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            result = max(dp[i], result);
        }
        return result;
    }

    /**
     * @description: 
     * 解法二：贪心算法 + 二分查找 时间复杂度O(nlog(n))，空间复杂度O(n)
     * 遍历原数组，对于每一个遍历到的数字，用二分查找法在sub_seq数组找第一个不小于它的数字，
     * 如果存在，  则将这个数字更新为当前遍历到的数字
     * 如果不存在，则将这个数字直接加在sub_seq数组后面
     * 最后返回sub_seq的长度即可
     * 特别注意的是sub_seq数组的值可能不是一个真实的LIS，贪心算法的弊端
     * Runtime: 4 ms, faster than 99.17% 
     * Memory Usage: 10.4 MB, less than 85.40%
     * @param {vector<int>} &nums
     * @return {int} length
     */
    int lengthOfLIS(vector<int> &nums)
    {
        size_t n = nums.size();
        vector<int> sub_seq;
        for(size_t i = 0; i < n; ++i) 
        {
            size_t left = 0, right = sub_seq.size();
            // 二分查找sub_seq数组中第一个不小于nums[i]的数字
            while(left < right)
            {
                size_t mid = (right + left) >> 1;
                if(nums[i] > sub_seq[mid])
                    left = mid + 1;
                else
                    right = mid;
            }
            if (right == sub_seq.size())
                sub_seq.push_back(nums[i]);
            else
                sub_seq[right] = nums[i];
        }
        return sub_seq.size();
    }
};

int main()
{
    vector<int> nums = {10,9,2,5,3,7,101,18};
    Solution s;
    int result = s.lengthOfLIS(nums);
    cout << result << endl;
    system("pause");
    return 0;
}