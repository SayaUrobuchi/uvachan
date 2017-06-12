#include<stdio.h>
int main()
{
    long long int k[30001];
    int a,b,c,d,e,f,g,h,i,j[4]={5,10,25,50};
    for(a=0;a<30001;a++)
    {
        k[a]=1;
    }
    for(a=0;a<4;a++)
    {
        for(b=0;b<30001-j[a];b++)
        {
            k[b+j[a]]+=k[b];
        }
    }
    while(scanf("%d",&a)==1)
    {
        if(k[a]==1)
        {
            printf("There is only 1 way to produce %d cents change.\n",a);
        }
        else
        {
            printf("There are %lld ways to produce %d cents change.\n",k[a],a);
        }
    }
    return 0;
}
