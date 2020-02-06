#include<cstdio>
#include<cstring>

struct BigNumber {
	int num[1001];
	int length;
	BigNumber() {
		length = 0;
		memset(num, 0, sizeof(num));
	}
};

BigNumber change(char* input) {
	BigNumber result;
	result.length = strlen(input);
	for(int i = 0; i < strlen(input); i++) {
		result.num[i] = input[strlen(input) - 1 - i] - '0';
	}
	return result;
}

BigNumber multiply(BigNumber a, int b) {
	BigNumber result;
	int carry = 0;
	for(int i = 0; i < a.length; i++) {
		int temp = a.num[i] * b + carry;
		result.num[result.length++] = temp % 10;
		carry = temp / 10;
	}
	while(carry != 0) {
		result.num[result.length++] = carry % 10;
		carry /= 10;
	}
	
	return result;
}

int main() {
	char input[21];
	scanf("%s", input);
	
	BigNumber source = change(input);
	BigNumber result = multiply(source, 2);
	
	if(result.length != source.length) {
		printf("No\n");
	}
	else {
		bool noFlag = false;
		int testArray[10] = {0};
		for(int i = 0; i < source.length; i++) {
			testArray[source.num[i]]++;
		}
		for(int i = 0; i < result.length; i++) {
			testArray[result.num[i]]--;
		}
		for(int i = 0; i < 10; i++) {
			if(testArray[i] != 0) {
				printf("No\n");
				noFlag = true;
				break;
			}
		}
		if(noFlag == false)
			printf("Yes\n");
	}
	
	for(int i = result.length - 1; i >= 0; i--) {
		printf("%d", result.num[i]);
	}
	
	return 0;
}
