#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    umask(0);
    if(mkfifo("mypipe",0644)<0);
        perror("mkfifo");
    int rfd = open("mypipe",O_RDONLY);
    if(rfd<0)
    {
        perror("open");
    }
    char buf[1024];
    while(1)
    {
        buf[0] = 0;
        printf("等待收信息...\n");
        ssize_t s = read(rfd,buf,sizeof(buf)-1);
        if(s > 0)
        {
            buf[s-1];
            printf("client 说：%s\n",buf);
        }
        else if(s == 0)
        {
            printf("clent退出了，我现在退出\n");
        }
        else
        {
            perror("read");
        }
    }
        close(rfd);
        return 0;
}

