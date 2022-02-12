/*
 * @Author: huiyiygy
 * @Date: 2022-02-06 18:32:39
 * @LastEditors: huiyiygy
 * @LastEditTime: 2022-02-12 15:02:08
 * @Description: 
 * 题目
 * 只包含小写字母的两个字符串A，B。每次移动B中任意一个字符到最后一位，经过若干次移动后，若能使两字符串相等A=B，则输出B最少需要移动的次数。若不能，输出-1。
 * 
 * 如：A = "ckad", B = "acdk" 至少需要移动 2 次B中的字符
 * 
 * 思路 
 * 按照A中字符的顺序，去B中找，记录按顺序找到的个数，
 * 若下一个字符在后续剩余字符中找不到，则 总数 - 找到的个数 = 最少需要移动的次数
 */
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

/**
 * @description: 
 * 时间复杂度O(nlog(n)mlog(m))，空间复杂度O(1)，m,n分别表示两个字符串长度
 * @param {string} a
 * @param {string} b
 * @return {*}
 */
int moveCount(string a, string b)
{
    if(a == b) return 0;
    string temp_a = a, temp_b = b;
    sort(temp_a.begin(), temp_a.end());
    sort(temp_b.begin(), temp_b.end());
    // 判断两个字符串是否包含相同的字符
    if(temp_a != temp_b) return -1;

    int pos = 0;
    for (auto c : b)
    {
        if(a[pos] == c)
            pos++;
    }
    return a.size() - pos;
}

int main() {
    // A = "abcabc", B = "cabacb";  // result = 3
    // A = "ckad", B = "acdk";  // result = 2
    // A = "hahahaha", B = "ahahahah";  // result = 1
    string A, B;
    cin >> A;
    cin >> B;
    int result = moveCount(A, B);
    cout << result << endl;
    system("pause");
    return 0;
}