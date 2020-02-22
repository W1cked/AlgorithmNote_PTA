#include<stdio.h>
using namespace std;

int main() {
	
	char answer[1000001];
	int length = 0;
	int ASCII[128] = {0};
	char tempChar;
	
	while((scanf("%c", &tempChar)) != EOF) {
		if(ASCII[tempChar] == 0 && tempChar != '\n') {
			ASCII[tempChar]++;
			answer[length++] = tempChar;
		}
		else {
			continue;
		}
	}
	for(int i = 0; i < length; i++) {
		putchar(answer[i]);
	}
	
	return 0;
}
