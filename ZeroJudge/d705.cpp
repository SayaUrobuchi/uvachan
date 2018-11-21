#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
int a[46400],c,i,j,k,l,m;//,tbl[10000001],used[10000001];
unsigned int b[20000];
char str[1100000], buf[210000];
main()
{
    unsigned int *p, q, x, y, z;
    char *pp, *ppp;
    a[1]=1;
    b[0]=2;
    for(i=4; i<46400; i+=2)
    {
		a[i] = 1;
	}
    for(i=3,k=1;i<218;i+=2)
    {
        if(a[i]==0)
        {
            for(j=i*i,l=i+i;j<46400;j+=l)
                a[j]=1;
            b[k]=i;
            k++;
        }
    }
    for(; i<46400; i+=2)
    {
        if(a[i]==0)
        {
            b[k]=i;
            k++;
        }
    }
    fread(str, 1, 1100000, stdin);
    pp = buf;
    l = 0;
    for(ppp=str, c=0; ; ppp++)
    {
        if(*ppp <= '9' && *ppp >= '0')
        {
            c = c*10-48+*ppp;
        }
        else if(*(ppp-1) >= '0' && *(ppp-1) <= '9')
        {
            if(!c)
            {
                break;
            }
            l=0;
            if(c<46400)
            {
				*pp++ = 48+a[c];
				*pp++ = 10;
				c = 0;
				continue;
			}
            if(c==1)
            {
                *pp++ = 49;
                *pp++ = 10;
                c = 0;
                if(*ppp == 0)
                {
                    break;
                }
                continue;
            }
            for(p=b,m=sqrt(c)+1;;p++)
            {
				if(*p>=m)
				{
					break;
				}
                /*if(*p* *p>c)
                {
                    break;
                }*/
                if(!(c%*p))
                {
                    l=1;
                    break;
                }
            }
            *pp++ = l+'0';
            *pp++ = 10;
            c = 0;
            if(*ppp == 0)
            {
                break;
            }
        }
    }
    fwrite(buf, 1, pp-buf, stdout);
    return 0;
}
