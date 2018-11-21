#include <stdio.h>
unsigned short int n[10055],m[100130050];
int main()
{
    n[0]=1;
    n[1]=2;
    int a,b,c;
    unsigned short int *p;
    for(a=2;a<=10050;a++)
    {
        n[a]=((n[a-1]+n[a-2])<<1)%10007;
    }
    m[0]=1;
    m[1]=4;
    for(p=m+2, c=2;p-m<=100130050;p++, c++)
    {
        if(c == 10006)
        {
			c = 0;
		}
        *p=(((*(p-1)+*(p-2))<<1)+n[c]);
        if(*p >= 10007)
        {
			*p %= 10007;
		}
    }
    while(scanf("%d",&a)==1)
    {
        if(a==-1)
        {
            break;
        }
        a%=100130042;
        printf("%d\n",m[a]);
    }
    return 0;
}
