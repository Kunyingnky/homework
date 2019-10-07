#include "uhead.h"
#include <sys/time.h>
int main(){
    int a[MAXNUM],b[MAXNUM],i;
    struct timeval starttime,endtime;
    arg arg1;
    double timeuse;
    urand(a,MAXNUM);
    //show(a,MAXNUM);
    arg1 = operator(a,MAXNUM);
    //printf("sum = %d, ave = %f\n",arg1.sum,arg1.ave);
    for ( i = 0; i < MAXNUM; i++)
    {
        b[i] = a[i];
    }
    //printf("\n =======\n sum = %d\n",usum(a,MAXNUM));
    gettimeofday(&starttime,0);
    bsort(a,MAXNUM);
    gettimeofday(&endtime,0);
    timeuse = 1000000*(endtime.tv_sec - starttime.tv_sec) + endtime.tv_usec - starttime.tv_usec;
    timeuse /=1000;//除以1000则进行毫秒计时，如果除以1000000则进行秒级别计时，如果除以1则进行微妙级别计时
    printf("bubble sort time use: %lf ms\n",timeuse);
    gettimeofday(&starttime,0);
    syssort(b,MAXNUM);
    gettimeofday(&endtime,0);
    timeuse = 1000000*(endtime.tv_sec - starttime.tv_sec) + endtime.tv_usec - starttime.tv_usec;
    timeuse /=1000;
    printf("sys sort time use: %lf ms\n",timeuse);
    return 0;
}