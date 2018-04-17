#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd = 0;
    fd = open("file",O_RDWR);
    printf("%d\n",fd);
    int fd_out = dup(1);
    dup2(fd,1);
    printf("helloworld\n");
    dup2(fd_out,1);
    printf("hello\n");



    return 0;
}