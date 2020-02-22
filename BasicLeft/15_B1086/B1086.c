#include<stdio.h>
#include<string.h>

int main() {
	
	long long int A, B;
	scanf("%lld%lld", &A, &B);
	
	long long int sum = A * B;
	if(sum == 0) {
		printf("0");
		return 0;
	}
	int flag = 0;
	while(sum) {
		if(sum % 10 > 0)	/** Don't display the head zero */
			flag++;			/** For example, 123000 is displayed in 321 */
		if(flag > 0)
			printf("%d", sum % 10);
		sum /= 10; 
	}
	
	return 0;
}
