/*
 * @Author: huiyiygy
 * @Date: 2022-02-06 13:26:05
 * @LastEditors: huiyiygy
 * @LastEditTime: 2022-02-06 19:01:33
 * @Description: 俄罗斯套娃信封问题 leetcode300 扩展题
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
     * 使用希尔排序对二维数组进行从小到大排序
     * 特别注意：
     * 先对第一维按升序排序，
     * 若第一维相等，则第二维按降序排列，避免后续dp只判断第二维时，特殊情况下出错，如[1,1], [1,2],该序列不满足
     * 时间复杂度：O(n^1.3)，空间复杂度：O(1)
     * @param {vector<vector<int>>} &arr
     * @return {*}
     */
    void ShellSort(vector<vector<int>> &arr)
    {
        size_t n = arr.size(), h = 1;
        while (h < n / 3 - 1)
            h = h * 3 + 1;
        while (h >= 1)
        {
            for (size_t i = h; i < n; ++i)
            {
                //对arr[i], arr[i-h], arr[i-2h]...使用插入排序
                int inserted_1 = arr[i][0];
                int inserted_2 = arr[i][1];
                size_t j;
                for (j = i; j >= h; j -= h)
                {
                    if(inserted_1 < arr[j - h][0] || 
                      (inserted_1 == arr[j - h][0] && inserted_2 > arr[j - h][1]))
                    {
                        arr[j][0] = arr[j - h][0];
                        arr[j][1] = arr[j - h][1];
                    }
                    else
                        break;  // 插入排序，插入位置前的都已经是有序的，可直接跳出
                }
                arr[j][0] = inserted_1;
                arr[j][1] = inserted_2;
            }
            h /= 3;
        }
    }

    /**
     * @description:
     * 解法一：先对二维数组排序，然后参照leetcode300进行动态规划
     * 时间复杂度：O(n^2)，空间复杂度：O(n)
     * 当输入数组长度为10^5时，算法超时
     * @param {vector<vector<int>>} &envelopes
     * @return {int}
     */
    int maxEnvelopes_1(vector<vector<int>> &envelopes)
    {
        size_t n = envelopes.size();
        int result = 1;
        if (n == 1)
            return result;
        ShellSort(envelopes);
        vector<int> dp(n, 1);
        for (size_t i = 1; i < n; i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                // 此时不再需要判断第一个位置的大小，因为排序时已经严格满足
                if (envelopes[j][1] < envelopes[i][1])
                {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            result = max(result, dp[i]);
        }
        return result;
    }

    /**
     * @description: 
     * 解法二：先对二维数组排序，然后参照leetcode300进行贪心+二分查找
     * 时间复杂度：O(nlog(n))，空间复杂度：O(n)
     * Runtime: 698 ms, faster than 49.42%
     * Memory Usage: 77.6 MB, less than 5.78%
     * @param {vector<vector<int>>} &envelopes
     * @return {*}
     */
    int maxEnvelopes_2(vector<vector<int>> &envelopes)
    {
        size_t n = envelopes.size();
        if (n == 1)
            return 1;
        ShellSort(envelopes);
        vector<int> sub_seq;
        for(size_t i = 0; i < n; ++i)
        {
            size_t left = 0, right = sub_seq.size();
            while(left < right)
            {
                size_t mid = (left + right) >> 1;
                if (envelopes[i][1] > sub_seq[mid])
                    left = mid + 1;
                else
                    right = mid;
            }
            if(right == sub_seq.size())
                sub_seq.push_back(envelopes[i][1]);
            else
                sub_seq[right] = envelopes[i][1];
        }
        return sub_seq.size();
    }

    /**
     * @description: 
     * 解法二优化：使用库函数实现排序，其它保持一致
     * 时间复杂度：O(nlog(n))，空间复杂度：O(n)
     * Runtime: 496 ms, faster than 56.84%
     * Memory Usage: 77.4 MB, less than 10.63%
     * @param {vector<vector<int>>} &envelopes
     * @return {*}
     */
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        size_t n = envelopes.size();
        if (n == 1)
            return 1;
        sort(envelopes.begin(), envelopes.end(), 
            [](vector<int>& a, vector<int>& b)
            {
                if(a[0] == b[0])
                    return a[1] > b[1]; // 对于宽度相等的信封，根据高度逆序，大的在前小的在后
                return a[0] < b[0];
            }
        );
        vector<int> sub_seq;
        for(size_t i = 0; i < n; ++i)
        {
            size_t left = 0, right = sub_seq.size();
            while(left < right)
            {
                size_t mid = (left + right) >> 1;
                if (envelopes[i][1] > sub_seq[mid])
                    left = mid + 1;
                else
                    right = mid;
            }
            if(right == sub_seq.size())
                sub_seq.push_back(envelopes[i][1]);
            else
                sub_seq[right] = envelopes[i][1];
        }
        return sub_seq.size();
    }
};

int main()
{
    vector<vector<int>> nums = {{10, 17}, {10, 19}, {16, 2}, {19, 18}, {5, 6}};
    Solution s;
    int result = s.maxEnvelopes(nums);
    cout << result << endl;
    system("pause");
    return 0;
}