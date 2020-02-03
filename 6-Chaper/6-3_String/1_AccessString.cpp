#include<cstdio>
#include<string>
using namespace std;

int main() {
	string str = "abcd";
	
	/** Access by index */
	for(int i = 0; i < str.length(); i++) {
		printf("%c\n", str[i]);
	}
	
	/** Output the object by convert it into a c_string */
	printf("%s\n", str.c_str());
	
	/** Access by iterator */
	for(string::iterator it = str.begin(); it != str.end(); it++) {
		printf("%c#", *it);
	}
	
	
	return 0;
}
