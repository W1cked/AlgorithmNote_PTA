#include<cstdio>

int main() {
	
	int number;
	scanf("%d", &number);
	
	double sum = 0;
	for(int i = 1; i <= number; i++) {
		double value;
		scanf("%lf", &value);
		sum += value * (number - i + 1) * i;
	}
	printf("%.2f", sum);
	
	return 0;
}
