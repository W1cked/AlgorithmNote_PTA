#include<cmath>
#include<iostream>
using namespace std;

int main() {
	int number;
	scanf("%d", &number);
	
	int count[10001] = {0};
	for(int i = 0; i < number; i++) {
		int temp;
		scanf("%d", &temp);
		
		count[abs((i + 1) - temp)]++;
		
	}
	
	for(int i = 10000; i >= 0; i--) {
		if(count[i] > 1)
			printf("%d %d\n", i, count[i]);
	}
	
	return 0;
}
