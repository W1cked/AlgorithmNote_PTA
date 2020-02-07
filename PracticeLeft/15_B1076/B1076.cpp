#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main() {
	int number;
	scanf("%d\n", &number);	
	
	char input[50];
	int password[101] = {0};
	for(int i = 0; i < number; i++) {
		cin.getline(input, 50);
		for(int j = 0; j < strlen(input); j++) {
			if(input[j] == 'T') {
				password[i] = input[j - 2] - 'A' + 1;		
			}
		}
	}
	
	for(int i = 0; i < number; i++) {
		printf("%d", password[i]);
	}
	
	return 0;
}
