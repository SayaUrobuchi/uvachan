/*
ID: dd.ener1
PROG: game1
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

const long maxn=110;
long N;
long s[maxn];
long sum[maxn];
long best[maxn][maxn];//best[i][j]=sum[i..j]-min(best[i-1][j],best[i,j-1]);

void input(){
	freopen("game1.in","r",stdin);
	scanf("%d",&N);
	for(long i=0;i<N;++i)
		scanf("%d",s+i);
}
void solvesum(){
	sum[0]=0;
	for(long i=1;i<=N;++i)
		sum[i]=sum[i-1]+s[i-1];
}
inline long min(const long a,const long b){
	return a<b?a:b;
}
void solve(){
	for(long i=0;i<N;++i)
		best[i][i]=s[i];
	for(long d=1;d<N;++d){
		for(long i=0;;++i){
			long j=i+d;
			if(j>=N)break;
			best[i][j]=sum[j+1]-sum[i]-min(best[i+1][j],best[i][j-1]);
		}
	}
}
void output(){
	freopen("game1.out","w",stdout);
	printf("%d %d\n",best[0][N-1],sum[N]-best[0][N-1]);
}
int main(){
	input();
	solvesum();
	solve();
	output();
	return 0;
}
