#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	node *next;
	char word[51];
};
void release(node *nod)
{
	if(nod->next!=NULL)
	{
		release(nod->next);
	}
	free(nod);
}
int main()
{
	int len,i,j,num,ok,k;
	char str[9000],wtmp[9000],check[128];
	node *head,*tmp,*now;
	head=NULL;
	for(i=0;i<128;i++)
	{
		check[i]=0;
	}
	for(i=48;i<58;i++)
	{
		check[i]=2;
	}
	for(i=65;i<91;i++)
	{
		check[i]=1;
	}
	for(i=97;i<123;i++)
	{
		check[i]=1;
	}
	while(gets(str))
	{
		if(!strcmp(str,"0"))
		{
			break;
		}
		len=strlen(str);
		num=0;
		ok=0;
		j=0;
		for(i=0;i<len;i++)
		{
			if(check[str[i]]==1)
			{
				wtmp[j++]=str[i];
				ok=1;
			}
			else if(check[str[i]]==2)
			{
				num*=10;
				num+=str[i]-48;
			}
			else
			{
				if(num)
				{
					if(num>1)
					{
						tmp=head;
						for(k=2;k<num;k++)
						{
							tmp=tmp->next;
						}
						now=tmp->next;
						tmp->next=now->next;
						now->next=head;
						head=now;
					}
					printf("%s",head->word);
					num=0;
				}
				else if(ok)
				{
					tmp=head;
					wtmp[j]=0;
					printf("%s",wtmp);
					head=(node*)malloc(sizeof(node));
					strcpy(head->word,wtmp);
					head->next=tmp;
					j=0;
					ok=0;
				}
				printf("%c",str[i]);
			}
		}
		if(num)
		{
			if(num>1)
			{
				tmp=head;
				for(k=2;k<num;k++)
				{
					tmp=tmp->next;
				}
				now=tmp->next;
				tmp->next=now->next;
				now->next=head;
				head=now;
			}
			printf("%s",head->word);
			num=0;
		}
		else if(ok)
		{
			tmp=head;
			wtmp[j]=0;
			printf("%s",wtmp);
			head=(node*)malloc(sizeof(node));
			strcpy(head->word,wtmp);
			head->next=tmp;
			j=0;
			ok=0;
		}
		printf("\n");
	}
	release(head);
	return 0;
}