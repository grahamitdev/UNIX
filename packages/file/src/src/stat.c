#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
    int i = 0;
    struct stat buf = {0};
    char *ptr = NULL;

    for (i = 1; i < argc; ++i)
    {
        printf("%s: \n", argv[i]);
        if (lstat(argv[i], &buf) < 0)
        {
            printf("lstat error\n");
            continue;
        }
        if (S_ISREG(buf.st_mode))
        {
            ptr = "regular";
            printf("%07o\n", buf.st_mode);
        }
        else if (S_ISDIR(buf.st_mode))
        {
            ptr = "directory";
            printf("%07o\n", buf.st_mode);
        }
        else if (S_ISCHR(buf.st_mode))
        {
            ptr = "character special";
            printf("%07o\n", buf.st_mode);
        }
        else if (S_ISBLK(buf.st_mode))
        {
            ptr = "block special";
            printf("%07o\n", buf.st_mode);
        }
        else if (S_ISFIFO(buf.st_mode))
        {
            ptr = "fifo";
            printf("%07o\n", buf.st_mode);
        }
        else if (S_ISLNK(buf.st_mode))
        {
            ptr = "symbolic link";
            printf("%07o\n", buf.st_mode);
        }
        else if (S_ISSOCK(buf.st_mode))
        {
            ptr = "socket";
            printf("%07o\n", buf.st_mode);
        }
        else
        {
            ptr = "unknown mode";
            printf("%07o\n", buf.st_mode);
        }
        printf("%s\n", ptr);
    }
    ptr = NULL;

    return 0;
}
