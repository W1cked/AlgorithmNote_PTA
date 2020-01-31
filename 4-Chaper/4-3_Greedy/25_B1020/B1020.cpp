#include<cstdio>
#include<algorithm>
using namespace std;

struct mooncake {
	double store;
	double price;
	double totalSell;
}cake[1001];

bool cmp(mooncake a, mooncake b) {
	return a.price > b.price;
}

int main() {
	int number;
	double needNumber;
	scanf("%d %lf", &number, &needNumber);
	
	// Input the data
	for(int i = 0; i < number; i++) {
		scanf("%lf", &cake[i].store);
	}
	for(int i = 0; i < number; i++) {
		scanf("%lf", &cake[i].totalSell);
		cake[i].price = cake[i].totalSell / cake[i].store;
	}
	
	// Sort the price, high to low
	sort(cake, cake + number, cmp);
	
	// Compute the earnings
	double earnings = 0;
	for(int i = 0; i < number; i++) {
		if(cake[i].store <= needNumber) {
			needNumber = needNumber - cake[i].store;
			earnings += cake[i].totalSell;
		}
		else {
			earnings = earnings + (cake[i].price * needNumber);
			break;
		}
	}
	
	// Display the result
	printf("%.2f\n", earnings);
	
	return 0;
}
