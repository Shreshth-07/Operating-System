#include<stdio.h>
#include<unistd.h>

int main()
{
    fork();
    printf("Id of this program is : %d\n",getpid());

    return 0;
}
