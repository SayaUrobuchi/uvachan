#include<stdio.h>
int main()
{
    int a[20][2],b,c,d,e,f,g,h,i=0,j,k,l;
    while(scanf("%d %d %d",&b,&c,&d)==3)
    {
        if(b==0&&c==0&&d==0)
        {
            break;
        }
        i++;
        for(e=0;e<b;e++)
        {
            scanf("%d",&a[e][0]);
            a[e][1]=1;
        }
        for(e=0,g=0,h=0;e<c;e++)
        {
            scanf("%d",&f);
            if(g<=d)
            {
                g+=a[f-1][0]*a[f-1][1];
                a[f-1][1]*=-1;
                if(g>h)
                {
                    h=g;
                }
            }
        }
        if(g>d)
        {
            printf("Sequence %d\nFuse was blown.\n\n",i);
        }
        else
        {
            printf("Sequence %d\nFuse was not blown.\n",i);
            printf("Maximal power consumption was %d amperes.\n\n",h);
        }
    }
    return 0;
}
