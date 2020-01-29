#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	
	// Input the data
	int number, p;
	scanf("%d%d", &number, &p);
	long long int data[100000];
	for(int i = 0; i < number; i++) {
		scanf("%lld", &data[i]);
	}
	
	// Sort the array
	sort(data, data + number);
	
	// Find the max length
	int firstIndex, lastIndex, maxLength = 0;
	for(firstIndex = 0, lastIndex = 0; lastIndex < number && maxLength < number - firstIndex; firstIndex++) {
		while(lastIndex < number && data[lastIndex] <= data[firstIndex] * p) {
			lastIndex++;
		}
		if(maxLength < lastIndex - firstIndex) {
			maxLength = lastIndex - firstIndex;
		}
	}
	
	// Display the result
	printf("%d", maxLength);
	
	return 0;
}
