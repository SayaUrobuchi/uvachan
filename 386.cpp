#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h;
	for(a=1;a<201;a++)
	{
		e=a*a*a;
		for(b=2;;b++)
		{
			f=b*b*b;
			if(f>e)
			{
				break;
			}
			for(c=b;;c++)
			{
				g=c*c*c;
				if(g+f<e)
				{
					for(d=c;;d++)
					{
						h=d*d*d;
						if(g+f+h==e)
						{
							printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
							break;
						}
						else if(g+f+h>e)
						{
							break;
						}
					}
				}
				else
				{
					break;
				}
			}
		}
	}
	return 0;
}