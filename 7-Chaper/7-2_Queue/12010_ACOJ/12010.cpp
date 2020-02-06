#include<iostream>
#include<queue>
using namespace std;

int main() {
	int number;
	cin >> number;
	
	// Input the QQ number
	queue<int> input;
	for(int i = 0; i < number; i++) {
		int temp;
		cin >> temp;
		input.push(temp);
	}
	
	// Decrypt the QQ number
	queue<int> answer;
	while(input.size()) {
		int tempPop = input.front();
		answer.push(tempPop);
		input.pop();
		
		tempPop = input.front();
		input.push(tempPop);
		input.pop();
	}
	
	// Display the result
	while(answer.size()) {
		cout << answer.front() << " ";
		answer.pop();
	}
	
	return 0;
}
