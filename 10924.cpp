#include<stdio.h>
int main()
{
    char x;
    int a,b,c,d,e,f,g,h,i,j,k[93];
    k[0]=1;
    k[1]=2;
    c=2;
    for(a=3;a<485;a+=2)
    {
        for(b=1,d=0;b<c;b++)
        {
            if(a%k[b]==0)
            {
                d=1;
            }
        }
        if(d!=1)
        {
            k[c]=a;
            c++;
        }
    }
    a=0;
    while(scanf("%c",&x)==1)
    {
        if(x==10)
        {
            for(b=0,c=0;b<93;b++)
            {
                if(a==k[b])
                {
                    printf("It is a prime word.\n");
                    c++;
                    break;
                }
                else if(k[b]>a)
                {
                    break;
                }
            }
            if(c==0)
            {
                printf("It is not a prime word.\n");
            }
            a=0;
        }
        else
        {
            if(x<97)
            {
                a+=x-38;
            }
            else
            {
                a+=x-96;
            }
        }
    }
    return 0;
}
