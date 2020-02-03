#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std;

string unitDigit[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[13] = {"tret", "tam","hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

string numToStr[170];
map<string, int> strToNum;

void init() {
	for(int i = 0; i < 13; i++) {
		numToStr[i] = unitDigit[i];
		strToNum[unitDigit[i]] = i;
		numToStr[i * 13] = tenDigit[i];
		strToNum[tenDigit[i]] = i * 13;
	}
	for(int i = 1; i < 13; i++) {	// ten digit
		for(int j = 1; j < 13; j++) {	// unit digit
			string str = tenDigit[i] + " " + unitDigit[j];
			numToStr[i * 13 + j] = str;
			strToNum[str] = i * 13 + j;
		}
	}
}


int main() {
	int number;
	scanf("%d\n", &number);
	
	init();
	while(number--) {
		string input;
		getline(cin, input);
		
		if(input[0] >= '0' && input[0] <= '9') {
			int num = 0;
			for(int j = 0; j < input.length(); j++) {
				num = num * 10 + (input[j] - '0');
			}
			cout << numToStr[num] << endl;
		}
		else {
			cout << strToNum[input] << endl;
		}
	}
	
	return 0;
}
