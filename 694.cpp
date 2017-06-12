#include<stdio.h>
int main()
{
    int a,b,c,d=0,e,f,g,h,i,j,k;
    while(scanf("%d %d",&a,&b)==2)
    {
        if(a<0&&b<0)
        {
            break;
        }
        d++;
        printf("Case %d: ",d);
        e=a;
        for(c=0;a<=b;c++)
        {
            if(a==1)
            {
                printf("A = %d, limit = %d, number of terms = %d\n",e,b,c+1);
                break;
            }
            else if(a%2==0)
            {
                a/=2;
            }
            else
            {
                if(a>715827882)
                {
                    printf("A = %d, limit = %d, number of terms = %d\n",e,b,c+1);
                    break;
                }
                a*=3;
                a++;
                if(a>b)
                {
                    printf("A = %d, limit = %d, number of terms = %d\n",e,b,c+1);
                    break;
                }
            }
        }
    }
    return 0;
}
