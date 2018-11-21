#include<stdio.h>
int a,b,c,d[16],f,g,h;
int abc()
{
    int e;
    for(e=0;e<2;e++)
    {
        if(f==b)
        {
            for(h=0;h<b;h++)
            {
                printf("%d",d[h]);
            }
            printf("\n");
            break;
        }
        else
        {
            if(e==1&&g!=0||e==0&&g<b-f)
            {
                d[f]=e;
                f++;
                g-=e;
                abc();
                g+=e;
                f--;
            }
        }
    }
    return 0;
}
int main()
{
    while(scanf("%d",&a)==1)
    {
        for(a;a>0;a--)
        {
            scanf("%d %d",&b,&c);
            f=0;
            g=c;
            abc();
            if(a!=1)
            {
                printf("\n");
            }
        }
    }
    return 0;
}
