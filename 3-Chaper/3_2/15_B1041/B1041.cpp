#include<cstdio>

int main() {
	int N;
	scanf("%d", &N);
	// input the student information 
	long long int stuID[1001] = {0};
	int testID[1001] = {0}, examID[1001] = {0};
	for(int i = 0; i < N; i++) {
		scanf("%lld", &stuID[i]);
		scanf("%d%d", &testID[i], &examID[i]);
	}
	
	// Input the number needed to search
	int searchNumber = 0;
	scanf("%d", &searchNumber);
	
	// Input the test ID
	int searchID = 0;
	for(int i = 0; i < searchNumber; i++) {
		scanf("%d", &searchID);
		for(int j = 0; j < N; j++) {
			if(searchID == testID[j]) {
				printf("%lld %d\n", stuID[j], examID[j]);
			}
		}
	}
	
	return 0;
}
