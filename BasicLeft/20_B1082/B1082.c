#include<stdio.h>
#include<math.h>

int main() {
	int number;
	scanf("%d", &number);
	
	double maxRadius = 0, minRadius = 0;
	int maxID, minID;
	int flag = 0;
	for(int i = 0; i < number; i++) {
		double x, y, radius;
		int ID;
		scanf("%d%lf%lf", &ID, &x, &y);
		radius = sqrt(x * x + y * y);
		
		if(flag == 0) {
			minRadius = radius;
			minID = ID;
			flag++;
		}
		if(radius > maxRadius) {
			maxRadius = radius;
			maxID = ID;	
		}  
		if(radius < minRadius) {
			minRadius = radius;	
			minID = ID;
		}   
	}
	printf("%04d %04d", minID, maxID);
	
	return 0;
}
