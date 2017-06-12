#include<stdio.h>
#include<string.h>
int main()
{
    char k[10],x;
    int a,b=1,c=10;
    while(scanf("%d%c",&a,&x)==2)
    {
        if(a==0)
        {
            break;
        }
        gets(k);
        if(strcmp(k,"too high")==0)
        {
            if(c>a-1)
            {
                c=a-1;
            }
        }
        else if(strcmp(k,"too low")==0)
        {
            if(b<a+1)
            {
                b=a+1;
            }
        }
        else
        {
            if(b>c)
            {
                printf("Stan is dishonest\n");
            }
            else
            {
                if(a<=c&&a>=b)
                {
                    printf("Stan may be honest\n");
                }
                else
                {
                    printf("Stan is dishonest\n");
                }
            }
            b=1;
            c=10;
        }
    }
    return 0;
}
