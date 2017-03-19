#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>

int daemon1(char *pFile,int uMask)
{
    pid_t pid;
    pid = fork();

    if(pid > 0)
    {
        //exit parent process
        exit(0);
    }
    

    printf("gpid:%d",getpgrp());
    //child process: ppid -> init
    pid = setsid(); // tty = ?

    printf("gpid:%d",getpgrp());

    if(pid < 0)
    {
        perror("setsid failed.");
        return -1;
    }

    chdir("/");

    if(pFile)
    {
        int fd = open(pFile,O_RDWR,0);
        if(fd < 0)
        {
            perror("open failed.");
            return -1;
        }
        dup2(fd,STDIN_FILENO);
        dup2(fd,STDOUT_FILENO);
        dup2(fd,STDERR_FILENO);
        close(fd);
    }

    umask(uMask);

    return 0;

}

int main()
{
    daemon1(NULL,002);

    sleep(100);

    return 0;
}
