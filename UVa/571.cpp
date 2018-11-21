#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g;
    while(scanf("%d %d %d",&a,&b,&c)==3)
    {
        if(b<a)
        {
            g=b;
            b=a;
            a=g;
            g=-1;
        }
        else
        {
            g=1;
        }
        if(c==b)
        {
            if(g==-1)
            {
                printf("fill A\nsuccess\n");
            }
            else
            {
                printf("fill B\nsuccess\n");
            }
        }
        else
        {
            for(d=0,f=0;d<10000;d++)
            {
                e=a;
                if(g==-1)
                {
                    printf("fill B\n");
                }
                else
                {
                    printf("fill A\n");
                }
                if(e==c)
                {
                    printf("success\n");
                    break;
                }
                if(b-f>e)
                {
                    f+=e;
                    if(g==-1)
                    {
                        printf("pour B A\n");
                    }
                    else
                    {
                        printf("pour A B\n");
                    }
                    if(f==c)
                    {
                        printf("success\n");
                        break;
                    }
                    e=0;
                }
                else
                {
                    e-=b-f;
                    if(g==-1)
                    {
                        printf("pour B A\n");
                    }
                    else
                    {
                        printf("pour A B\n");
                    }
                    if(e==c)
                    {
                        printf("success\n");
                        break;
                    }
                    if(g==-1)
                    {
                        printf("empty A\n");
                    }
                    else
                    {
                        printf("empty B\n");
                    }
                    f=e;
                    if(g==-1)
                    {
                        printf("pour B A\n");
                    }
                    else
                    {
                        printf("pour A B\n");
                    }
                    e=0;
                }
            }
        }
    }
    return 0;
}
