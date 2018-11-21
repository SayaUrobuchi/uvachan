/*
ID: dd.ener1
PROG: ratios
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	//freopen("ratios.log","w",stdout);
	long need[3];
	long p[3][3];
	long res[3]={101,101,101};
	long res2;
	freopen("ratios.in","r",stdin);
	scanf("%d%d%d",need,need+1,need+2);
	for(long i=0;i<3;++i)
		for(long j=0;j<3;++j)
			scanf("%d",&p[i][j]);
	for(long a=0;a<=100;++a)
		for(long b=0;b<=100;++b)
			for(long c=0;c<=100;++c){
				if(a+b+c>res[0]+res[1]+res[2]||a+b+c==0)continue;
				long now[3]={a*p[0][0]+b*p[1][0]+c*p[2][0],a*p[0][1]+b*p[1][1]+c*p[2][1],a*p[0][2]+b*p[1][2]+c*p[2][2]};
				long s=need[0]?now[0]/need[0]:(need[1]?now[1]/need[1]:now[2]/need[2]);
				if(now[0]==need[0]*s&&now[1]==need[1]*s&&now[2]==need[2]*s){
					res[0]=a;
					res[1]=b;
					res[2]=c;
					res2=s;
				}
			}
	freopen("ratios.out","w",stdout);
	if(res[0]>100)
		puts("NONE");
	else
		printf("%d %d %d %d\n",res[0],res[1],res[2],res2);
	return 0;
}
