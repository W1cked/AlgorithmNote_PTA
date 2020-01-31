#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	
	int N, arr[1000];
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	
	//Compute A1
	int A1 = 0;
	for(int i = 0; i < N; i++) {
		if(arr[i] % 5 == 0 && arr[i] % 2 == 0) {
			A1 += arr[i];
		}
	}
	if(A1 != 0) {
		printf("%d ", A1);
	}
	else {
		printf("N ");
	}
	
	//Compute A2
	int A2 = 0, j = 1;
	int a2[1000] = {0};
	for(int i = 0; i < N; i++) {
		//Save the number into a new array
		if(arr[i] % 5 == 1) {
			a2[j] = arr[i];
			j++;
		}
	}
	//Find the satisfied conditions.
	for(int i = 1; i <= N; i++) {
		//Odd index
		if(i % 2 != 0) {
			A2 += a2[i];
		}
		
		//Even index
		if(i % 2 == 0) {
			A2 -= a2[i];
		}
	}
	if(A2 != 0) {
		printf("%d ", A2);
	}
	else {
		printf("N ");
	}
	
	//Compute A3
	int A3 = 0;
	for(int i = 0; i < N; i++) {
		if(arr[i] % 5 == 2) {
			A3++;
		}
	}
	if(A3 != 0) {
		printf("%d ", A3);
	}
	else {
		printf("N ");
	}
		
	//Compute A4
	double A4 = 0;
	int countA4 = 0;
	for(int i = 0; i < N; i++) {
		if(arr[i] % 5 == 3) {
			A4 += arr[i];
			countA4++;
		}
	}
	if(A4 != 0) {
		printf("%.1f ", A4 / countA4);
	}
	else {
		printf("N ");
	}
	
	//Compute A5
	int countA5 = 0;
	int a5[1000] = {0};
	j = 0;
	for(int i = 0; i < N; i++) {
		if(arr[i] % 5 == 4) {
			a5[j] = arr[i];
			countA5++;
		}
	}
	if(countA5 != 0) {
		sort(a5, a5 + countA5 + 1);
		printf("%d", a5[countA5]);
	}
	else {
		printf("N");
	}
	
	return 0;
}
