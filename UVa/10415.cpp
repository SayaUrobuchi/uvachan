#include <stdio.h>
#include <string.h>

int main()
{
	int count, i, j, note, len;
	char buf[201], finger[10], now[10], table[14][10] = {
		{0, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 1, 1, 1, 0, 0, 1, 1, 1, 1}, 
		{0, 1, 1, 1, 0, 0, 1, 1, 1, 0}, 
		{0, 1, 1, 1, 0, 0, 1, 1, 0, 0}, 
		{0, 1, 1, 1, 0, 0, 1, 0, 0, 0}, 
		{0, 1, 1, 1, 0, 0, 0, 0, 0, 0}, 
		
		{1, 1, 1, 0, 0, 0, 0, 0, 0, 0}, 
		{1, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
		{0, 0, 1, 0, 0, 0, 0, 0, 0, 0}, 
		{1, 1, 1, 1, 0, 0, 1, 1, 1, 0}, 
		{1, 1, 1, 1, 0, 0, 1, 1, 0, 0}, 
		{1, 1, 1, 1, 0, 0, 1, 0, 0, 0}, 
		{1, 1, 1, 1, 0, 0, 0, 0, 0, 0}
	};
	char *ptr, *ptr2;
	scanf("%d", &count);
	gets(buf);
	while(count--)
	{
		gets(buf);
		memset(finger, 0, sizeof(finger));
		memset(now, 0, sizeof(now));
		for(ptr=buf; *ptr; ptr++)
		{
			note = *ptr;
			if(note < 97)
			{
				note -= 58;
			}
			else
			{
				note -= 97;
			}
			for(j=0, ptr2=table[note]; j<10; j++, ptr2++)
			{
				if(*ptr2 && !now[j])
				{
					now[j] = 1;
					finger[j]++;
				}
				else if(!(*ptr2))
				{
					now[j] = 0;
				}
			}
		}
		printf("%d", finger[0]);
		for(i=1; i<10; i++)
		{
			printf(" %d", finger[i]);
		}
		puts("");
	}
	return 0;
}
