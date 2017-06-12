#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g,h,i,j[100000],k[100000];
    for(a=0;a<10000;a++)
    {
        j[a]=0;
        k[a]=0;
    }
    b=0;
    while(scanf("%d",&a)==1)
    {
        if(j[a]==0)
        {
            k[b]=a;
            b++;
        }
        j[a]++;
    }
    for(c=0;c<b;c++)
            {
                printf("%d %d\n",k[c],j[k[c]]);
            }
    //while(1);
    return 0;
}
