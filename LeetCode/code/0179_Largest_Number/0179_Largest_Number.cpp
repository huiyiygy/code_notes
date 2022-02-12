/*
 * @Author: huiyiygy
 * @Date: 2022-02-11 22:59:31
 * @LastEditors: huiyiygy
 * @LastEditTime: 2022-02-12 16:17:23
 * @Description:
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a; // 两字符串直接相加，从左到右，逐位比较二者字符哪个ascii值更大
}

class Solution
{
public:
    /**
     * @description: 
     * 利用字符串大小比较。若要使数字最大，则排序时，最高位的数字越大越好
     * 时间复杂度O(nlog(n)nlog(m))，空间复杂度O(n)，m表示单个字符串的长度
     * Runtime: 3 ms, faster than 97.94%
     * Memory Usage: 11.4 MB, less than 41.43%
     * @param {vector<int>} &nums
     * @return {*}
     */
    string largestNumber(vector<int> &nums)
    {
        if (nums.size() == 1)
            return to_string(nums[0]);
        vector<string> str;
        for (auto num : nums)
            str.push_back(to_string(num));
        sort(str.begin(), str.end(), cmp); // 字符串从大到小排序
        string result;
        for (auto s : str)
        {
            if (result == "0" && s == "0")  // 处理特殊情况，数组中只有多个0
                break;
            result += s;
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {3, 30, 34, 5, 9};
    Solution s;
    string result = s.largestNumber(nums);
    cout << result << endl;
    system("pause");
    return 0;
}