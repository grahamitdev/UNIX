#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

void *dup_thread(void *p)
{
    while(1)
    {
        printf("helloworld\n");
    }
}

int main(void)
{
    int fd = 0;
    int fd_out = 0;
    fd = open("file", O_RDWR);
    fd_out = dup(1);
    dup2(fd, 1);
    

    pthread_t pid;
    pthread_create(&pid, NULL, dup_thread, NULL);
    usleep(5);
    dup2(fd_out, 1);
    printf("hello\n");
    

    return 0;
}