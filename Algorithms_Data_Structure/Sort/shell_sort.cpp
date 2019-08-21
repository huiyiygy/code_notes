#include <iostream>
#include <vector>
/**
ϣ������
*/
using namespace std;

void ShellSort(vector<int> &arr){
	//�����������У�1��4��13��40, 121...
	int n = arr.size();
	int h = 1;
	while (h < n / 3 - 1){
		h = h * 3 + 1;
	}
	while (h >= 1){
		// h-sort the array
		for (int i = h; i < n; ++i){
			//��arr[i], arr[i-h], arr[i-2h]...ʹ�ò�������
			int inserted = arr[i];
			int j;
			for (j = i; j >= h && inserted < arr[j - h]; j-=h){
				arr[j] = arr[j-h];
			}
			arr[j] = inserted;
		}
		h /= 3;
		//ÿ���������������鿴���
		cout << "-----------------------" << endl;
		for (int k = 0; k < n; ++k){
			cout << arr[k] << "  ";
		}
		cout << "  " << endl;
	}
}

int main(){
	vector<int> nums = { 5, 8, 9, 26497, 4, 5, 6, 8, 741, 3, 4968, 4, 9, 76, 43, 1, 86, 2149, 7, 6, 789, 45, 13, 789, 15, 46, 26497, 46578, 4968, 684897 };
	ShellSort(nums);
	system("pause");
	return 0;
}