#include<stdio.h>
int main()
{
    char a[1000],b;
    int c,d;
    c=0;
    d=0;
    while(scanf("%c",&a[c])==1)
    {
        if(a[c]==32)
        {
            a[c]=0;
            while(scanf("%c",&b)==1)
            {
                if(b==10)
                {
                    break;
                }
                if(b==a[d]&&d<c)
                {
                    d++;
                }
            }
            if(d==c)
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
            c=-1;
            d=0;
        }
        c++;
    }
    return 0;
}
