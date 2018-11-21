#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
int a,b,c[50010],i,j,k,x,y,l,m,n,zz=0;
int z(int o)
{
	if(c[o]==0)
		return o;
	return c[o]=z(c[o]);
}
main()
{
	while(scanf("%d %d",&a,&b)==2)
	{
		if(a==0&&b==0)
			break;
		zz++;
		memset(c, 0, sizeof(c));
		l=a;
		for(int i=0;i<b;i++)
		{
			scanf("%d %d",&m,&n);
			x=z(m);
			y=z(n);
			if(x!=y)
			{
				c[y]=x;
				l-=1;
			}
		}
		printf("Case %d: %d\n",zz,l);
	}
}
