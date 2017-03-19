#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    pid_t pid;
    pid = fork();
    if(pid == 0)
    {
        printf("[%d] child.\n", getpid());
        exit(0);
    }
    if(pid > 0)
    {
        printf("[%d] parent.\n", getpid());
        sleep(60);
    }

    printf("[%d] end main.\n", getpid());
    return 0;
}
