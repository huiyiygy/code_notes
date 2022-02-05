/*
 * @Author: huiyiygy
 * @Date: 2022-02-05 15:26:56
 * @LastEditors: huiyiygy
 * @LastEditTime: 2022-02-05 22:35:04
 * @Description: 最长递增子序列的个数  leetcode300 扩展题
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * @description:
     * 解法一：动态规划 
     * 时间复杂度O(n^2)，空间复杂度O(n)
     * length数组记录 当前位置最长递增子序列的 长度
     * count 数组记录 当前位置最长递增子序列的 个数
     * Runtime: 136 ms, faster than 66.88%
     * Memory Usage: 13.1 MB, less than 82.82%
     * @param {vector<int> &nums}
     * @return {int}
     */
    int findNumberOfLIS_1(vector<int> &nums)
    {
        size_t n = nums.size();
        vector<int> length(n, 1), count(n, 1);
        int max_length = 1, max_count = 0, temp_length = 0;
        for (size_t i = 1; i < n; ++i)
        {
            for (size_t j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    temp_length = length[j] + 1;
                    if (temp_length > length[i])
                    {
                        length[i] = temp_length;
                        count[i] = count[j];
                    }
                    else if (temp_length == length[i])
                        count[i] += count[j];
                }
            }
            max_length = max(max_length, length[i]);
        }
        for (size_t i = 0; i < n; ++i)
        {
            if (max_length == length[i])
                max_count += count[i];
        }
        return max_count;
    }

    /**
     * @description: 
     * 解法二：两次二分查找 
     * 时间复杂度O(nlog(n))，空间复杂度O(n)
     * 题解参考 https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/solution/yanglr-leetcode-accong-lei-si-jian-dan-t-er6c/
     * Runtime: 12 ms, faster than 99.11%
     * Memory Usage: 14.9 MB, less than 7.97%
     * @param {vector<int> &nums}
     * @return {int}
     */
    int findNumberOfLIS_2(vector<int>& nums) {
        const int N = nums.size();
        vector<vector<pair<int, int>>> dp(N + 1);  /* dp table */
        int curMaxLen = 0;
        for (int i = 0; i < N; i++)
        {
            // 二分查找插入点
            int L = 0, R = curMaxLen;
            while (L < R)
            {
                int mid = (L + R) / 2;
                if (dp[mid].back().first < nums[i])
                    L = mid + 1;
                else R = mid;
            }
            // bsearch number of options
            int options = 1;
            int row = L - 1;
            if (row >= 0)
            {
                int L1 = 0, R1 = dp[row].size();
                while (L1 < R1)
                {
                    int mid = (L1 + R1) / 2;
                    if (dp[row][mid].first < nums[i])
                        R1 = mid;
                    else L1 = mid + 1;
                }
                options = dp[row].back().second;
                options -= (L1 == 0) ? 0 : dp[row][L1 - 1].second;
            }

            dp[L].push_back({nums[i], dp[L].empty() ? options : dp[L].back().second + options});
            if (L == curMaxLen) curMaxLen++;
        }        
        return dp[curMaxLen - 1].back().second;
    }

    /**
     * @description: 
     * 解法二优化版，使用内置lower_bound、upper_bound函数替换手动实现的二分查找 
     * 时间复杂度O(nlog(n))，空间复杂度O(n)
     * 题解参考 https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/solution/yanglr-leetcode-accong-lei-si-jian-dan-t-er6c/
     * Runtime: 12 ms, faster than 99.11%
     * Memory Usage: 15.5 MB, less than 5.27%
     * @param {vector<int> &nums}
     * @return {int}
     */
    int findNumberOfLIS_3(vector<int>& nums) {
        const int N = nums.size();
        vector<vector<int>> table(N, vector<int>{});
        vector<vector<int>> paths;
        vector<int> q; /* q: 数组模拟队列, 存 最长递增子序列 中的数 */
        size_t i, j;
        int k;
        for (auto& num : nums)
        {
            i = lower_bound(q.begin(), q.end(), num) - q.begin();
            k = 1;
            if (i > 0)
            {
                j = upper_bound(table[i - 1].begin(), table[i - 1].end(), -num) - table[i - 1].begin();
                k = paths[i - 1].back() - paths[i - 1][j];
            }
            table[i].push_back(-num);

            if (i == q.size())
            {
                q.push_back(num);
                paths.push_back({0, k});
            }
            else
            {
                q[i] = num;
                paths[i].push_back(paths[i].back() + k);
            }
        }
        return paths.back().back();
    }
};

int main()
{
    vector<int> nums = {1, 3, 5, 4, 7};
    Solution s;
    int result = s.findNumberOfLIS_2(nums);
    cout << result << endl;
    system("pause");
    return 0;
}