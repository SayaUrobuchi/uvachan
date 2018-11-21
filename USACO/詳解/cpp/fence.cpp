/*
ID: dd.ener1
PROG: fence
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

const long N=500;//顶点以1-500编号 
long G[510][510];//记录两个顶点之间边的条数
long con[510];//每个点的度 
long cir[1100];
long cirsize;

inline long& g(long a,long b){
	if(a<b)return G[a][b];
	return G[b][a];
}
void input(){
	memset(G,0,sizeof(G));
	memset(con,0,sizeof(con));
	freopen("fence.in","r",stdin);
	long m;
	scanf("%d",&m);
	while(m--){
		long a,b;
		scanf("%d%d",&a,&b);
		++g(a,b);
		++con[a];
		++con[b];
	}
}
inline void del_edge(long a,long b){
	--g(a,b);
	--con[a];
	--con[b];
}
void find(long k){
	while(con[k])
		for(long i=1;i<=N;++i)
			if(g(k,i)){
				del_edge(k,i);
				find(i);
			}
	cir[cirsize++]=k;
}
void solve(){
	cirsize=0;
	long beg=1;
	for(long i=N;i>=0;--i)
		if(con[i]%2)beg=i;
	find(beg);
}
void output(){
	freopen("fence.out","w",stdout);
	for(--cirsize;cirsize>=0;--cirsize)
		printf("%d\n",cir[cirsize]);
}
int main(){
	input();
	solve();
	output();
}
