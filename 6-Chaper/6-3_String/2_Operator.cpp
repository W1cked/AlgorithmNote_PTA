#include<iostream>
#include<string>
using namespace std;

int main() {
	
	string str1 = "abc";
	string str2 = "xyz";
	string result;
	
	result = str1 + str2;
	str1 += str2;
	
	cout << str1 << endl;
	cout << result << endl;
	cout << "The length of result is: " << result.length();
	
	return 0;
}
