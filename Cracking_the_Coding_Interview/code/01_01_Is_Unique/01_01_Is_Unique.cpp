/*
 * @Author: huiyiygy
 * @Date: 2022-02-06 19:22:49
 * @LastEditors: huiyiygy
 * @LastEditTime: 2022-02-11 22:31:14
 * @Description: 判定字符是否唯一
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    /**
     * @description:
     * 解法一：若字符范围只包含26个小写字母，可用位运算
     * 时间复杂度O(n)，空间复杂度O(1)
     * Runtime: 0 ms, faster than 100.00%
     * Memory Usage: 6.1 MB, less than 6.9%
     * @param {string} astr
     * @return {*}
     */
    bool isUnique_1(string astr)
    {
        size_t len = astr.size();
        int32_t mark = 0;
        // 针对特殊样例，直接判断返回
        if (len == 0 || len == 1)
            return true;
        if (len > 26)
            return false;
        int32_t move_bit = 0;
        for (size_t i = 0; i < len; i++)
        {
            move_bit = astr[i] - 'a';
            move_bit = 1 << move_bit;
            if ((mark & move_bit) != 0)
            {
                return false;
            }
            mark = mark | move_bit;
        }
        return true;
    }

    /**
     * @description:
     * 解法二：若字符范围是ascii码，128位超过int表示范围，则需要用到ascii数组
     * 时间复杂度O(n)，空间复杂度O(1)
     * Runtime: 0 ms, faster than 100.00%
     * Memory Usage: 5.8 MB, less than 96.53%
     * @param {string} astr
     * @return {*}
     */
    bool isUnique_2(string astr)
    {
        size_t len = astr.size();
        // 针对特殊样例，直接判断返回
        if (len == 0 || len == 1)
            return true;
        if (len > 128)
            return false;
        // 将 字符 对应的ASCII码转为 数组的int下标，每个位置存储该字符在字符串中的下标
        vector<int> char_arry(128, 0);
        int val = 0;
        for (size_t i = 0; i < len; i++)
        {
            val = (int)astr[i];
            if (char_arry[val] == 0)
            {
                char_arry[val] = 1;
            }
            else
                return false;
        }
        return true;
    }

    /**
     * @description:
     * 解法三：若是Unicode码，字符范围超过1600万，字符码数组方式会占用大量内存
     * 可采取对整个字符数组，按int十进制数进行排序，在排序过程中判断是否存在相等的数
     * 时间复杂度O(n^2)，空间复杂度O(n)
     * Runtime: 0 ms, faster than 100.00%
     * Memory Usage: 6 MB, less than 31.65%
     * @param {string} astr
     * @return {*}
     */
    bool isUnique_3(string astr)
    {
        size_t n = astr.size();
        // 针对特殊样例，直接判断返回
        if (n == 0 || n == 1)
            return true;
        vector<int> arry(n, 0);
        arry[0] = (int)astr[0];
        int val = 0;
        // 使用插入排序，边建立数组，边遍历数组，从而节省一次遍历
        // 可在排序中途中断，直接返回
        for (size_t i = 1; i < n; i++)
        {
            val = (int)astr[i];
            size_t j;
            for (j = i; j > 0; --j)
            {
                if (val == arry[j - 1])
                    return false;
                else if (val < arry[j - 1])
                    arry[j] = arry[j - 1];
                else
                    break;
            }
            arry[j] = val;
        }
        return true;
    }

    /**
     * @description:
     * 解法四：使用内置排序库函数
     * @param {string} astr
     * 时间复杂度O(nlog(n))，空间复杂度O(n)
     * Runtime: 0 ms, faster than 100.00%
     * Memory Usage: 6.1 MB, less than 11.49%
     * @return {*}
     */
    bool isUnique_4(string astr)
    {
        size_t n = astr.size();
        // 针对特殊样例，直接判断返回
        if (n == 0 || n == 1)
            return true;
        sort(astr.begin(), astr.end());
        for (int i = 1; i < n; ++i)
        {
            if ((astr[i - 1] ^ astr[i]) == 0)
            {
                return false;
            }
        }
        return true;
    }

    /**
     * @description:
     * 解法五：适用字符库函数
     * 时间复杂度O(n^2)，空间复杂度O(1)
     * Runtime: 0 ms, faster than 100.00%
     * Memory Usage: 5.9 MB, less than 89.71%
     * @param {string} astr
     * @return {*}
     */
    bool isUnique_5(string astr)
    {
        size_t n = astr.size();
        // 针对特殊样例，直接判断返回
        if (n == 0 || n == 1)
            return true;
        for (size_t i = 0; i < n; i++)
        {
            // find()正向查找字符，rfind()逆向查找字符
            if (astr.find(astr[i]) != astr.rfind(astr[i]))
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    string input = "adfefewsbbb";
    Solution s;
    cout << s.isUnique_4(input) << endl;
    system("pause");
    return 0;
}