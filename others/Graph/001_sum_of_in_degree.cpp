/*
 * @Author: huiyiygy
 * @Date: 2022-02-19 22:10:01
 * @LastEditors: huiyiygy
 * @LastEditTime: 2022-02-20 01:01:34
 * @Description: 入度之和
 * 题目
 * 在包含N个节点的有向图上，节点从 1 到 N 编号。初始时图中没有连边。
 * 现在对所有整数对 (i, j)
 * 如果满足 1 <= i < j <= N，且 i 能整除 j，则从 i 号节点向 j 号节点连一条边。
 * 那么图上所有节点的入度（某个节点的入度即连向该节点的边数）之和是多少？
 * 
 * 输入为一个整数 N， 1 <= N <= 10^9，输出为所有节点的入度之和
 * 
 * 如 输入 6，输出 8
 */
#include <iostream>

using namespace std;

long long in_degree(int N)
{
	// i 最大为 N 的 1/2
	int mid = N >> 1;
	long long result = 0;
	for (int i = 1; i <= mid; ++i)
	{
		// 计算N是i的多少倍，由于 1 <= i < j <= N，故j的个数为 N / i - 1
		result += N / i - 1;
	}
	return result;
}

int main()
{
	int n;
	cin >> n;
	long long result = in_degree(n);
	cout << result << endl;
	system("pause");
	return 0;
}