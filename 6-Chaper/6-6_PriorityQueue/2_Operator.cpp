#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct fruit {
	string name;
	int price;
	/**
	friend bool operator < (fruit f1, fruit f2) {
		return f1.price > f2.price;
	}*/
}f1, f2, f3;

struct cmp {
	bool operator() (fruit f1, fruit f2) {
		return f1.price > f2.price;
	}
};

int main() {
	//priority_queue<fruit> testQueue;
	priority_queue<fruit, vector<fruit>, cmp> testQueue;
	f1.name = "Peach";
	f1.price = 3;
	f2.name = "Pear";
	f2.price = 4;
	f3.name = "Apple";
	f3.price = 1;
	
	testQueue.push(f1);
	testQueue.push(f2);
	testQueue.push(f3);
	
	cout << testQueue.top().name << " " << testQueue.top().price << endl;
	
	return 0;
}
