#include <stdio.h>
#include <stdlib.h>
int main(){
    int arr[100], i, n, seek = 0, init;
    printf("Enter the number of Request: ");
    scanf("%d", &n);
    printf("Enter the sequence: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter Start head position: \n");
    scanf("%d", &init);
    for (i = 0; i < n; i++)
    {
        seek = seek + abs(arr[i] - init);
        init = arr[i];
    }
    printf("Total head move :%d \n", seek);
    return 0;
}
