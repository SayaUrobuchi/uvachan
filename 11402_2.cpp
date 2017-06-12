#include <stdio.h>
#include <stdlib.h>

int list[2008], start[1008], end[1008], num[2008], len[2008], hash[1024005], repeat[1024005];
char type[1008], buf[1024], str[1024005];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int main()
{
	int cas, count, n, m, o, i, j, l, temp;
	char *ptr, *tail;
	gets(buf);
	for(ptr=buf, count=0; *ptr; count=count*10+*(ptr++)-48);
	for(cas=0; ++cas<=count; )
	{
		gets(buf);
		for(ptr=buf, m=0; *ptr; m=m*10+*(ptr++)-48);
		tail = str;
		for(; m--; )
		{
			gets(buf);
			for(ptr=buf, o=0; *ptr; o=o*10+*(ptr++)-48);
			gets(buf);
			for(; o--; )
			{
				for(ptr=buf; *ptr; *(tail++)=*(ptr++));
			}
		}
		gets(buf);
		for(ptr=buf, m=0; *ptr; m=m*10+*(ptr++)-48);
		repeat[0] = cas;
		list[0] = 0;
		repeat[temp=tail-str] = cas;
		list[1] = temp;
		for(i=0, n=2; i<m; i++)
		{
			gets(buf);
			type[i] = *buf;
			for(ptr=buf+2, temp=0; *ptr!=' '; temp=temp*10+*(ptr++)-48);
			start[i] = temp;
			if(repeat[temp] != cas)
			{
				repeat[temp] = cas;
				list[n++] = temp;
			}
			for(ptr++, temp=0; *ptr; temp=temp*10+*(ptr++)-48);
			end[i] = ++temp;
			if(repeat[temp] != cas)
			{
				repeat[temp] = cas;
				list[n++] = temp;
			}
		}
		qsort(list, n, sizeof(int), comp);
		hash[0] = 1;
		for(i=1, j=0; i<n; i++)
		{
			hash[l=list[i]] = i + 1;
			for(temp=0; j<l; temp+=str[j++]-48);
			num[i] = temp;
			len[i] = list[i] - list[i-1];
		}
		printf("Case %d:\n", cas);
		for(i=0, o=0; i<m; i++)
		{
			if(type[i] == 'F')
			{
				for(j=hash[start[i]], l=hash[end[i]]; j<l; num[j]=len[j], j++);
			}
			else if(type[i] == 'E')
			{
				for(j=hash[start[i]], l=hash[end[i]]; j<l; num[j]=0, j++);
			}
			else if(type[i] == 'I')
			{
				for(j=hash[start[i]], l=hash[end[i]]; j<l; num[j]=len[j]-num[j], j++);
			}
			else
			{
				for(j=hash[start[i]], l=hash[end[i]], temp=0; j<l; temp+=num[j++]);
				printf("Q%d: %d\n", ++o, temp);
			}
		}
	}
	return 0;
}
