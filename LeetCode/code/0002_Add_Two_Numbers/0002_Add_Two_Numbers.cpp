/*
输入: (2 -> 4 -> 3) + (5 -> 6 -> 4)
输出: 7 -> 0 -> 8
原因：342 + 465 = 807
*/
#include<iostream>
#include <memory>
#include <vector>

using namespace std;

// 单链表
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct ListNode_cpp {
    int val;
    std::shared_ptr<ListNode_cpp> next;
    ListNode_cpp() : val(0), next(nullptr) {}
    ListNode_cpp(int x) : val(x), next(nullptr) {}
    ListNode_cpp(int x, std::shared_ptr<ListNode_cpp> other) : val(x), next(other) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(0);
		ListNode* result = head;
		//  var_a var_b 两个输入的值，sum 两数和，carry 进位数
		int var_a = 0, var_b = 0, sum = 0, carry = 0;
		while (true) {
			var_a = l1 == nullptr ? 0 : l1->val;
			var_b = l2 == nullptr ? 0 : l2->val;
			sum = var_a + var_b + carry;
			if (sum >= 10) {
				sum %= 10;
				carry = 1;
			}
			else {
				carry = 0;
			}
			result->next = new ListNode(sum);
			result = result->next;
			l1 = l1 == nullptr ? nullptr : l1->next;
			l2 = l2 == nullptr ? nullptr : l2->next;
			if (l1 == nullptr && carry == 0){
				result->next = l2;
				break;
			}
			else if (l2 == nullptr && carry == 0){
				result->next = l1;
				break;
			}
		}
		return head->next;
	}
};

int main(){
	//构造两个链表
	vector<int> m = {9, 8, 7, 6, 5, 4, 3};
	vector<int> n = {0, 1, 2};  // result = {9, 9, 9, 6, 5, 4, 3}
	ListNode *input_1 = nullptr, *input_2 = nullptr, *result = nullptr, *temp = nullptr;
    // 数组逆序遍历，初始化输入链表
    for (int i = m.size() -1; i >=0 ; i--)
    {
        input_1 = new ListNode(m[i], input_1);
    }
    for (int i = n.size() -1; i >=0 ; i--)
    {
        input_2 = new ListNode(n[i], input_2);
    }

	Solution s;
	result = s.addTwoNumbers(input_1, input_2);

	// 打印结果
	while (result != nullptr){
		cout << result->val << "  ";
		result = result->next;
	}
	// 释放手动申请的内存
    while(input_1 != nullptr)
    {
        temp = input_1->next;
        delete input_1;
        input_1 = nullptr;
        input_1 = temp;
    }
    while(input_2 != nullptr)
    {
        temp = input_2->next;
        delete input_2;
        input_2 = nullptr;
        input_2 = temp;
    }
    while(result != nullptr)
    {
        temp = result->next;
        delete result;
        result = nullptr;
        result = temp;
    }

	system("pause");
	return 0;
}