/*
输入: (2 -> 4 -> 3) + (5 -> 6 -> 4)
输出: 7 -> 0 -> 8
原因：342 + 465 = 807
*/
#include<iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* result = new ListNode(0);
		ListNode* next = result;
		int carry = 0; //进位数
		int var_a, var_b, var;
		while (true) {
			var_a = l1 == NULL ? 0 : (*l1).val;
			var_b = l2 == NULL ? 0 : (*l2).val;
			var = var_a + var_b + carry;
			if (var >= 10) {
				var = var % 10;
				carry = 1;
			}
			else {
				carry = 0;
			}
			(*next).next = new ListNode(var);
			next = (*next).next;
			l1 = l1 == NULL ? NULL : (*l1).next;
			l2 = l2 == NULL ? NULL : (*l2).next;
			if (l1 == NULL && carry == 0){
				(*next).next = l2;
				break;
			}
			if (l2 == NULL && carry == 0){
				(*next).next = l1;
				break;
			}
		}
		return (*result).next;
	}
};

int main(){
	//构造两个链表
	int nums1[3] = { 2, 4, 3 };
	int nums2[3] = { 5, 6, 4 };
	ListNode* l1 = new ListNode(0); //表头
	ListNode* l2 = new ListNode(0);
	ListNode* l1_next = l1; //尾指针
	ListNode* l2_next = l2;
	for (size_t i = 0; i < 3; i++)
	{
		(*l1_next).next = new ListNode(nums1[i]);
		l1_next = (*l1_next).next; //移动尾指针
		(*l2_next).next = new ListNode(nums2[i]);
		l2_next = (*l2_next).next;
	}
	ListNode* p1 = l1;
	ListNode* p2 = l2;
	l1 = (*l1).next; //移除空表头
	l2 = (*l2).next;
	free(p1);
	free(p2);

	Solution s;
	ListNode* result = s.addTwoNumbers(l1, l2);

	while (result != NULL){
		cout << (*result).val << "  ";
		result = (*result).next;
	}

	system("pause");
	return 0;
}