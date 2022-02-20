/*
 * @Author: huiyiygy
 * @Date: 2022-02-20 23:11:35
 * @LastEditors: huiyiygy
 * @LastEditTime: 2022-02-21 00:38:51
 * @Description: 青蛙过河
 * 题目
 * 河面上从左到右并排长着 N 片荷叶，相邻两片荷叶之间的距离为 1。在最左边的荷叶上有一只青蛙，它想跳到最右边的荷叶上。
 * 这只青蛙每次可以 向左 或 向右 跳到另一片荷叶上，最大跳跃距离为 2，即它每次可以跳到相邻的荷叶或越过相邻的荷叶。
 * 在这只青蛙从一片荷叶上跳走时，这片荷叶就沉入河里。那么，这只青蛙有多少种跳跃路线能够到达最右边的荷叶？
 * 由于答案可能很大，请输出答案对 M 取模后的结果。
 *
 * 输入描述
 * 仅一行输入两个整数N、M (1 < N <= 10^6, 1 < M <= 1000000007)
 *
 * 输出描述
 * 输出一个整数，表示合法的跳跃路线的数量对M取模后的结果
 *
 * 样例输入
 * 4 10
 *
 * 样例输出
 * 4
 *
 * 思路
 * 动态规划，从2片荷叶的情况开始推导，统计存在的跳跃路线
 */
#include <iostream>
#include <vector>

using namespace std;

int get_way(int n, int m)
{
    // dp[i] 表示跳到第i+1片荷叶时 存在的跳跃路线总数
    vector<int> dp(n);
    // 手动统计 5片荷叶有 7 种跳跃方式，6片荷叶有 13 种跳跃方式
    dp[0] = 0 % m;
    dp[1] = 1 % m;
    dp[2] = 2 % m;
    dp[3] = 4 % m;
    // 状态转移方程 dp[i] = dp[i-3] + dp[i-2] + dp[i-1]，其中dp[i-3]表示 +2-1+2 这种跳跃方式
    for (int i = 4; i < n; ++i)
    {
        // 注意计算结果需要对M取模，否则随着不断累加，数字将很快溢出，连 unsigned long long 都不够存储
        // 计算时取余数，不会影响最终的结果
        dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % m;
    }
    return dp[n - 1];
}

int main()
{
    int n, m;
    cin >> n >> m;
    int ways = get_way(n, m);
    cout << ways << endl;
    system("pause");
    return 0;
}