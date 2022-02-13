/*
 * @Author: huiyiygy
 * @Date: 2022-02-10 18:08:09
 * @LastEditors: huiyiygy
 * @LastEditTime: 2022-02-14 00:48:05
 * @Description:
 */
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <random>
#include <vector>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif
#ifndef M_PIl
#define M_PIl (3.14159265358979323846264338327950288)
#endif

using namespace std;

class Solution
{
public:
    double r, x, y;

    Solution(double radius, double x_center, double y_center) : r(radius), x(x_center), y(y_center) {}

    /**
     * @description:
     * 解法一：
     * 利用随机数，生成在[-r, r] 正方形内的点，判断是否在圆内
     * 时间复杂度O(1)，最坏O(∞)，空间复杂度O(1)
     * Runtime: 107 ms, faster than 60.95%
     * Memory Usage: 26.9 MB, less than 97.89%
     * @param {*}
     * @return {*}
     */
    vector<double> randPoint_1()
    {
        while (true)
        {
            // 生成[-r, r] 之间的随机数
            double x1 = (2 * (double)rand() / RAND_MAX - 1.0) * r;
            double y1 = (2 * (double)rand() / RAND_MAX - 1.0) * r;
            // 判断点是否在以(0,0)为圆心，半径为r的圆内
            if (pow(x1, 2) + pow(y1, 2) <= pow(r, 2))
                return {x + x1, y + y1}; // 将点平移到真实圆心(x, y)处
        }
    }

    random_device rd;                                        // Will be used to obtain a seed for the random number engine
    mt19937 engine{rd()};                                    // 标准的随机数生成器，使用随机种子rd()进行初始化
    uniform_real_distribution<> real_distribution{0.0, 1.0}; // 生成在[left, right) 之间 均匀分布 的随机浮点数

    /**
     * @description:
     * 解法二：
     * 利用弧度制
     * 时间复杂度O(1)，空间复杂度O(1)
     * Runtime: 108 ms, faster than 60.42%
     * Memory Usage: 27.5 MB, less than 11.35%
     * @param {*}
     * @return {*}
     */
    vector<double> randPoint_2()
    {
        double distance = r * sqrt(real_distribution(engine));
        double theta = real_distribution(engine) * (2 * M_PI);
        return {distance * cos(theta) + x, distance * sin(theta) + y};
    }
};

int main()
{
    Solution s(5.0, 5.0, 6.0);
    vector<double> point = s.randPoint_1();
    printf("%f, %f\n", point[0], point[1]);
    system("pause");
    return 0;
}