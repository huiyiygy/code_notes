/*
输入: 120
输出: 21
*/
#include<iostream>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		int rev = 0;
		while (x != 0) {
			int pop = x % 10;
			x = x / 10;
			if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop >= 7)) {
				return 0;
			}
			if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop <= -8)) {
				return 0;
			}
			rev = rev * 10 + pop;
		}
		return rev;
	}
};

int main(){
	int nums = 902569;
	Solution s;
	int result = s.reverse(nums);
	cout << result << endl;
	system("pause");
	return 0;
}