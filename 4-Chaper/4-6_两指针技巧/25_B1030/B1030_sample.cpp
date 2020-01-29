#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int number, p;
	scanf("%d%d", &number, &p);
	
	long long int A[100001];
	for(int i = 0; i < number; i++) {
		scanf("%lld", &A[i]);
	}
	
	sort(A, A + number);
	
	// Count the number of perfect array
	int firstIndex = 0, lastIndex = 0, counter = 0;
	while(firstIndex < number && lastIndex < number) {
		// Keep moving the lastIndex till the end
		while(lastIndex < number && A[lastIndex] <= A[firstIndex] * p) {
			lastIndex++;
		}
		if(counter < lastIndex - firstIndex) {	// Update the counter
			counter = lastIndex - firstIndex;
		}
		firstIndex++;
	}
	
	printf("%d", counter);
	
	return 0;
}
