#include <stdio.h>
#include <unistd.h>

int main()
{
    int i;
    for (i = 0; i < 2; ++i)
    {
        fork();
        printf("3\n"); //打印了8次，fork会把缓冲也复制一份
    }
    return 0;
}
