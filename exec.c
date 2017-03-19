/*exec 函数族。执行另一个程序作为原进程的子进程*/
/*int execl(const char* path, const char *arg, ...)*/
/*int execlp(const char* file, const char *arg, ...)*/
/*int execle(const char* path, const char *arg, ..., char *const envp[]);*/

/*int execv(const char* path, const char **argv)*/
/*int execvp(const char* file, const char **argv)*/
/*int execve(const char* path, const char **argv, char *const envp[])*/

/*exec 函数族*/
/*execl：入参是可变参数列表(一级指针), 以 NULL 结束*/

/*execv:  入参是参数数组(二级指针)*/

/*p 后缀：搜索系统 PATH，寻找可执行文件*/

/*e 后缀：显式传递环境变量*/


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{
    pid_t pid;

    pid = fork();
    if(pid == 0)
    {
        /*execl("/bin/ls", "-l", "..", NULL);//exec 了进程里会把下面的代码都替换掉*/
        execlp("ls", "-l", "..", NULL);//exec 了进程里会把下面的代码都替换掉
        printf("child...\n");//不会输出,子进程结束
    }
    else
    {
        printf("parent...\n");
        sleep(1);
    }
    

    pid = vfork();
    if(pid != 0)
    {

        char *argv[]={"/bin/ls","..",NULL};
        execv("/bin/ls",argv);//父进程结束
    }

    printf("end main...\n");//vfork 子进程输出
    return 0;
}

