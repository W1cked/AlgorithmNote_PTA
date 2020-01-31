#include<cstdio>
#include<cstring>

int main() {
	int number[10] = {0};
	char temp[1000];
	scanf("%s", temp);
	
	// Analize the data and store them into 2-D array
	for(int i = 0; i < strlen(temp); i++) {
		number[temp[i] - '0']++;
	}
	
	// Display the result
	for(int i = 0; i < 10; i++) {
		if(number[i] != 0) {
			printf("%d:%d\n", i, number[i]);
		}
	}
	
	return 0;
}
