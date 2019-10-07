#include"uhead.h"
int main(void)
{
	int a[UNUMBER];
	int j;
	struct timeval tvBegin1, tvEnd1,tvBegin2, tvEnd2;
	gettimeofday(&tvBegin1, NULL);
	urand(a,UNUMBER);
	usort(a,UNUMBER);
	gettimeofday(&tvEnd1, NULL);
	//<1>.获得毫秒数:
	double dDuration1 = 1000 * (tvEnd1.tv_sec - tvBegin1.tv_sec) + ((tvEnd1.tv_usec - tvBegin1.tv_usec) / 1000.0);

	gettimeofday(&tvBegin2, NULL);
	urand(a,UNUMBER);
	uqsort(a,UNUMBER);
	gettimeofday(&tvEnd2, NULL);
	//<1>.获得毫秒数:
	double dDuration2 = 1000 * (tvEnd2.tv_sec - tvBegin2.tv_sec) + ((tvEnd2.tv_usec - tvBegin2.tv_usec) / 1000.0);
	printf("time of usort=%f\n",dDuration1);
	printf("time of qsort=%f\n",dDuration2);
	return 0;
}
