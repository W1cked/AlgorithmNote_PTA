#include<cstdio>
#include<algorithm>
using namespace std;

struct Fraction {
	long long int up;
	long long int down;
};

long long int gcd(long long int, long long int);
Fraction reduction(Fraction result);
Fraction add(Fraction f1, Fraction f2);
Fraction minus(Fraction f1, Fraction f2);
Fraction multiply(Fraction f1, Fraction f2);
Fraction divide(Fraction f1, Fraction f2);
void display(Fraction result);

int main() {
	
	Fraction number1, number2, result;
	scanf("%lld/%lld %lld/%lld", &number1.up, &number1.down, &number2.up, &number2.down);
	
	// Display addition
	display(number1);
	printf(" + ");
	display(number2);
	printf(" = ");
	display(add(number1, number2));
	printf("\n");
	
	// Display substraction
	display(number1);
	printf(" - ");
	display(number2);
	printf(" = ");
	display(minus(number1, number2));
	printf("\n");
	
	// Display multiplication
	display(number1);
	printf(" * ");
	display(number2);
	printf(" = ");
	display(multiply(number1, number2));
	printf("\n");
	
	// Display dividsion
	display(number1);
	printf(" / ");
	display(number2);
	printf(" = ");
	if(number2.up == 0) {
		printf("Inf\n");
	}
	else {
		display(divide(number1, number2));
		printf("\n");
	}
	
	return 0;
}

/*********************************************************/

long long int gcd(long long int m, long long int n) {
	if(n == 0)
		return m;
	else {
		int remainder;
		while(n) {
			remainder = m % n;
			m = n;
			n = remainder;
		}
		return m;
	}
}

Fraction reduction(Fraction result) {
	if(result.down < 0) {
		result.up = -result.up;
		result.down = -result.down;
	}
	
	if(result.up == 0) {
		result.down = 1;
	}
	else {
		int factor = gcd(abs(result.up), abs(result.down));
		result.up /= factor;
		result.down /= factor;
	}
	return result;
}

Fraction add(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = (f1.up * f2.down) + (f2.up * f1.down);
	result.down = f1.down * f2.down; 
	return reduction(result);
}

Fraction minus(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = (f1.up * f2.down) - (f2.up * f1.down);
	result.down = f1.down * f2.down;
	return reduction(result);
}

Fraction multiply(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.up;
	result.down = f1.down * f2.down;
	return reduction(result);
}

Fraction divide(Fraction f1, Fraction f2) {
	Fraction result;
	result.up = f1.up * f2.down;
	result.down = f1.down * f2.up;
	return reduction(result);
}

void display(Fraction result) {
	result = reduction(result);
	
	if(result.up < 0)
		printf("(");
	
	if(result.up == 0) {
		printf("0");
	}
	else if(result.down == 1) {	// Integar
		printf("%lld", result.up);
	}
	else if(abs(result.up) > abs(result.down)) {	// Virtual Fraction
		printf("%d %d/%d", result.up / result.down, abs(result.up) % result.down, result.down);
	}
	else {	// True Fraction
		printf("%d/%d", result.up, result.down);
	}
	
	if(result.up < 0)
		printf(")");
}
