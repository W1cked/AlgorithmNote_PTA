#include<cstdio>
#include<set>
using namespace std;

int main() {
	
	set<int> st;
	
	/** Delete a singal element 
	st.insert(100);
	st.insert(200);
	st.insert(100);
	st.insert(300);
	st.erase(st.find(100)); 
	st.erase(st.find(200));
	*/
	
	/** Delete elements with an interval */
	st.insert(20);
	st.insert(10);
	st.insert(40);
	st.insert(30);
	
	set<int>::iterator it = st.find(30);
	st.erase(it, st.end());
	
	for(it = st.begin(); it != st.end(); it++) {
		printf("%d\n", *it);
	}
	printf("size of this set is: %d ", st.size());
	
	return 0;
}
