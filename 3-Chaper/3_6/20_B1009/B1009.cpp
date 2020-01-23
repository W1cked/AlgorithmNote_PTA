#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main() {
	
	char str[81];
	cin.getline(str, 81);
	
	int length = strlen(str);
	int row = 0, col = 0;
	
	// Partition
	char word[81][81];
	for(int i = 0; i < length; i++) {
		if(str[i] == ' ') {
			word[row][col] = '\0';
			row++;
			col = 0;
		}
		else {
			word[row][col] = str[i];
			col++;
		}
	}
	
	// Display the string
	for(int i = row; i >= 0; i--) {
		printf("%s", word[i]);
		if(i != 0) {
			printf(" ");
		}
	}
	
	return 0;
}
