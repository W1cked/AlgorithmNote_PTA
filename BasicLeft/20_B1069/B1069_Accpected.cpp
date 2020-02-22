#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int totalNumber, interval, firstOne;
	scanf("%d%d%d", &totalNumber, &interval, &firstOne);

	if (firstOne > totalNumber) {
		cout << "Keep going..." << endl;
		return 0;
	}
	else {
		int i = 0;
		while ((++i) < firstOne) {	// Ignore them before he get the prize
			string temp;
			cin >> temp;
		}
		vector<string> rewardList;
		while ((i++) <= totalNumber) {
			string name;
			cin >> name;

			vector<string>::iterator it = find(rewardList.begin(), rewardList.end(), name);
			if (it == rewardList.end()) {	// This guy don't take the prize yet
				rewardList.push_back(name);
				cout << name << endl;
				for (int j = 1; i <= totalNumber && j < interval; i++, j++) { // Ignore (interval - 1) times
					string temp;
					cin >> temp;
				}
			}
		}
	}

	return 0;
}
