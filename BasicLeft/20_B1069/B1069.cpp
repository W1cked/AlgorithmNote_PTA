/* Test point4 didn't pass */
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int totalNumber, interval, champion;
	scanf("%d%d%d", &totalNumber, &interval, &champion);
	
	if(champion > totalNumber) {
		printf("Keep going...");
		return 0;
	} 
	
	int counter = 0;
	vector<string> rewardName;
	for(int i = 0; i < totalNumber; i++) {
		string user;
		cin >> user;
		
		if(i + 1 == champion) {
			cout << user << endl;
			rewardName.push_back(user);
			counter++;
			continue;
		}
		if(counter) { 
			if((++counter) % interval == 1) {
				/* Do you have already take the reward? */
				vector<string>::iterator it = find(rewardName.begin(), rewardName.end(), user);
				if(it == rewardName.end()) {	// This guy didn't appear in the list
					rewardName.push_back(user);
					cout << user << endl;
				}
				else
					counter--;
			}
		}	
	}
	
	return 0;
}
