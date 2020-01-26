#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student {
	int ID;
	int DeScore;
	int CaiScore;
	int sum;
	int tier;
}stu[100001];

bool cmp(Student a, Student b) {
	if(a.tier != b.tier) {
		return a.tier < b.tier;
	}
	else if(a.sum != b.sum) {
		return a.sum > b.sum;
	}
	else if(a.DeScore != b.DeScore) {
		return a.DeScore > b.DeScore;
	}
	else {
		return a.ID < b.ID;
	}
}

int main() {
	int number, L, H;
	
	// Input the data
	scanf("%d%d%d", &number, &L, &H);
	int counter = number;
	for(int i = 0; i < number; i++) {
		scanf("%d %d %d", &stu[i].ID, &stu[i].DeScore, &stu[i].CaiScore);
		stu[i].sum = stu[i].CaiScore + stu[i].DeScore;
		
		if(stu[i].CaiScore < L || stu[i].DeScore < L) {
			stu[i].tier = 5;
			counter--;
		}
		else if(stu[i].CaiScore >= H && stu[i].DeScore >= H){
			stu[i].tier = 1;
		}
		else if(stu[i].DeScore >= H && stu[i].CaiScore < H) {
			stu[i].tier = 2;
		}
		else if(stu[i].DeScore < H && stu[i].CaiScore < H && stu[i].DeScore >= stu[i].CaiScore) {
			stu[i].tier = 3;
		}
		else {
			stu[i].tier = 4;
		}
			
	}
	printf("%d\n", counter);
	
	sort(stu, stu + number, cmp);
	for(int i = 0; i < counter; i++) {
		printf("%d %d %d\n", stu[i].ID, stu[i].DeScore, stu[i].CaiScore);
	}
	
	return 0;
}
