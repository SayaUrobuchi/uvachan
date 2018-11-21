#include <stdio.h>

int main()
{
	while(gets(buf))
	{
		a = getcode(buf);
		al = strlen(buf);
		gets(buf);
		b = getcode(buf);
		bl = strlen(buf);
		gets(buf);
		gets(buf2);
		final = getcode(buf2);
		flen = strlen(buf2);
		memset(used, 0, sizeof(used));
		for(i=0, n=0; buf[i]; i++)
		{
			for(j=0; buf[i+j]; j++)
			{
				buf2[j] = buf[i+j];
				buf2[j+1] = 0;
				if(!used[j][temp=getcode(buf2)])
				{
					if(check(temp, j, final, flen))
					{
						break;
					}
					used[j][temp] = 1;
					queue[n] = temp;
					qlen[n++] = j;
				}
			}
			if(buf[i+j])
			{
				break;
			}
		}
		if(buf[i])
		{
			printf("YES\n");
		}
		else
		{
			for(i=0, j=n; i<j; i++)
			{
				now = queue[i];
				len = qlen[i];
				for(p=0, next=0; p<len; p++)
				{
				}
			}
		}
	}
	return 0;
}
