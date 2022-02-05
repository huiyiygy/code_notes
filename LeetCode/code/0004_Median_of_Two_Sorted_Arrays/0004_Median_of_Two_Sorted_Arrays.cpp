/*
 * @Author: huiyiygy
 * @Date: 2021-12-12 23:25:27
 * @LastEditors: huiyiygy
 * @LastEditTime: 2022-02-05 23:09:37
 * @Description: 寻找两个正序数组的中位
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
     * 解法一：合并两数组，找到中位数下标
     * 时间复杂度O(m+n)，空间复杂度O(m+n)
     * Runtime: 45 ms, faster than 54.58%
     * Memory Usage: 89.6 MB, less than 44.04%
     * @param {vector<int> &nums1, vector<int>} &nums2
     * @return {double}
     */
    double findMedianSortedArrays_1(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m == 0 && n == 0) // 特殊样例，直接返回
            return 0.0;
        else if (m == 0 && n == 1)
            return (double)nums2[0];
        else if (m == 1 && n == 0)
            return (double)nums1[0];
        else if (m == 1 && n == 1)
            return (nums1[0] + nums2[0]) / 2.0;
        // len为偶数时，中位数为 (num[mid] + num[mid+1]) / 2.0
        // len为奇数时，中位数为 (double)num[mid]
        int len = m + n;
        int mid = len >> 1;
        // 对两数组进行排序合并
        int i(0), j(0), index(0);
        vector<int> merge(mid + 2, 0);
        while (index <= mid + 1)
        {
            if (i == m)
            {
                merge[index] = nums2[j];
                j++;
                index++;
                continue;
            }
            if (j == n)
            {
                merge[index] = nums1[i];
                i++;
                index++;
                continue;
            }
            if (nums1[i] < nums2[j])
            {
                merge[index] = nums1[i];
                i++;
                index++;
                continue;
            }
            else
            {
                merge[index] = nums2[j];
                j++;
                index++;
                continue;
            }
        }
        // 判断合并后两数组的长度 奇偶性，奇数为1，偶数为0
        if (len & 1) // 奇数
        {
            return (double)merge[mid];
        }
        else // 偶数
        {
            return (merge[mid] + merge[mid + 1]) / 2.0;
        }
    }

    /**
     * @description:
     * 找第k大的数
     * @param {int} k
     * @return {*}
     */
    int getKthElement(const vector<int> &nums1, const vector<int> &nums2, int k)
    {
        /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
         */
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;

        while (true)
        {
            // 边界情况
            if (index1 == m)
            {
                return nums2[index2 + k - 1];
            }
            if (index2 == n)
            {
                return nums1[index1 + k - 1];
            }
            if (k == 1)
            {
                return min(nums1[index1], nums2[index2]);
            }
            // 正常情况
            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2)
            {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else
            {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    /**
     * @description:
     * 解法二：
     * 求中位数，其实就是求第 k 小数的一种特殊情况
     * 时间复杂度O(log(m+n))，空间复杂度O(1)
     * 题解参考：https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-s-114/
     * Runtime: 51 ms, faster than 48.99%
     * Memory Usage: 89.4 MB, less than 43.90%
     * @param {vector<int> &nums1, vector<int>} &nums2
     * @return {double}
     */
    double findMedianSortedArrays_2(vector<int> &nums1, vector<int> &nums2)
    {
        int totalLength = nums1.size() + nums2.size();
        int mid = totalLength >> 1;
        if (totalLength & 1) // 奇数
        {
            return getKthElement(nums1, nums2, mid + 1);
        }
        else // 偶数
        {
            return (getKthElement(nums1, nums2, mid) + getKthElement(nums1, nums2, mid + 1)) / 2.0;
        }
    }

    /**
     * @description:
     * 解法三：不断划分数组
     * 时间复杂度O(log(min(m,n)))，空间复杂度O(1)
     * 题解参考：https://leetcode-cn.com/problems/median-of-two-sorted-arrays/solution/xun-zhao-liang-ge-you-xu-shu-zu-de-zhong-wei-s-114/
     * Runtime: 52 ms, faster than 47.47%
     * Memory Usage: 89.3 MB, less than 60.51% 
     * @param {vector<int> &nums1, vector<int>} &nums2
     * @return {double}
     */
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        // median1：前一部分的最大值
        // median2：后一部分的最小值
        int median1 = 0, median2 = 0;
        while (left <= right)
        {
            // 前一部分包含 nums1[0 .. i-1] 和 nums2[0 .. j-1]
            // 后一部分包含 nums1[i .. m-1] 和 nums2[j .. n-1]
            int i = (left + right) / 2;
            int j = (m + n + 1) / 2 - i;
            // nums_im1, nums_i, nums_jm1, nums_j 分别表示 nums1[i-1], nums1[i], nums2[j-1], nums2[j]
            int nums_im1 = (i == 0 ? INT_MIN : nums1[i - 1]);
            int nums_i   = (i == m ? INT_MAX : nums1[i]);
            int nums_jm1 = (j == 0 ? INT_MIN : nums2[j - 1]);
            int nums_j   = (j == n ? INT_MAX : nums2[j]);

            if (nums_im1 <= nums_j)
            {
                median1 = max(nums_im1, nums_jm1);
                median2 = min(nums_i, nums_j);
                left = i + 1;
            }
            else
            {
                right = i - 1;
            }
        }
        return (m + n) % 2 == 0 ? (median1 + median2) / 2.0 : median1;
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {4, 5, 6, 7, 8, 9, 10, 11, 11, 13};
    Solution s;
    double result = s.findMedianSortedArrays(nums1, nums2);
    printf("findMedianSortedArrays: %lf\n", result);
    system("pause");
    return 0;
}