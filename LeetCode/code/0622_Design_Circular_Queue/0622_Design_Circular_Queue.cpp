/*
队列：尾部入队，头部出队
*/
#include<iostream>
#include<vector>

using namespace std;

class MyCircularQueue {
private:
	vector<int> data;
	int head;
	int tail;
public:
	MyCircularQueue(int k) {
		data.resize(k, 0);
		head = -1;
		tail = -1;
	}

	bool enQueue(int value) {
		if (isFull() == true) return false;
		if (isEmpty() == true) {
			head = 0;
			tail = 0;
		}
		else{
			tail += 1;
			if (tail > data.size() - 1) tail = 0;
		}
		data[tail] = value;
		return true;
	}

	bool deQueue() {
		if (isEmpty() == true) return false;
		if (head == tail){
			tail = -1;
			head = -1;
		}
		else{
			head += 1;
			if (head > data.size() - 1) head = 0;
		}
		return true;
	}

	int Front() {
		if (isEmpty() == true) return -1;
		return data[head];
	}

	int Rear() {
		if (isEmpty() == true) return -1;
		return data[tail];
	}

	bool isEmpty() {
		return (head == -1 && tail == -1);
	}

	bool isFull() {
		int value = tail - head;
		return (value == -1 || value == data.size() - 1);
	}
};

int main(){
	MyCircularQueue circularQueue(3); // 设置长度为 3

	circularQueue.enQueue(1); // 返回 true
	
	circularQueue.enQueue(2); // 返回 true

	circularQueue.enQueue(3); // 返回 true

	circularQueue.enQueue(4); // 返回 false，队列已满

	circularQueue.Rear(); // 返回 3

	circularQueue.isFull(); // 返回 true

	circularQueue.deQueue(); // 返回 true

	circularQueue.enQueue(4); // 返回 true

	circularQueue.Rear(); // 返回 4

	system("pause");
	return 0;
}