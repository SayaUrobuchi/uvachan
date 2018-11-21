#include<stdio.h>
int a[9],b[3],d,e[3],f[3],g[3],h,i;
int abc()
{
    int c;
    for(c=0;c<3;c++)
    {
        d+=c;
        if(e[d%3]==0)
        {
            i+=b[d%3]-a[d];
            f[d/3]=d%3;
            if(d-c!=6)
            {
                e[d%3]=1;
                d+=3;
                d-=c;
                abc();
                d-=3;
                d+=c;
                e[d%3]=0;
            }
            else
            {
                if(i<h)
                {
                    h=i;
                    g[0]=f[0];
                    g[1]=f[1];
                    g[2]=f[2];
                }
            }
            i-=b[d%3]-a[d];
        }
        d-=c;
    }
    return 0;
}
int main()
{
    while(scanf("%d",&a[0])==1)
    {
        scanf("%d %d %d %d %d %d %d %d",&a[2],&a[1],&a[3],&a[5],&a[4],&a[6],&a[8],&a[7]);
        d=0;
        b[0]=a[0]+a[3]+a[6];
        b[1]=a[1]+a[4]+a[7];
        b[2]=a[2]+a[5]+a[8];
        e[0]=0;
        e[1]=0;
        e[2]=0;
        i=0;
        h=b[0]+b[1]+b[2];
        abc();
        for(d=0;d<3;d++)
        {
            if(g[d]==0)
            {
                printf("B");
            }
            else if(g[d]==1)
            {
                printf("C");
            }
            else
            {
                printf("G");
            }
        }
        printf(" %d\n",h);
    }
    return 0;
}
