#include<cstdio>
#include<set>
using namespace std;

int main() {
	set<int> st;
	for(int i = 1; i <= 3; i++) {
		st.insert(i);
	}
	
	set<int>::iterator it = st.find(2);
	printf("%d ", *it);
	printf("%d ", *(st.find(2)));
	
	return 0;
}
