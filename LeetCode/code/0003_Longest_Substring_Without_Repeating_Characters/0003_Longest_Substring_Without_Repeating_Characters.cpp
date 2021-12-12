/*
 * @Author: huiyiygy
 * @Date: 2021-12-12 14:51:17
 * @LastEditors: huiyiygy
 * @LastEditTime: 2021-12-12 17:12:22
 * @Description: 无重复字符的最长子串
 */
#include <cmath>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * @description:
     * 解法一：暴力遍历
     * 定义两个指针，表示子串的左右边界，采取滑动窗口的形式，每次往右移动，判断下一个字符是否在子串中出现过，出现则更新左边界
     * Runtime: 4 ms, faster than 97.46%
     * Memory Usage: 6.8 MB, less than 87.76%
     * @param {string} s
     * @return {int}
     */
    int lengthOfLongestSubstring_1(string s)
    {
        int start(0), end = 1, len = s.size(), length(0), result(0), index(0);
        char val(0);
        if (len == 0)
            return 0; // 针对特殊样例，直接判断返回
        if (len == 1)
            return 1;
        while (end < len)
        {
            val = s[end];
            for (index = start; index < end; index++)
            {
                if (s[index] == val) // 如果当前值与右边界值相等，则start移动到当前位置的下一位
                {
                    start = index + 1;
                    break;
                }
            }
            length = end - start + 1;
            result = max(length, result);
            end++;
        }
        return result;
    }

    /**
     * @description:
     * 解法二：hashmap存储字符的下标，节省双循环遍历字符串耗时，由于测试样例字符串长度不足，此处不能体现节省
     * Runtime: 8 ms, faster than 85.43%
     * Memory Usage: 8.3 MB, less than 56.22%
     * @param {string} s
     * @return {int}
     */
    int lengthOfLongestSubstring_2(string s)
    {
        int start(0), end = 1, len = s.size(), length(0), result(0);
        char val(0);
        std::unordered_map<char, int> char_map; // 存储 字符、以及对应下标
        if (len == 0)
            return 0; // 针对特殊样例，直接判断返回
        if (len == 1)
            return 1;
        char_map[s[0]] = 0;
        while (end < len)
        {
            val = s[end];
            // 判断能否在窗口中能找到该字符，此时需要注意判断是否大于start，因为该字符可能在滑动窗口之前出现过
            if (char_map.find(val) != char_map.end() && char_map[val] >= start)
            {
                start = char_map[val] + 1;
            }
            char_map[val] = end;
            length = end - start + 1;
            result = max(length, result);
            end++;
        }
        return result;
    }

    /**
     * @description:
     * 解法三：
     * 题目中有提示s 由英文字母、数字、符号和空格组成，由于知晓字符的范围，故可将hashmap存储改为用数组（桶）存储字符的ASCII码
     * Runtime: 0 ms, faster than 100.00%
     * Memory Usage: 7.5 MB, less than 84.34%
     * @param {string} s
     * @return {int}
     */
    int lengthOfLongestSubstring(string s)
    {
        int start(0), end = 1, len = s.size(), length(0), result(0), val(0);
        std::vector<int> char_arry(128, -1); // 将 字符 对应的ASCII码转为 数组的int下标，每个位置存储该字符在字符串中的下标
        if (len == 0)
            return 0; // 针对特殊样例，直接判断返回
        if (len == 1)
            return 1;
        char_arry[int(s[0])] = 0;
        while (end < len)
        {
            val = (int)s[end];
            if (char_arry[val] >= start)
            {
                start = char_arry[val] + 1;
            }
            char_arry[val] = end;
            length = end - start + 1;
            result = max(length, result);
            end++;
        }
        return result;
    }
};

int main()
{
    string input = "bbbbb";
    Solution s;
    int result = s.lengthOfLongestSubstring(input);
    printf("length Of Longest Substring: %d\n", result);
    system("pause");
    return 0;
}