#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c,d,e,f,g;
    while(scanf("%d",&a)==1)
    {
        if(a==0)
        {
            break;
        }
        if(a==1)
        {
            printf("1 1\n");
        }
        else
        {
            b=sqrt(a-1);
            b+=b%2;
            b--;
            c=b+1;
            b*=b;
            b=a-b;
            if(b<=c)
            {
                printf("%d ",b);
            }
            else
            {
                b-=c;
                b++;
                if(b<=c)
                {
                    printf("%d ",c);
                }
                else
                {
                    b-=c;
                    if(b<=c+1)
                    {
                        printf("%d ",c+1);
                    }
                    else
                    {
                        b-=c+1;
                        printf("%d ",c+1-b);
                    }
                }
            }
            b=sqrt(a-1);
            b-=b%2;
            c=b+1;
            b*=b;
            b=a-b;
            if(b<=c)
            {
                printf("%d\n",b);
            }
            else
            {
                b-=c;
                b++;
                if(b<=c)
                {
                    printf("%d\n",c);
                }
                else
                {
                    b-=c;
                    if(b<=c+1)
                    {
                        printf("%d\n",c+1);
                    }
                    else
                    {
                        b-=c+1;
                        printf("%d\n",c+1-b);
                    }
                }
            }
        }
    }
    return 0;
}
