/*
ID: dd.ener1
PROG: stall4
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=210;
int N,M;
bool visy[maxn];
int g[maxn][maxn];
int s[maxn];
int linky[maxn];
int res;

void input(){
	freopen("stall4.in","r",stdin);
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;++i){
		scanf("%d",s+i);
		for(long j=0;j<s[i];++j){
			int b;
			scanf("%d",&b);
			g[i][j]=b-1;
		}
	}
}

bool find(int v){
	for(int i=0;i<s[v];++i){
		int j=g[v][i];
		if(!visy[j]){
			visy[j]=true;
			if(linky[j]==-1||find(linky[j])){
				linky[j]=v;
				return true;
			}
		}
	}
	return false;
}

void solve(){
	res=0;
	memset(linky,-1,sizeof(linky));
	for(int i=0;i<N;++i){
		memset(visy,0,sizeof(visy));
		if(find(i))
			++res;
	}
}
void output(){
	freopen("stall4.out","w",stdout);
	printf("%d\n",res);
}
int main(){
	input();
	solve();
	output();
}
