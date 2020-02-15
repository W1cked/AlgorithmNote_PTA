#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

struct Student {
	bool searchFlag;
	string award;
	int ID;
	int rank;
	Student() {
		searchFlag = false;
		rank = 0;
	}
};

bool isPrime(int n) {
	if(n <= 1) return false;
	for(long long int i = 2; i * i <= n; i++) {
		if(n % i == 0) return false;
	}
	return true;
}

int main() {
	int number;
	scanf("%d", &number);
	
	Student* stu = new Student[number];
	for(int i = 0; i < number; i++) {
		scanf("%d", &stu[i].ID);
		stu[i].rank = i + 1;
		
		if(stu[i].rank == 1) 
			stu[i].award = "Mystery Award";
		else if(isPrime(stu[i].rank))
			stu[i].award = "Minion";
		else 
			stu[i].award = "Chocolate";
	}
	
	int searchNumber;
	scanf("%d", &searchNumber);
	for(int i = 0; i < searchNumber; i++) {
		int tempID;
		scanf("%d", &tempID);
		
		bool findFlag = false;
		for(int i = 0; i < number; i++) {
			if(stu[i].ID == tempID) {
				findFlag = true;
				
				if(stu[i].searchFlag) {
					printf("%04d: Checked\n", tempID);	/* Be careful if someone's ID is 0001*/
				}
				else {
					printf("%04d: ", tempID);
					cout << stu[i].award << endl;
					stu[i].searchFlag = true;
				}
				break;
			}
		}
		if(findFlag == false)
			printf("%04d: Are you kidding?\n", tempID);
	}
	delete[] stu;
	
	return 0;
}
