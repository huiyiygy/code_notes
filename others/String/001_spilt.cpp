/*
 * @Author: huiyiygy
 * @Date: 2022-02-09 16:42:50
 * @LastEditors: huiyiygy
 * @LastEditTime: 2022-02-09 18:05:35
 * @Description: 字符串拆分，手动实现string 的spilt()，当做后续的工具函数
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @description: 
 * 根据 target_str 字符串，切分string，输出结果中不包含目标字符串
 * 兼容最前/最后存在目标字符的情况
 * @param {string} str 待切分字符
 * @param {vector<string>} &sub_str  切分结果
 * @param {string} target_str 切分依据
 * @return {*}
 */
vector<string> spilt(string str, string target_str)
{
    vector<string> sub_str;
	size_t str_length = str.size(), target_len = target_str.size();
    
	if (str_length < 1) 
        return sub_str;

	size_t pos = 0, curpos = 0;
	while (pos < str_length)
	{
		curpos = pos;
		pos = str.find(target_str, curpos);
		if (pos == string::npos)
		{
			pos = str_length;
		}
        string sub = str.substr(curpos, pos - curpos);
        if(sub.size() > 0) // 当str最前包含 或 连续重复出现 目标字符串时，去除空串
        {
            sub_str.push_back(sub);
        }
		pos += target_len;
	}
    return sub_str;
}


int main() {
    string A = "1, 2, 3, 4, 5", B = ", "; // result = {"1", "2", "3", "4", "5"}
    vector<string> result = spilt(A, B);
    for (auto str : result)
    {
        cout << str << endl;
    }
    system("pause");
    return 0;
}