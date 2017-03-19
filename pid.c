#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> //pid_t


int main()
{
    printf("ppid:%d\n",getppid());//父进程id
    printf("pgrp:%d\n",getpgrp());//组进程id
    printf("pid:%d\n",getpid());

    while(1);
}


