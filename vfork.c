// vfork 数据与父进程共享

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    printf("Start min pid[%d]...\n",getpid());

    if((pid = vfork()) == 0) // 阻塞父进程
    {
        sleep(2);
        printf("this is child process. pid[%d]\n",getpid());
    }
    else // 被延迟了2s
    {
        printf("this is parent process. pid[%d] and child is %d\n", \
            getpid(),pid);
    }

    _exit(0);
}
