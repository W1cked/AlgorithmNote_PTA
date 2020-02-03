#include<cstdio>
#include<queue>
using namespace std;

int main() {
	
	queue<int> q;
	for(int i = 1; i <= 5; i++) {
		q.push(i);
	}
	
	//printf("%d %d\n", q.front(), q.back());
	
	for(int i = 1; i <=3; i++) {
		q.pop();
	}
	printf("%d\n", q.front());
	
	return 0;
}
