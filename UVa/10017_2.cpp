/*ACM Q10017*/
/*6	6243337	FGISC¡EAikoSenoo	0.010	ANSI C	2008-02-20 03:00:12*/
/*hanoi--recusive*/
#include<stdio.h>
#include <string.h>
int k;
int h[4][250], hn[4];
char tower[3][1001], *ptr[3];
/*void show(){
	int i, j;
	for(j=0; j<3; j++){
		printf("%c=>", j + 'A');
		if(hn[j] != 0)
			printf("  ");
		for(i=0; i<hn[j]; i++){
			printf(" %d",h[j][i]);
		}
		printf("\n");	
	}printf("\n");
}*/
/*void hanoi(int n, int A, int B, int C){
	if(n == 0)return;
	hanoi(n-1, A, C, B);
	if(k == 0) return;
	h[C][hn[C]++] = h[A][--hn[A]];
	show();
	k--;
	if(k == 0) return;
	hanoi(n-1, B, A, C);
}*/
void show()
{
	int j;
	for(j=0; j<3; j++)
	{
		if(tower[j][5])
		{
			puts(tower[j]);
		}
		else
		{
			printf("%.3s\n", tower[j]);
		}
	}
	putchar(10);
}
void hanoi(int n, int A, int B, int C){
	if(n == 0)return;
	hanoi(n-1, A, C, B);
	if(k == 0) return;
	for(; *ptr[A]!=' '; ptr[A]--);
	strcpy(ptr[C], ptr[A]);
	ptr[C] += strlen(ptr[C]);
	*ptr[A] = 0;
	show();
	k--;
	if(k == 0) return;
	hanoi(n-1, B, A, C);
}
int main(){
	int n;
	int i, cnt = 1;
	while(scanf("%d %d", &n, &k) != EOF){
		if(n == 0 && k == 0) break;
		printf("Problem #%d\n\n", cnt++);
		/*for(i=n; i>=1; i--)
			h[0][n-i] = i;
		hn[0] = n;
		hn[1] = hn[2] = 0;*/
		strcpy(tower[0], "A=>  ");
		strcpy(tower[1], "B=>  ");
		strcpy(tower[2], "C=>  ");
		ptr[0] = tower[0] + strlen(tower[0]);
		ptr[1] = tower[1] + strlen(tower[1]);
		ptr[2] = tower[2] + strlen(tower[2]);
		for(i=0; i<n; i++)
		{
			sprintf(ptr[0], " %d\0", n-i);
			ptr[0] += strlen(ptr[0]);
		}
		show();
		if(k > 0)
			hanoi(n, 0, 1, 2);	

	}
    return 0;
}
