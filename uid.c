#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    printf("uid:%u\n",getuid());
    printf("euid:%u\n",geteuid());
}
