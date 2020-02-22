#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

int main() {
	
	int number;
	scanf("%d\n", &number);
	
	for(int i = 0; i < number; i++) {
		char password[101];
		cin.getline(password, 101);	// Important line
		
		/** index 0 is Letter; index 1 is integer; index 2 is '.';
		   index 3 is others*/
		int charCount[4] = {0};
		   
		if(strlen(password) < 6) {	// length is not enough
			printf("Your password is tai duan le.\n");
			continue;
		}
		else {	// length is enough
			for(int j = 0; j < strlen(password); j++) {
				if(password[j] >= '0' && password[j] <= '9') {
					charCount[1]++;
				}
				else if((password[j] >= 'A' && password[j] <= 'Z') || 
					(password[j] >= 'a' && password[j] <= 'z')) {
					charCount[0]++;
				}
				else if(password[j] == '.') {
					charCount[2]++;
				}
				else {
					charCount[3]++;
				}
			}
			
			if(charCount[3]) {
				printf("Your password is tai luan le.\n");
			}
			else if(charCount[1] == 0) {
				printf("Your password needs shu zi.\n");
			}
			else if(charCount[0] == 0) {
				printf("Your password needs zi mu.\n");
			}
			else {
				printf("Your password is wan mei.\n");
			}
		}
	}
	
	
	return 0;
}
