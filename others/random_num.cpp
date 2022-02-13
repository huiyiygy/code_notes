/*
 * @Author: huiyiygy
 * @Date: 2022-02-09 19:54:28
 * @LastEditors: huiyiygy
 * @LastEditTime: 2022-02-14 00:23:29
 * @Description: 生成随机数工具函数
 */
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

/**
 * @description:
 * 手动实现 生成范围在left ~ right 的随机整数数组
 * @param {int} n 生成数量
 * @param {int} left 范围下界
 * @param {int} right 范围上界
 * @param {vector<int>} &result 结果数组
 * @return {*}
 */
void Random_1(int n, int left, int right, vector<int> &result)
{
    // rand() 用来生成随机数，通常生成随机数范围为0~32767
    // srand()用来重新设置随机数“种子”
    srand(time(0)); //设置时间种子
    int range = right - left + 1;
    for (int i = 0; i < n; i++)
    {
        result[i] = rand() % range + left; //生成范围在left ~ right 的随机数
    }
}

/**
 * @description: 
 * 均匀生成范围在[left, right) 的随机整型数组
 * @param {int} num 生成数量
 * @param {int} left 范围下界
 * @param {int} right 范围上界
 * @param {vector<int>} &result 结果数组
 * @return {*}
 */
void Random_Int(int num, int left, int right, vector<int> &result)
{
    std::random_device rd;                                         // Will be used to obtain a seed for the random number engine
    std::mt19937 engine{rd()};                                     // 标准的随机数生成器，使用随机种子rd()进行初始化
    std::uniform_int_distribution<> int_distribution{left, right}; // 生成在[left, right) 之间 均匀分布 的随机整型数

    result.clear();
    for (int i = 0; i < num; ++i)
    {
        result.push_back(int_distribution(engine));
    }
}

/**
 * @description: 
 * 均匀生成范围在[left, right) 的随机浮点数组
 * @param {int} num 生成数量
 * @param {int} left 范围下界
 * @param {int} right 范围上界
 * @param {vector<double>} &result 结果数组
 * @return {*}
 */
void Random_Real(int num, double left, double right, vector<double> &result)
{
    std::random_device rd;                                           // Will be used to obtain a seed for the random number engine
    std::mt19937 engine{rd()};                                       // 标准的随机数生成器，使用随机种子rd()进行初始化
    std::uniform_real_distribution<> real_distribution{left, right}; // 生成在[left, right) 之间 均匀分布 的随机浮点数

    result.clear();
    for (int i = 0; i < num; ++i)
    {
        result.push_back(real_distribution(engine));
    }
}

int main()
{
    int nums = 10, m = 10, n = 50;
    vector<int> result1(nums, 0);
    Random_Int(nums, m, n, result1);
    
    double l = 1.0, r = 2.0;
    vector<double> result2(nums, 0.0);
    Random_Real(nums, l, r, result2);

    for(auto num: result1)
    {
        cout << num << " ";
    }
    cout << endl;

    for(auto num: result2)
    {
        cout << num << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}