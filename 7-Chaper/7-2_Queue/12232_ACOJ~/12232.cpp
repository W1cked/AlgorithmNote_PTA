#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main() {
	
	int number;
	scanf("%d", &number);
	
	vector<int> Dust;
	int timeMore = 0;
	int count = number;
	while(count--) {
		int temp;
		bool findFlag = false;
		scanf("%d", &temp);
		
		for(int i = 0; i < Dust.size(); i++) {
			if(temp == Dust[i]) {
				timeMore += Dust.size() - i - 1;
				findFlag = true;
				Dust.clear();
				break;
			}
		}
		if(findFlag == false) {
			Dust.push_back(temp);
		}
		
	}
	
	cout << timeMore + number << endl;
	
	return 0;
}
