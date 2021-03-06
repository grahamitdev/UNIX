#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int val;
    if (argc != 2)
    {
        printf("usage : a.out <descriptor#>\n");
        exit(1);
    }
    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
    {
        printf("fcntl error for fd %d\n", atoi(argv[1]));
        return 0;
    }
    switch (val & O_ACCMODE)
    {
    case O_RDONLY:
        printf("read only\n");
        break;
    case O_WRONLY:
        printf("write only\n");
        break;
    case O_RDWR:
        printf("read & write\n");
        break;
    default:
        printf("unknown access mode\n");
        break;
    }
    if (val & O_APPEND)
    {
        printf(",append\n");
    }
    if (val & O_NONBLOCK)
    {
        printf(",nonblocking\n");
    }
    if (val & O_SYNC)
    {
        printf(",synchronous write\n");
    }

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
    if (val & O_FSYNC)
    {
        printf(",synchronous writes\n");
    }
#endif
    //putchar('\n');

    return 0;
}