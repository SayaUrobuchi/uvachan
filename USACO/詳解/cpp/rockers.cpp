/*
ID: dd.ener1
PROG: rockers
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

const long maxN=20,maxM=20,maxT=20;
long N,M,T;
long time[maxN];
long f[maxN][maxM][maxT+1];//f[i][j][t]��ʾ���ǵ���i�׸裬����j���������̣����һ�����Ѿ�����t����ʱ�ܹ�¼�Ƶ������� 
/*
f[i][j][t]=max{
	f[i][j][t-1],//Ϊ�˱��ֵ�����
	f[i-1][j][t],//��¼��i�׸裬ǰ����i!=0 
	f[i-1][j][t-time[i]]+1,//����i�׸�ŵ����һ�����ǰ����t-time[t]>=0
	f[i-1][j-1][T]+t>=time[i]//�¿�һ���̣�ǰ��ĸ趼¼��ǰһЩ���ǰ����j!=0 
}
*/
void input(){
	freopen("rockers.in","r",stdin);
	scanf("%d%d%d",&N,&T,&M);
	for(long i=0;i<N;++i)
		scanf("%d",time+i);
}
void update(long& old,const long now){
	if(old<now)old=now;
}
void solve(long i,long j,long t){//���ô˺�����ǰ����i!=0
	long& now=f[i][j][t];
	now=f[i-1][j][t];
	if(t!=0)update(now,f[i][j][t-1]);
	if(t>=time[i])update(now,f[i-1][j][t-time[i]]+1);
	if(j!=0)update(now,f[i-1][j-1][T]+(t>=time[i]));
}
void solve(){
	memset(f,0,sizeof(f));
	for(long j=0;j<M;++j)
		for(long t=0;t<=T;++t)
			f[0][j][t]=(t>=time[0]);
	for(long i=1;i<N;++i)
		for(long j=0;j<M;++j)
			for(long t=0;t<=T;++t)
				solve(i,j,t);
}
void output(){
	freopen("rockers.out","w",stdout);
	printf("%d\n",f[N-1][M-1][T]);
}
int main(){
	input();
	solve();
	output();
}
