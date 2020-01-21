#include<cstdio>

int main() {
	
	long long int A, B;
	int DA = 0, DB = 0;
	
	//Input the number
	scanf("%lld%d%lld%d", &A, &DA, &B, &DB);
	
	//Scan every bit of number
	int PA = 0, PB = 0;
	while(A != 0) {
		if(A % 10 == DA) {
			PA = PA * 10 + DA;
		}
		A = A / 10;
	}
	
	while(B != 0) {
		if(B % 10 == DB) {
			PB = PB * 10 + DB;
		}
		B = B / 10;
	}
	
	printf("%d", PB + PA);
	
	return 0;
}
