#include<cstdio>
#include<cstring>

struct BigNumber {
	int number[1001];
	int length;
	
	BigNumber() {	// Constructor
		length = 0;
		memset(number, 0, sizeof(number));
	}
};

BigNumber change(char*);
BigNumber divide(BigNumber, int, int&);

int main() {
	char input1[1001];
	int B;
	scanf("%s%d", input1, &B);
	
	int remainder = 0;
	BigNumber A = change(input1);
	BigNumber result = divide(A, B, remainder);
	
	// Display the result
	for(int i = result.length - 1; i >= 0; i--) {
		printf("%d", result.number[i]);
	}
	printf(" %d", remainder);
	
	return 0;
}

/*********************************************/

BigNumber change(char* input) {
	BigNumber result;
	result.length = strlen(input);
	
	for(int i = 0; i < result.length; i++) {
		result.number[i] = input[result.length - 1 -i] - '0';
	}
	
	return result;
}

BigNumber divide(BigNumber a, int b, int& remainder) {
	BigNumber result;
	result.length = a.length;
	
	for(int i = a.length - 1; i >= 0; i--) {
		remainder = remainder * 10 + a.number[i];
		if(remainder < b) {	// Unable to divide
			result.number[i] = 0;
		}
		else {	// Enable to divide
			result.number[i] = remainder / b;
			remainder = remainder % b;
		}
	}
	while(result.length - 1 >= 1 && result.number[result.length - 1] == 0) {
		result.length--;
	}
	return result;
}

