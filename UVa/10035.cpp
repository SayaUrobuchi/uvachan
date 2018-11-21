#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g,h;
    while(scanf("%d %d",&a,&b)==2)
    {
        if(a==0&&b==0)
        {
            break;
        }
        for(c=0,d=0,f=0;c<11;c++)
        {
            e=a%10+b%10+f;
            if(e>9)
            {
                d++;
            }
            a/=10;
            b/=10;
            f=e/10;
        }
        if(d==0)
        {
            printf("No carry operation.\n");
        }
        else if(d==1)
        {
            printf("1 carry operation.\n");
        }
        else
        {
            printf("%d carry operations.\n",d);
        }
    }
    return 0;
}
