#include<cstdio>

const int INF = 0x3fffffff;

int main() {
	// Input the data
	int number;
	int input[100001];
	scanf("%d", &number);
	for(int i = 0; i < number; i++) {
		scanf("%d", &input[i]);
	}
	
	// Analyze the leftMax and rightMin
	int leftMax[100001], rightMin[100001];

	leftMax[0] = 0;		// There is nothing bigger than input[0]
	for(int i = 1; i < number; i++) {
		if(leftMax[i - 1] > input[i - 1]) {
			leftMax[i] = leftMax[i - 1];
		}
		else {
			leftMax[i] = input[i - 1];
		}
	}
	
	rightMin[number - 1] = INF; 	// There is nothing smaller ther input[number - 1]
	for(int i = number - 2; i >= 0; i--) {
		if(rightMin[i + 1] > input[i + 1]) {
			rightMin[i] = input[i + 1];
		}
		else {
			rightMin[i] = rightMin[i + 1];
		}
	}
	
	int answer[100001] = {0};
	int counter = 0;	// Count the number of pivot
	for(int i = 0; i < number; i++) {
		if(leftMax[i] < input[i] && rightMin[i] > input[i]) {
			answer[counter] = input[i];
			counter++;
		}
	}
	
	// Display the result
	printf("%d\n", counter);
	for(int i = 0; i < counter; i++) {
		printf("%d", answer[i]);
		if(i != counter - 1) {
			printf(" ");
		}
	}
	printf("\n");
	
	return 0;
}
