/*
ID: dd.ener1
PROG: cowxor
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=101000;

int N;
int xr[maxn];
int prev[maxn][2];
int best[maxn];
int res;

int main(){	
	freopen("cowxor.in","r",stdin);
	scanf("%d",&N);
	xr[0]=0;
	for(int i=0;i<N;++i){
		int n;
		scanf("%d",&n);
		xr[i+1]=xr[i]^n;
	}
	for(int i=0;i<=N;++i){
		prev[i][0]=i-1;
		prev[i][1]=-1;
		best[i]=i-1;
	}

	res=0;
	int w=22;
	while(w--){
		for(int i=1;i<=N;++i)
			if(prev[i][0]==-1)
				prev[i][1]=-1;
			else{
				int tmp[2];
				if(xr[i]>>w!=xr[prev[i][0]]>>w){
					tmp[0]=prev[prev[i][0]][1];
					tmp[1]=prev[i][0];
				}
				else{
					tmp[0]=prev[i][0];
					tmp[1]=prev[prev[i][0]][1];
				}
				prev[i][0]=tmp[0];
				prev[i][1]=tmp[1];
			}

        bool fnd=false;
        for(int i=1;i<=N;++i)
        	if(best[i]>=0&&
        	(((xr[i]>>w)&1)!=((xr[best[i]]>>w)&1)||prev[best[i]][1]>=0)){
        		fnd=true;
        		break;
			}
        if(fnd){
			res|=1<<w;
			for(int i=1;i<=N;++i)
				if(best[i]>=0&&
				((xr[i]>>w)&1)==((xr[best[i]]>>w)&1))
					best[i]=prev[best[i]][1];
		}
	}

	int a;
	for(a=1;best[a]==-1;++a);
	freopen("cowxor.out","w",stdout);
	printf("%d %d %d\n",res,best[a]+1,a);
}
