/*
ID: dd.ener1
PROG: frameup
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char s[100][100];
char v[100][100];
int H,W;
int Up[26],Left[26],Down[26],Right[26];
bool Cover[26][26];
bool in[26];
int edge[26];
int N;
int S[26];
string res[100000];
int R;

void input(){
	freopen("frameup.in","r",stdin);
	scanf("%d %d\n",&H,&W);
	for(int i=0;i<H;++i)
		scanf("%s\n",s[i]);
}
void analysis(){
	for(int i=0;i<26;++i){
		Up[i]=Left[i]=1000;
		Down[i]=Right[i]=-1;
	}
	for(int i=0;i<H;++i)
		for(int j=0;j<W;++j){
			if(s[i][j]=='.'){
				s[i][j]=-1;
				continue;
			}
			s[i][j]-='A';
			in[s[i][j]]=true;
			if(i<Up[s[i][j]])Up[s[i][j]]=i;
			else if(i>Down[s[i][j]])Down[s[i][j]]=i;
			if(j<Left[s[i][j]])Left[s[i][j]]=j;
			else if(j>Right[s[i][j]])Right[s[i][j]]=j;
		}
	for(int i=0;i<26;++i)
		if(in[i])++N;
}
void put(int k){
	for(int i=Up[k];i<=Down[k];++i){
		v[i][Left[k]]=k;
		v[i][Right[k]]=k;
	}
	for(int i=Left[k];i<=Right[k];++i){
		v[Up[k]][i]=k;
		v[Down[k]][i]=k;
	}
}
void buildgraph(){
	for(int k=0;k<26;++k){
		if(!in[k])continue;
		for(int i=Up[k];i<=Down[k];++i){
			if(s[i][Left[k]]!=k)
				Cover[s[i][Left[k]]][k]=true;
			if(s[i][Right[k]]!=k)
				Cover[s[i][Right[k]]][k]=true;
		}
		for(int i=Left[k];i<=Right[k];++i){
			if(s[Up[k]][i]!=k)
				Cover[s[Up[k]][i]][k]=true;
			if(s[Down[k]][i]!=k)
				Cover[s[Down[k]][i]][k]=true;
		}
	}
	for(int i=0;i<26;++i){
		edge[i]=0;
		for(int j=0;j<26;++j)
			if(Cover[i][j])++edge[i];
	}
}
bool correct(){
	for(int i=0;i<H;++i)
		for(int j=0;j<W;++j)
			if(v[i][j]!=s[i][j])return false;
	return true;
}
void addres(){
	string str;
	for(int i=0;i<N;++i)
		str+=('A'+S[i]);
	res[R++]=str;
}
void topo(int k){
	if(k==N){
		addres();
		return;
	}
	for(int i=0;i<26;++i){
		if(!in[i])continue;
		if(edge[i])continue;
		S[k]=i;
		in[i]=false;
		for(int j=0;j<26;++j)
			if(Cover[j][i])--edge[j];
		topo(k+1);
		for(int j=0;j<26;++j)
			if(Cover[j][i])++edge[j];
		in[i]=true;
	}
}
void output(){
	freopen("frameup.out","w",stdout);
	for(int i=0;i<R;++i)
		puts(res[i].c_str());
}
int main(){
	//freopen("frameup.log","w",stdout);
	input();
	analysis();
	buildgraph();
	topo(0);
	output();
}
