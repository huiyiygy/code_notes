/*
输入: "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
*/
#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> hashmap;
		hashmap['I'] = 1;
		hashmap['V'] = 5;
		hashmap['X'] = 10;
		hashmap['L'] = 50;
		hashmap['C'] = 100;
		hashmap['D'] = 500;
		hashmap['M'] = 1000;
		int len = s.length();
		int result = 0;
		for (int i = 0; i < len; i++) {
			if (i < len - 1 && hashmap[s[i]]<hashmap[s[i + 1]]) {
				result -= hashmap[s[i]];
			}
			else {
				result += hashmap[s[i]];
			}
		}
		return result;
	}
};

int main(){
	string a = "MCMXCIV";
	Solution s;
	int result = s.romanToInt(a);
	cout << result << endl;

	system("pause");
	return 0;
}