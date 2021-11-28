/*
 * @Author: your name
 * @Date: 2021-11-28 16:28:27
 * @LastEditTime: 2021-11-28 20:03:20
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \code_notes\others\josephus\code.cpp
 */
/*
约瑟夫环
方法1：链表解法
方法2：递归解法
方法3（最优）：将递归改为递推
*/

#include<iostream>
#include<vector>

using namespace std;
/*
方法1：链表解法   代码略
缺点：
模拟整个游戏过程，时间复杂度高达O(nm)
当n，m非常大(例如上百万，上千万)的时候，几乎是没有办法在短时间内出结果的
*/
struct node{
	int number;
	node* next;
};


/*
方法2：递归解法
该函数每次可以求出第n次扔海里的人的编号, 编号范围：0 ~ (n-1)
person_num：总人数
k:每次最大报道的数
n:第n次，剩余需要被扔的人数
当person_num,n太大时，可能存在栈溢出，导致程序无法运行
*/
int josephus_recursion(int person_num, int k, int n){
	if (n == 1){
		return (person_num + k - 1) % person_num;
	}
	else{
		return (josephus_recursion(person_num - 1, k, n - 1) + k) % person_num;
	}
}

/*
方法3：将递归改为递推
*/
int josephus(int person_num, int k, int n){
	if (n == 1){
		return (person_num + k - 1) % person_num;
	}
	int cur_index = (person_num - n + k) % (person_num - n + 1);
	for (int i = 2; i <= n; i++){
		cur_index = (cur_index + k) % (person_num - n + i);
	}
	return cur_index;
}

int main() {
	int person_num = 10000, k = 4, n = 100;
	cout << "josephus_recursion" << endl;
	for (int i = 1; i <= n; i++){
		cout << josephus_recursion(person_num, k, i) << "  ";
	}
	cout << " " << endl;
	cout << "josephus" << endl;
	for (int i = 1; i <= n; i++){
		cout << josephus(person_num, k, i) << "  ";
	}
	system("pause");
	return 0;
}