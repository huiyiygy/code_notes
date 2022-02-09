/*
 * @Author: huiyiygy
 * @Date: 2022-02-09 19:54:28
 * @LastEditors: huiyiygy
 * @LastEditTime: 2022-02-09 20:01:21
 * @Description: 生成随机数工具函数
 */
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @description:
 * 生成范围在left ~ right 的随机数组
 * @param {vector<int>} &a 数组
 * @param {int} n 生成数量
 * @param {int} left 范围下界
 * @param {int} right 范围上界
 * @return {*}
 */
void Random(vector<int> &a, int n, int left = 0, int right = 255)
{
    srand(time(0)); //设置时间种子
    int range = right - left + 1;
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % range + left; //生成范围在left ~ right 的随机数
    }
}

// rand() 用来生成随机数，通常生成随机数范围为0~32767
// srand()用来重新设置随机数”种子“

int main()
{
    int nums = 0, m = 0, n = 0;

    system("pause");
    return 0;
}