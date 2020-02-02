#include<cstdio>
#include<cstring>

struct BigNumber {
	int number[1000];
	int length;
	
	// Constructor
	BigNumber() {
		memset(number, 0, sizeof(number));
		length = 0;
	}
};

BigNumber change(char* );
int compare(BigNumber, BigNumber);
BigNumber add(BigNumber, BigNumber);
BigNumber minus(BigNumber, BigNumber);
BigNumber multiply(BigNumber, int);
BigNumber divide(BigNumber, int, int&);

int remainder;

int main() {
	char input1[1000], input2[1000];
	printf("Enter 2 Integer: ");
	scanf("%s%s", input1, input2);
	
	BigNumber result;
	BigNumber a = change(input1);
	BigNumber b = change(input2);
	
	/** Test BigNumber addition */
	//result = add(a, b);
	
	/** Test BigNumber substration
	if(compare(a, b) >= 0) {
		result = minus(a, b);
	}
	else {
		result = minus(b, a);
		printf("-");
	}*/
	
	/** Test BigNumber multiplication in positive 
	// Convert the BigNumber b into a integer number
	int numberB = 0;
	for(int i = b.length - 1; i >= 0; i--) {
		numberB = numberB * 10 + b.number[i];
	}
	result = multiply(a, numberB);*/
	
	/** Test BigNumber division*/
	int numberB = 0;
	for(int i = b.length - 1; i >= 0; i--) {
		numberB = numberB * 10 + b.number[i];
	}
	
	result = divide(a, numberB, remainder);
	printf("remainder is: %d\n", remainder);
	
	
	// Display the result
	for(int i = result.length - 1; i >= 0; i--) {
		printf("%d", result.number[i]);
	}
	
	return 0;
}

/************************************************/

/*******************/
/* 	Input: A string
/* 	Output: A BigNumber object
/* 	Function: Turn the string into a big number.
/*******************/
BigNumber change(char* input) {
	BigNumber result;
	result.length = strlen(input);
	for(int i = 0; i < result.length; i++) {
		result.number[i] = input[result.length - 1 - i] - '0';
	}
	return result;
}

int compare(BigNumber a, BigNumber b) {
	if(a.length > b.length)
		return 1;
	else if(a.length < b.length)
		return -1;
	else {
		for(int i = a.length - 1; i >= 0; i--) {  // Compare from the low bit
			if(a.number[i] > b.number[i])
				return 1;
			else if(a.number[i] < b.number[i])
				return -1; 
		}
		return 0;
	}  
}

BigNumber add(BigNumber a, BigNumber b) {
	BigNumber result;
	int carry = 0;
	for(int i = 0; i < a.length || i < b.length; i++) {
		int temp = a.number[i] + b.number[i] + carry;
		result.number[result.length++] = temp % 10;
		carry = temp / 10;
	}
	if(carry != 0) {
		result.number[result.length++] = carry;
	}
	
	return result;
}

BigNumber minus(BigNumber a, BigNumber b) {
	BigNumber result;
	int borrow = 0;
	for(int i = 0; i < a.length || i < b.length; i++) {
		if(a.number[i] < b.number[i]) {
			a.number[i + 1]--;
			a.number[i] += 10;
		}
		result.number[result.length++] = a.number[i] - b.number[i];
	}
	//while() {
			
	//}
	
	return result;
}

BigNumber multiply(BigNumber a, int b) {
	BigNumber result;
	int carry = 0;
	for(int i = 0; i < a.length; i++) {
		int temp = a.number[i] * b + carry;
		result.number[result.length++] = temp % 10;
		carry = temp / 10;
	}
	while(carry != 0) {	// Carry may more than 1 bit
		result.number[result.length++] = carry % 10;
		carry /= 10;
	}
	
	return result;
}

BigNumber divide(BigNumber a, int b, int& remainder) {
	BigNumber result;
	result.length = a.length;	// Important step
	for(int i = a.length - 1; i >= 0; i--) {	// Start from high bit
		remainder = remainder * 10 + a.number[i];
		if(remainder < b)	// Unable to divide 
			result.number[i] = 0;
		else {	// enable to divide
			result.number[i] = remainder / b;
			remainder = remainder % b;
		}
	}
	// Remove the high bit 0, and make sure we have at least 1 bit
	while(result.length - 1 >= 1 && result.number[result.length - 1] == 0) {
		result.length--;
	}
	
	return result;
}

