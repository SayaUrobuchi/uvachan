#include<stdio.h>
int main()
{
    char x;
    int a,b,c,d,e,f,g,h,i,j,k[100];
    a=0;
    while(scanf("%d%c",&k[a],&x)==2)
    {
        if(x==10)
        {
            f=0;
            for(;;)
            {
                scanf("%d%c",&b,&x);
                for(c=1,d=a,i=0;d>=0;c*=b,d--)
                {
                    i+=c*k[d];
                }
                if(f!=0)
                {
                    printf(" ");
                }
                printf("%d",i);
                f=1;
                if(x==10)
                {
                    a=-1;
                    printf("\n");
                    break;
                }
            }
        }
        a++;
    }
    return 0;
}
