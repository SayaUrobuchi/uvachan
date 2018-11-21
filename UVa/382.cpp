#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g,h,i,j,k;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&a)==1)
    {
        if(a==0)
        {
            printf("END OF OUTPUT\n");
            break;
        }
        for(b=1,c=0;b<a;b++)
        {
            if(a%b==0)
            {
                c+=b;
            }
        }
        if(a==c)
        {
            printf("%5d  PERFECT\n",a);
        }
        else if(a>c)
        {
            printf("%5d  DEFICIENT\n",a);
        }
        else
        {
            printf("%5d  ABUNDANT\n",a);
        }
    }
    return 0;
}
