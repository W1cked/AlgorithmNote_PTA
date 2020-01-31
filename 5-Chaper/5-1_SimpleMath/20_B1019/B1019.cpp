#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

bool cmp(char a, char b) {
	return a > b;
}

int to_number(int* input) {
	int number = 0;
	for(int i = 0; i < 4; i++) {
		number = number * 10 + input[i];
	}
	return number;
}

void to_array(int result, int* input) {
	for(int i = 0; i < 4; i++) {
		input[i] = result % 10;
		result /= 10;
	}
}

int main() {
	// Input the data
	int input[1001];
	int inputNumber, MIN, MAX;	
	scanf("%d", &inputNumber);
	
	while(1) {
		to_array(inputNumber, input);
		sort(input, input + 4);
		MIN = to_number(input);
		
		sort(input, input + 4, cmp);
		MAX = to_number(input);
		
		inputNumber = MAX - MIN;
		printf("%04d - %04d = %04d\n", MAX, MIN, inputNumber);
		
		if(inputNumber == 0 || inputNumber == 6174) {
			break;
		}
	}
	
	return 0;
}
