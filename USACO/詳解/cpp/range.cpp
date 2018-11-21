/*
ID: dd.ener1
PROG: range
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

const long maxN=250;
long N;
bool g[maxN][maxN];
long maxs[maxN][maxN];//maxs[i][j]=min(maxs[i-1][j-1]+1,maxl[i][j],maxu[i][j])(if g[i][j])
long counts[maxN+1];

void input(){
	freopen("range.in","r",stdin);
	scanf("%d\n",&N);
	for(long i=0;i<N;++i){
		for(long j=0;j<N;++j)
			g[i][j]=getchar()-'0';
		getchar();//ignore '\n'
	}
}
void solvemaxl(){
	for(long i=0;i<N;++i){
		maxl[i][0]=g[i][0];
		for(long j=1;j<N;++j)
			maxl[i][j]=g[i][j]?maxl[i][j-1]+1:0;
	}
}
void solvemaxu(){
	for(long j=0;j<N;++j){
		maxu[0][j]=g[0][j];
		for(long i=1;i<N;++i)
			maxu[i][j]=g[i][j]?maxu[i-1][j]+1:0;
	}
}
void solvemaxs(){
	for(long k=0;k<N;++k){
		maxs[k][0]=g[k][0];
		maxs[0][k]=g[0][k];
	}
	for(long i=1;i<N;++i)
		for(long j=1;j<N;++j){
			if(!g[i][j]){
				maxs[i][j]=0;
				continue;
			}
			maxs[i][j]=maxs[i-1][j-1]+1;
			if(maxl[i][j]<maxs[i][j])maxs[i][j]=maxl[i][j];
			if(maxu[i][j]<maxs[i][j])maxs[i][j]=maxu[i][j];
		}
}
void count(){
	memset(counts,0,sizeof(counts));
	for(long i=0;i<N;++i)
		for(long j=0;j<N;++j)
			++counts[maxs[i][j]];
}
void solve(){
	solvemaxl();
	solvemaxu();
	solvemaxs();
	count();
}
void output(){
	freopen("range.out","w",stdout);
	long s=0;
	for(long k=2;k<=N;++k)
		s+=counts[k];
	for(long k=2;;++k){
		if(!s)break;
		printf("%d %d\n",k,s);
		s-=counts[k];
	}
}
int main(){
	input();
	solve();
	output();
}
