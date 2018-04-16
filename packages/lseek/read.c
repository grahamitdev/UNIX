#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd = 0;
    char buf[1024] = {0};
    fd = open("main.c", O_RDWR);
    int ret = 0;
    
    lseek(fd,10,SEEK_SET);
    while((ret = read(fd,buf,10)))
    {
        printf("ret = %d\n",ret);
    }

 
    return 0;
}