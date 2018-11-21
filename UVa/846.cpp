#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c,d,e,f;
    while(scanf("%d",&a)==1)
    {
        for(a;a>0;a--)
        {
            scanf("%d %d",&b,&c);
            c-=b;
            b=(int)(sqrt(c));
            d=b*b+b;
            if(c>d)
            {
                printf("%d\n",b*2+1);
            }
            else if(c==0)
            {
                printf("0\n");
            }
            else if(c==b*b)
            {
                printf("%d\n",b*2-1);
            }
            else
            {
                printf("%d\n",b*2);
            }
        }
    }
    return 0;
}
