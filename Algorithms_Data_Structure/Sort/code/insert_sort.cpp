#include <iostream>
#include <vector>
/**
插入排序
*/
using namespace std;

void InsertSort(vector<int> &arr){
	int n = arr.size();
	for (int i = 1; i < n; ++i){
		int inserted = arr[i];
		int j;
		for (j = i; j > 0 && inserted < arr[j - 1]; --j){
			arr[j] = arr[j - 1];
		}
		arr[j] = inserted;
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
	InsertSort(nums);
	system("pause");
	return 0;
}