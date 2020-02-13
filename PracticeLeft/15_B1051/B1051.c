#include<stdio.h>
#include<math.h>

int main() {
	
	double R1, R2, P1, P2;
	scanf("%lf%lf%lf%lf", &R1, &P1, &R2, &P2);
	
	double answerA, answerB;
	answerA = R1 * R2 * cos(P1 + P2);
	answerB = R1 * R2 * sin(P1 + P2);
	
	if(answerA < 0 && answerA > -0.005)
		answerA = 0;
	if(answerB < 0 && answerB > -0.005)
		answerB = 0;
	
    printf("%.2f%+.2fi", answerA, answerB);
	
	return 0;
}
