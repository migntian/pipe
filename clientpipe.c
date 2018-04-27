#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int wfd = open("mypipe",O_WRONLY);
    if(wfd<0)
    {
        perror("open");
    }
    char buf[1024];
    while(1)
    {
        buf[0] = 0;
        printf("请输入信息");
        fflush(stdout);
        ssize_t s = read(0,buf,sizeof(buf)-1);
        if(s > 0)
        {
            buf[s] = 0;
            write(wfd,buf,strlen(buf));
        }
        else
        {
            perror("read");
        }
    }
        close(wfd);
        return 0;
}

