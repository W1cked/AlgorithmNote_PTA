#include<iostream>
#include<cstdio>
#include<string>
#include<queue>
using namespace std;

int main() {
	
	int number;
	scanf("%d\n", &number);
	
	queue<int> myQueue;
	while(number--) {
		string input;
		getline(cin, input);
		
		if(input[0] == 'O') {
			myQueue.pop();
		}
		else {
			int num = 0;
			for(int i = 2; i < input.length(); i++) {
				num = num * 10 + (input[i] - '0');
			}
			myQueue.push(num);
		}
	}
	
	// Display the result
	while(myQueue.size()) {
		cout << myQueue.front() << " ";
		myQueue.pop();
	}
	
	return 0;
}
