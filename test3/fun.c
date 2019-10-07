#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int fdsrc,fddes,nbytes;
	int flags=O_CREAT |O_TRUNC | O_WRONLY;
	int z;
	char buf[20],src[20],des[20];
	struct timeval tvBegin1, tvEnd1,tvBegin2, tvEnd2;
	printf("input filename:");
	scanf("%s",des);
	fdsrc=open("/etc/passwd",O_RDONLY);
	if(fdsrc<0)
	{
		exit(1);
	}
	fddes=open(des,flags,0644);
	if(fddes<0)
	{
		exit(1);
	}
	while((nbytes=read(fdsrc,buf,20))>0)
	{
		z=write(fddes,buf,nbytes);
		if(z<0)
		{
			perror("open original file error!\n");
		}
	}
	close(fdsrc);
	close(fddes);
	printf("复制“/ect/passwd”文件为“%s”文件成功!\n",des);
	gettimeofday(&tvEnd1, NULL);
		//<1>.获得毫秒数:
	double dDuration1 = 1000 * (tvEnd1.tv_sec - tvBegin1.tv_sec) + ((tvEnd1.tv_usec - tvBegin1.tv_usec) / 1000.0);

	exit(0);
}
