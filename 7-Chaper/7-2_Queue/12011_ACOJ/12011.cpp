#include<iostream>
#include<vector>
using namespace std;

int main() {
	int M, N;
	cin >> M >> N;
	
	vector<int> memory;
	int searchCount = 0;
	while(N--) {
		int temp;
		bool searchFlag = false;
		cin >> temp;
		
		if(memory.size() < M) {	// Memory is not full
			for(vector<int>::iterator it = memory.begin(); it != memory.end(); it++) {	// Search the words in memory
				if(*it == temp) {
					searchFlag = true;
					break;
				}
			}
			if(searchFlag == false) {
				memory.push_back(temp);
				searchCount++;	
			}
		}
		else {	// Memory is full
			for(vector<int>::iterator it = memory.begin(); it != memory.end(); it++) {	// Search the words in memory
				if(temp == *it) {
					searchFlag = true;
					break;
				}
			}
			if(searchFlag == false) {
				memory.erase(memory.begin());
				memory.push_back(temp);
				searchCount++;
			}
		}
	}
	
	cout << searchCount;
	
	return 0;
}
