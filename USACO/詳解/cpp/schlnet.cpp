/*
ID: dd.ener1
PROG: schlnet
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=128;
bool g[maxn][maxn];
int N;
int R1,R2;
int r[maxn];//强连通子图的代表顶点 

void input(){
	memset(g,0,sizeof(g));
	freopen("schlnet.in","r",stdin);
	scanf("%d",&N);
	for(int i=1;i<=N;){
		int x;
		scanf("%d",&x);
		if(!x)++i;
		else g[i][x]=true;
	}
}
void solve(){
	for(int k=1;k<=N;++k)	
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				if(g[i][k]&&g[k][j])g[i][j]=true;
	for(int i=1;i<=N;++i){
		if(r[i])continue;
		r[i]=i;
		for(int j=1;j<=N;++j){
			if(g[i][j]&&g[j][i])
				r[j]=i;
		}
	}
	int n=0,NoIn=0,NoOut=0;
	for(int i=1;i<=N;++i){
		if(r[i]!=i)continue;
		++n;
		bool in=false,out=false;
		for(int j=1;j<=N;++j){
			if(i==j)continue;
			if(r[j]!=j)continue;
			if(g[i][j])out=true;
			if(g[j][i])in=true;
		}
		if(!in)++NoIn;
		if(!out)++NoOut;
	}
	if(n==1){
		R1=1;
		R2=0;
	}
	else{
		R1=NoIn;
		if(R1==0)R1=1;
		R2=NoIn>NoOut?NoIn:NoOut;
	}
}
void output(){
	freopen("schlnet.out","w",stdout);
	printf("%d\n%d\n",R1,R2);
}
int main(){
	//freopen("schlnet.log","w",stdout);
	input();
	solve();
	output();
}
