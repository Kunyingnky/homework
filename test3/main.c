#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<time.h>
#include<sys/time.h>
int main(){
	FILE *fp= NULL;
	FILE *fd= NULL;
	char tmp[100],des[20],src[20],buf[20];
	int fdsrc,fddes,nbytes;
	int flags=O_CREAT |O_TRUNC | O_WRONLY;
	int z;
	struct timeval tvBegin1, tvEnd1,tvBegin2, tvEnd2;
	printf("input filename:");
	scanf("%s",des);
	gettimeofday(&tvBegin1, NULL);
	
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
	gettimeofday(&tvBegin2, NULL);
	
	fp=fopen ("/etc/passwd","rb");
	if(fp==NULL){
		printf("open original file error!\n");
		exit(1);
	}
	fd=fopen (des,"wb+");
	if(fd==NULL){
		printf("open target file error!\n");
		exit(1);
	}
	while(fread(tmp,32,1,fp)>0){
		if(fwrite(tmp,32,1,fd)<0){
			perror("write file error\n");
		}
	}
	fclose(fp);
	fclose(fd);
	printf("Copy Right!\n");
	gettimeofday(&tvEnd2, NULL);
	double dDuration2 = 1000 * (tvEnd2.tv_sec - tvBegin2.tv_sec) + ((tvEnd2.tv_usec - tvBegin2.tv_usec) / 1000.0);
	printf("time of usort=%f\n",dDuration1);
	printf("time of qsort=%f\n",dDuration2);
	return 0;
}

