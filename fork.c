// fork复制一份父进程的数据

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    printf("Start min pid[%d]...\n",getpid());

    if((pid = fork()) < 0)
    {
        perror("Fail to create child process");
        return -1;
    }
    else if(pid == 0)
    {
        printf("this is child process. pid[%d]\n",getpid());
    }
    else
    {
        printf("this is parent process. pid[%d] and child is %d\n", \
            getpid(),pid);
    }

    return 0;

}
