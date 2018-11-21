/*
ID: dd.ener1
PROG: latin
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

//��һ�з�1-n����һ��Ҳ��1-n�������(n-1)!����
//ʹ���û�Ⱥ�ķ�����֦ 

const int maxn=16;
int N;
bool putx[maxn][maxn];//putx[x][k]��ʾ�ڵ�x���Ѿ��Ź�k������ 
bool puty[maxn][maxn];
long long int res;
int s[maxn][maxn];
int h[maxn][maxn*maxn];//ָǰ�����û�Ȧ�ĸ���Ϊi,�����û�Ȧ���ȵĻ�Ϊjʱ�Ľ� 

void input(){
	freopen("latin.in","r",stdin);
	scanf("%d",&N);
}
void put(int x,int y,int k){
	putx[x][k]=true;
	puty[y][k]=true;
	s[x][y]=k;
}
void unput(int x,int y,int k){
	putx[x][k]=false;
	puty[y][k]=false;
	s[x][y]=0;
}
void pretreat(){
	memset(putx,0,sizeof(putx));
	memset(puty,0,sizeof(puty));
	for(int i=1;i<=N;++i){
		put(1,i,i);
		put(i,1,i);
	}
	memset(h,-1,sizeof(h));
}
unsigned int search(int x,int y){
	if(x>=N)return 1;
	if(x==3&&y==2){
		static bool v[maxn];
		memset(v,0,sizeof(v));
		int i=0,j=1;
		for(int k=1;k<=N;++k){
			if(v[k])continue;
			v[k]=true;
			int n=1;
			for(int l=s[2][k];l!=k;l=s[2][l]){
				v[l]=true;
				++n;
			}
			++i;
			j*=n;
		}
		if(h[i][j]!=-1)return h[i][j];
		int res=0;
		for(int k=1;k<=N;++k){
			if(putx[x][k])continue;
			if(puty[y][k])continue;
			put(x,y,k);
			res+=(y!=N?search(x,y+1):search(x+1,2));
			unput(x,y,k);
		}
		return h[i][j]=res;
	}
	int res=0;
	for(int k=1;k<=N;++k){
		if(putx[x][k])continue;
		if(puty[y][k])continue;
		put(x,y,k);
		res+=(y!=N?search(x,y+1):search(x+1,2));
		unput(x,y,k);
	}
	return res;
}
void solve(){
	pretreat();
	res=search(2,2);
	for(int i=2;i<N;++i)
		res*=i;
}
void output(){
	freopen("latin.out","w",stdout);
	cout<<res<<endl;
}
int main(){
	//freopen("latin.log","w",stdout);
	input();
	solve();
	output();
}
