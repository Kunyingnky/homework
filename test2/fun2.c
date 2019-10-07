#include "uhead.h"

arg operator(int *a,int n){
    arg arg1;
    int sum = 0;
    float ave = 0.0;
    sum = usum(a,n);
    ave = (sum+0.0) / n;
    arg1.sum = sum;
    arg1.ave = ave;
    return arg1;
}