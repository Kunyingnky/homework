#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(){
    int fd;
    if ((fd = creat("file.hole",O_RDWR))<0)
    {
        perror("create error\n");
    }
    if (write(fd,buf1,10) != 10)    
    {
        perror("buf1 write error");
    }
    /*offset now = 10*/
    if (lseek(fd,40,SEEK_SET) == -1)    
    {
        perror("lseek error");
    }
    // offset now is 40
    if (write(fd,buf2,10) != 10)    
    {
        perror("buf2 write error");
    }
    // now is 50
    
    return 0;
}