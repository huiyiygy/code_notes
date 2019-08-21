#include <iostream>
#include <vector>
/**
冒泡排序
*/
using namespace std;

void BubbleSort(vector<int> &arr){
	int n = arr.size();
	for (int i = 0; i < n - 1; ++i){
		for (int j = 0; j < n - i - 1; ++j) {
			// 两两相邻元素比较大小，从小到大排序
			// if (list[j] < list[j + 1]) : 从大到小排序
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	//输出最后的排序结果
	cout << "-----------------------" << endl;
	for (int k = 0; k < n; ++k){
		cout << arr[k] << "  ";
	}
	cout << "  " << endl;
}

int main(){
	vector<int> nums = { 5, 8, 9, 26497, 4, 5, 6, 8, 741, 3, 4968, 4, 9, 76, 43, 1, 86, 2149, 7, 6, 46578, 4968, 684897 };
	BubbleSort(nums);
	system("pause");
	return 0;
}