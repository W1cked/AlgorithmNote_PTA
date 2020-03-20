#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main() {
	int number;
	cin >> number;
	
	double MAX = 0;
	for(int i = 0; i < number; i++) {
		double realValue, virtualValue;
		cin >> realValue >> virtualValue;
		
		double radius = sqrt(realValue * realValue + virtualValue * virtualValue);
		if(radius > MAX)
			MAX = radius;
	}
	
	cout << fixed << setprecision(2) << MAX << endl;
	
	return 0;
}
