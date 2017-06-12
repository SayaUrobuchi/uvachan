#include<stdio.h>
#include<string.h>
int main()
{
	bool j[100][100];
	int a,b,c,d,e,f,g,h,i;
	char k[200];
	j['A']['A']=1;
	j['3']['E']=1;
	j['E']['3']=1;
	j['H']['H']=1;
	j['I']['I']=1;
	j['J']['L']=1;
	j['L']['J']=1;
	j['M']['M']=1;
	j['O']['O']=1;
	j['0']['0']=1;
	j['O']['0']=1;
	j['0']['O']=1;
	j['S']['2']=1;
	j['2']['S']=1;
	j['T']['T']=1;
	j['U']['U']=1;
	j['V']['V']=1;
	j['W']['W']=1;
	j['X']['X']=1;
	j['Y']['Y']=1;
	j['Z']['5']=1;
	j['5']['Z']=1;
	j['1']['1']=1;
	j['8']['8']=1;
	while(scanf("%s",&k)==1)
	{
		a=strlen(k);
		for(b=0,c=a-1,d=0,i=0;b<=c;b++,c--)
		{
			if(k[b]!=k[c])
			{
				d=1;
				if(i==1)
				{
					break;
				}
			}
			if(j[k[b]][k[c]]!=1)
			{
				i=1;
				if(d==1)
				{
					break;
				}
			}
		}
		if(i==1)
		{
			if(d==1)
			{
				printf("%s -- is not a palindrome.\n\n",k);
				continue;
			}
			printf("%s -- is a regular palindrome.\n\n",k);
			continue;
		}
		else
		{
			if(d==1)
			{
				printf("%s -- is a mirrored string.\n\n",k);
				continue;
			}
			printf("%s -- is a mirrored palindrome.\n\n",k);
			continue;
		}
	}
	return 0;
}