/*
输入: -121
输出: false
*/
#include<iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || (x % 10 == 0 && x != 0)) {
			return false;
		}
		int reverse_number = 0;
		while (x > reverse_number) {
			int pop = x % 10;
			reverse_number = reverse_number * 10 + pop;
			x = x / 10;
		}
		if (x == reverse_number || x == reverse_number / 10) {
			return true;
		}
		else {
			return false;
		}
	}
};

int main(){
	int nums = 902569;
	Solution s;
	bool result = s.isPalindrome(nums);
	if (result){
		cout << "true" << endl;
	} else{
		cout << "false" << endl;
	}
	system("pause");
	return 0;
}