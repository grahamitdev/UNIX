#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd = 0;
    char buf[1024] = {0};
    fd = open("file", O_RDONLY);
    int ret = 0;
    if ((ret = lseek(fd, 0, SEEK_END)) == -1)
    {
        printf("cannot seek\n");
    }
    else
    {
        printf("seek OK\n");
    }

    read(fd, buf, 1024);
    printf("return = %d\n", ret);
    printf("%s\n", buf);
    return 0;
}
