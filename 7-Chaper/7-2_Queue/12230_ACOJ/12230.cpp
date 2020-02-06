#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

struct Birthday {
	int month;
	int day;
};

int main() {
	
	int number;
	scanf("%d\n", &number);
	
	Birthday birthday[number];
	for(int i = 0; i < number; i++) {
		string input;
		getline(cin, input);
		
		birthday[i].month = (input[2] - '0') * 10 + input[6] - '0';
		birthday[i].day = (input[10] - '0') * 10 + input[14] - '0';
		
	}
	
	for(int i = 0; i < number; i++) {
		printf("%02d %02d\n", birthday[i].month, birthday[i].day);
	}
	
	return 0;
}
