#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main() {
	
	int totalNumber, interval, champion;
	scanf("%d%d%d", &totalNumber, &interval, &champion);
	
	if(champion > totalNumber) {
		printf("Keep going...");
		return 0;
	} 
	
	/** Read the data */
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
			counter++; 
			if(counter % interval == 1) {
				/* Do you have already take the reward? */
				bool sameFlag = false;
				for(vector<string>::iterator it = rewardName.begin(); it != rewardName.end(); it++) {
					if(*it == user) {
						counter--;
						sameFlag = true;
						break;
					}
				}
				if(sameFlag == false) {
					cout << user << endl;
					rewardName.push_back(user);
				}
			}
		}	
	}
	
	return 0;
}
