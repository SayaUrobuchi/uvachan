#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c,d,e,f,g,h,i,j,k[100];
    for(a=3,b=0;b<70;a+=2)
    {
        for(c=0,d=0;c<b;c++)
        {
            if(a%k[c]==0)
            {
                d=1;
                break;
            }
        }
        if(d==0)
        {
            k[b]=a;
            b++;
        }
    }
    while(scanf("%d",&a)==1)
    {
        if(a==0)
        {
            break;
        }
        for(b=0,f=0;b<100;b++)
        {
            c=a-k[b];
            g=(int)(sqrt(c));
            for(d=3,e=0;d<=g;d+=2)
            {
                if(c%d==0)
                {
                    e=1;
                }
            }
            if(e==0)
            {
                printf("%d = %d + %d\n",a,k[b],c);
                f++;
                break;
            }
        }
        if(f==0)
        {
            printf("Goldbach's conjecture is wrong.\n");
        }
    }
    return 0;
}
