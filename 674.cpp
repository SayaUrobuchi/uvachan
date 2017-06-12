#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g,h,i,j[7490],k[]={5,10,25,50};
    for(a=0;a<7490;a++)
    {
        j[a]=1;
    }
    for(a=0;a<4;a++)
    {
        for(b=0;b<7490-k[a];b++)
        {
            j[b+k[a]]+=j[b];
        }
    }
    while(scanf("%d",&a)==1)
    {
        printf("%d\n",j[a]);
    }
    return 0;
}
