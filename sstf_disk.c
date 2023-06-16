#include <stdio.h>
#include <stdlib.h>
int main(){
    int arr[100], i, n, seek = 0, init, count = 0;
    printf("Shreshth Pratap Singh / Sec-M / Roll_no.-51\n\n");
    printf("Enter the number of Request: \n");
    scanf("%d", &n);
    printf("Enter the Request sequence: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter Start head position: \n");
    scanf("%d", &init);
    while (count != n)
    {
        int min = 1000, d, index;
        for (i = 0; i < n; i++)
        {
            d = abs(arr[i] - init);
            if (min > d)
            {
                min = d;
                index = i;
            }
        }
        seek = seek + min;
        init = arr[index];
        arr[index] = 1000;
        count++;
    }
    printf("Total head movement is: %d \n", seek);
    return 0;
}
