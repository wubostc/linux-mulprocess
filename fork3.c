#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    int x = 2;
    int *y = (int *)malloc(sizeof(int));
    if((pid = fork()) == 0)
    {
        printf("child pid:%d\n",getpid());
        printf("child addr:%p\tval:%d\n",&x,x);
        sleep(2);
        x = 3;
        printf("[2] child addr:%p\tval:%d\n",&x,x);//地址不变，值变了
    }
    else
    {
        printf("parent pid:%d\n",getpid());
        printf("parent addr:%p\tval:%d\n",&x,x);
        sleep(4);
        printf("[2] parent addr:%p\tval:%d\n",&x,x);//值没变

    }
    
    return 0;
}
