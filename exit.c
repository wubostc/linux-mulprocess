#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>



int fun1()
{
    printf("fun1\n");
    exit(0);
}


int fun2()
{
    printf("fun2\n");
    _exit(0);
}

int main()
{
    pid_t pid;

    if((pid = fork()) == 0)
    {
        fun1();
    }

    sleep(1);

    if((pid = fork()) == 0)
    {
        fun2();
    }

    return 0;
}
