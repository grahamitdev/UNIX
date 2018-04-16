#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#include <sys/stat.h>
#include <fcntl.h>
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFJHIJ";
int main(void)
{
    int fd;
    if ((fd = creat("file.hole", FILE_MODE)) < 0)
    {
        perror("creat error");
    }
    if (write(fd, buf1, 10) != 10)
    {
        perror("buf1 write error");
    }
    if (lseek(fd, 100, SEEK_SET) == -1)
    {
        perror("lseek error");
    }
    if (write(fd, buf2, 10) != 10)
    {
        perror("buf2 write error");
    }
    return 0;
}