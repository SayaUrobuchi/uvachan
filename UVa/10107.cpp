#include<stdio.h>
#include<stdlib.h>
int a=1,b,c,d,e,f,g,h,i,j,k[10001];
int abcc(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    while(scanf("%d",&k[a])==1)
    {
        qsort(k,a+1,sizeof(int),abcc);
        if(a%2==1)
        {
            b=a+1;
            b/=2;
            printf("%d\n",k[b]);
        }
        else
        {
            b=a/2;
            printf("%d\n",(k[b]+k[b+1])/2);
        }
        a++;
    }
    return 0;
}
