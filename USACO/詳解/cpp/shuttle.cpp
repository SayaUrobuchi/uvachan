/*
ID: dd.ener1
PROG: shuttle
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;


int N,n;
int s[30];
int o[1000];

int zero(){
	for(int i=1;i<=2*N+1;++i)
		if(s[i]==0)return i;
}
void swap(int i,int j){
	int t=s[i];
	s[i]=s[j];
	s[j]=t;
}
void move1(){
	int z=zero(),i;
	for(i=z;s[i]!=1;--i);
	swap(i,z);
	o[n++]=i;
}
void move2(){
	int z=zero(),i;
	for(i=z;s[i]!=2;++i);
	swap(i,z);
	o[n++]=i;
}

int main(){
	freopen("shuttle.in","r",stdin);
	freopen("shuttle.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
		s[i]=1;
	s[N+1]=0;
	for(int i=N+2;i<=N*2+1;++i)
		s[i]=2;
	n=0;
	for(int i=1;i<=N;++i)
		for(int j=0;j<i;++j)
			if(i%2)move1();
			else move2();
	for(int i=1;i<=N;++i)
		if(N%2)move2();
		else move1();
	for(int i=N;i>=1;--i)
		for(int j=0;j<i;++j)
			if(i%2)move1();
			else move2();
	for(int i=0;i<n;++i){
		if(i==n-1||i%20==19)
			printf("%d\n",o[i]);
		else
			printf("%d ",o[i]);
	}
}
