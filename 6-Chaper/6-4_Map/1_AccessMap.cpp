#include<cstdio>
#include<map>
using namespace std;

int main() {
	
	map<char, int> mp;
	
	/** Access by index 
	mp['c'] = 20;
	mp['c'] = 30;	// Override
	printf("%d\n", mp['c']);
	*/
	
	/** Access by iterator */
	mp['m'] = 20;
	mp['r'] = 30;
	mp['a'] = 40;
	
	for(map<char, int>::iterator it = mp.begin(); it != mp.end(); it++) {
		printf("%c %d\n", it->first, it->second);
	}
	printf("The size of the map is: %d ", mp.size());
	
	return 0;
}
