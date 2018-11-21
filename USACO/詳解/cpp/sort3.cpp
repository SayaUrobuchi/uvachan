/*
ID: dd.ener1
PROG: sort3
LANG: C++
*/
#include <cstdio>
using namespace std;

long N;
long* s;
long to[3][3];//to[x][y]表示应该是x的却成了y的个数 
long left[3];
long res;

void input(){
	freopen("sort3.in","r",stdin);
	scanf("%d",&N);
	s=new long[N];
	for(long i=0;i<N;++i){
		scanf("%d",s+i);
		--s[i];
	}
}
void solve_left(){
	for(long i=0;i<3;++i)left[i]=0;
	for(long i=0;i<N;++i)++left[s[i]];
}
void solve_to(){
	for(long i=0;i<3;++i)
		for(long j=0;j<3;++j)
			to[i][j]=0;
	for(long i=0;i<left[0];++i)++to[0][s[i]];
	for(long i=left[0];i<left[0]+left[1];++i)++to[1][s[i]];
	for(long i=left[0]+left[1];i<N;++i)++to[2][s[i]];
}
long min(long a,long b){
	return a<b?a:b;
}
long min(long a,long b,long c,long d){
	return min(min(a,b),min(c,d));
}
void solve(){
	solve_left();
	solve_to();
	res=0;
	for(long i=0;i<3;++i)
		left[i]-=to[i][i];
	for(long i=0;i<3;++i)
		for(long j=i+1;j<3;++j){
			long delta=min(left[i],left[j],to[i][j],to[j][i]);
			res+=delta;
			left[i]-=delta;
			left[j]-=delta;
		}
	res+=left[0]*2;
}
void output(){
	freopen("sort3.out","w",stdout);
	printf("%d\n",res);
}
int main(){
	input();
	solve();
	output();
}
