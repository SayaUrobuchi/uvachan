/*
ID: dd.ener1
PROG: rectbarn
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int R,C,P;
const int maxp=90000,maxn=3000,INF=maxn*maxn;
int rocklist[maxp+2*maxn];
int *rock[maxn];
int nrock[maxn];
int h[maxn];
int l[maxn];
int r[maxn];
int best;


int comp(const void* a,const void* b){
	return *(int*)a-*(int*)b;
}
int main(){
	//freopen("rectbarn.log","w",stdout);

	memset(rocklist,-1,sizeof(rocklist));
	memset(nrock,0,sizeof(nrock));

	freopen("rectbarn.in","r",stdin);
	scanf("%d%d%d",&R,&C,&P);
	for(int i=0;i<P;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		nrock[a-1]++;
	}

	rock[0]=rocklist+1;
	for(int i=1;i<R;++i)
		rock[i]=rock[i-1]+nrock[i-1]+2;
	memset(nrock,0,sizeof(nrock));

	freopen("rectbarn.in","r",stdin);
	scanf("%d%d%d",&R,&C,&P);
	for(int i=0;i<P;++i){
		int a,b;
		scanf("%d%d",&a,&b);
		rock[a-1][nrock[a-1]++]=b-1;
	}

	for(int i=0;i<R;++i)
		qsort(rock[i],nrock[i],sizeof(int),comp);

	for(int i=0;i<R;++i){
		if(!nrock[i])continue;
		int from,to;
		for(from=1,to=1;from<nrock[i];++from,++to){
			while(from<nrock[i]&&rock[i][from]==rock[i][from-1])++from;
			if(from<nrock[i])rock[i][to]=rock[i][from];
		}
		nrock[i]=to;
	}
	for(int i=0;i<R;++i)
		rock[i][nrock[i]]=C;

	memset(h,0,sizeof(h));
	memset(l,INF,sizeof(l));
	memset(r,INF,sizeof(r));
	best=-1;
	for(int i=0;i<R;++i){
		int q=0;
		for(int j=0;j<C;++j){
			if(j==rock[i][q]){
				h[j]=0;
				l[j]=r[j]=INF;
				++q;
			}
			else{
				++h[j];
				if(l[j]>j-rock[i][q-1])
					l[j]=j-rock[i][q-1];
				if(r[j]>rock[i][q]-j)
					r[j]=rock[i][q]-j;
			}
			if(best<h[j]*(l[j]+r[j]-1))
				best=h[j]*(l[j]+r[j]-1);
		}
	}

	freopen("rectbarn.out","w",stdout);
	printf("%d\n",best);
}
