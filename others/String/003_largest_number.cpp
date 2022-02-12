/*
 * @Author: huiyiygy
 * @Date: 2022-02-12 15:04:47
 * @LastEditors: huiyiygy
 * @LastEditTime: 2022-02-12 16:16:00
 * @Description:
 * 题目
 * 有一些数字，可以将这些数字表示成字符串并进行翻转，如“1234”翻转为"4321"，现在可以将这些字符串以任意顺序拼接起来，在拼接的时候每个字符串可以选择翻转或者不翻转，问能得到的最大拼接的整数是多少。
 *
 * 如：
 * [10,2]       最大数为"210"
 * [103,2]      最大数为"3012"
 * [0, 0, 0, 0] 最大数为"0"
 *
 * 思路
 * 与leetcode 179相同，只不过要增加一次判断数字自身翻转后的大小
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool cmp(string a, string b)
{
    return a + b > b + a;
}

string largestNumber(vector<int> &nums)
{
    vector<string> str;
    for (auto num : nums)
    {
        string temp1 = to_string(num);
        string temp2(temp1.rbegin(), temp1.rend()); // 将temp1进行翻转
        if (cmp(temp1, temp2))  // 比较 数字翻转前后大小，将较大的存入数组
            str.push_back(temp1);
        else
            str.push_back(temp2);
    }

    if (str.size() == 1)
        return str[0];

    sort(str.begin(), str.end(), cmp); // 字符串从大到小排列
    string result;
    for (auto s : str)
    {
        if (result == "0" && s == "0") // 处理特殊情况，数组中只有多个0
            break;
        result += s;
    }
    return result;
}

int main()
{
    vector<int> nums = {3, 30, 34, 5, 9}; // result = 9543330
    string result = largestNumber(nums);
    cout << result << endl;
    system("pause");
    return 0;
}