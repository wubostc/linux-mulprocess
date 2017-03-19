#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    pid_t pid;

    int state;

    if((pid = fork()) == 0)
    {
        sleep(1);
        printf("[%d] child \n",getpid());
    }
    if(pid > 0)
    {
        sleep(2);
        pid = waitpid(-1, &state, WNOHANG);//wnohang=1 非阻塞, 0是阻塞
    }

    //pid = wait(&state);

    //第1字节:state & 0xff 信号值
    //2字节:(state >> 8) & 0xff 退出码
    //3 4字节:保留
    printf("[%d] exit child [%d], SIG:%d, exitcode:%d\n",getpid(),pid,
                state & 0xff, (state >> 8) & 0xff);

    printf("end main...[%d]\n",getpid());

    return 0;
}
