#include<stdio.h>

int main()
{
    int num;
    scanf("%d", &num);
    
    //Scanner
    int arr[100000] = {0};
    for(int i = 0; i < num; i++) {
        int schInfo, score;
        scanf("%d%d", &schInfo, &score);
        arr[schInfo] += score;
    }

    //Find the max one
    int sum = arr[0];
    int flag = 1;
    for(int i = 1; i <= num; i++) {
        if(sum < arr[i]) {
            sum = arr[i];
            flag = i;
        }
    }

    printf("%d %d", flag, sum);
    
    return 0;
}
