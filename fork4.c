#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    int *y = (int *)malloc(sizeof(int));
    *y = 1;
    if((pid = fork()) == 0)
    {
        printf("child pid:%d\n",getpid());
        printf("child addr:%p\tval:%d\n",y,*y);
        sleep(2);
        *y = 3;
        printf("[2] child addr:%p\tval:%d\n",y,*y);//地址不变，值变了
    }
    else
    {
        printf("parent pid:%d\n",getpid());
        printf("parent addr:%p\tval:%d\n",y,*y);
        sleep(4);
        printf("[2] parent addr:%p\tval:%d\n",y,*y);//值没变

    }
    
    return 0;
}
