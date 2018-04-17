#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd = 0;
    char buf[1024] = {0};

    fd = open("num", O_RDWR);
    int ret = 0;

    lseek(fd, 3, SEEK_SET);
    ret = pread(fd,buf,20,0);
    printf("%d\n",ret);
    printf("%s\n",buf);
    
    int cur = lseek(fd,0,SEEK_CUR);
    printf("%d\n", cur);

   return 0;
}