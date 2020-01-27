#include<cstdio>
#include<cstring>

int main() {
	int ASCII[128] = {0};
	char tempChar;
	while((tempChar = getchar()) != '\n') {
		if(tempChar >= 'A' && tempChar <= 'Z') {
			tempChar = tempChar - 'A';
			ASCII[tempChar]++;
		}
		else if(tempChar >= 'a' && tempChar <= 'z') {
			tempChar = tempChar - 'a';
			ASCII[tempChar]++;
		}
	}
	
	int index = 0;
	for(int i = 0; i < 128; i++) {
		if(ASCII[i] > ASCII[index]) {
			index = i;
		}
	}
	
	printf("%c %d", index + 'a', ASCII[index]);
	
	return 0;
}
