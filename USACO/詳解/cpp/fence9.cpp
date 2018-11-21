/*
ID: dd.ener1
PROG: fence9
LANG: C++
*/
#include <cstdio>
#include <cmath>
using namespace std;

long N,M,P;
long res;

/*
三个点 (0,0)、(n,m)、(p,0) 
两条直线的方程： 
ny=mx
(x-n)/(x-p)=(y-m)/y
(p-n)y=pm-mx
*/

void input(){
	freopen("fence9.in","r",stdin);
	scanf("%d%d%d",&N,&M,&P);
}
long solve(){
	res=0;
	double n=N;
	double m=M;
	double p=P;
	for(long y=1;y<M;++y){
		long x1=(long)ceil(n*y/m+0.000001);
		long x2=(long)floor((p*m-(p-n)*y)/m-0.000001);
		res+=(x2-x1+1);
	}
}
void output(){
	freopen("fence9.out","w",stdout);
	printf("%d\n",res);
}
int main(){
	//freopen("fence9.log","w",stdout);
	input();
	solve();
	output();
	return 0;
}
