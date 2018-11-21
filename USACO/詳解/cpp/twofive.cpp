/*
ID: dd.ener1
PROG: twofive
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

int v[6][6][6][6][6];
int maxr[5],maxc[5];
bool used[25];

int calc(int a,int b,int c,int d,int e,int l){
	int& now=v[a][b][c][d][e];
	if(now)return now;
	if(used[l])return now=calc(a,b,c,d,e,l+1);

	if(a<5&&l>maxr[0]&&l>maxc[a])now+=calc(a+1,b,c,d,e,l+1);
	if(a>b&&l>maxr[1]&&l>maxc[b])now+=calc(a,b+1,c,d,e,l+1);
	if(b>c&&l>maxr[2]&&l>maxc[c])now+=calc(a,b,c+1,d,e,l+1);
	if(c>d&&l>maxr[3]&&l>maxc[d])now+=calc(a,b,c,d+1,e,l+1);
	if(d>e&&l>maxr[4]&&l>maxc[e])now+=calc(a,b,c,d,e+1,l+1);

	return now;
}
void put(int l,int r,int c){
	memset(v,0,sizeof(v));
	v[5][5][5][5][5]=1;
	maxr[r]=maxc[c]=l;
	used[l]=true;
}
void solve_n(){
	int N;
	scanf("%d",&N);
	memset(maxr,-1,sizeof(maxr));
	memset(maxc,-1,sizeof(maxc));
	memset(used,0,sizeof(used));
	
	int in[5];
	memset(in,0,sizeof(in));

	char str[26];
	for(int a=0;a<25;++a){
		in[a/5]++;
		int l;
		for(l=0;l<25;++l)
			if(!used[l]&&l>maxr[a/5]&&l>maxc[a%5]){
				put(l,a/5,a%5);
				int t=calc(in[0],in[1],in[2],in[3],in[4],0);
				if(N-t<=0)break;
				else N-=t;
				used[l]=false;
			}
		str[a]='A'+l;
	}
	str[25]=0;
	puts(str);
}
void solve_w(){
	char str[25];
	scanf("%s\n",str);
	int N=1;
	
	int in[5];
	memset(in,0,sizeof(in));

	for(int a=0;a<25;++a){
		in[a/5]++;
		int l;
		for(l=0;l<str[a]-'A';++l)
			if(!used[l]&&l>maxr[a/5]&&l>maxc[a%5]){
				put(l,a/5,a%5);
				N+=calc(in[0],in[1],in[2],in[3],in[4],0);
				used[l]=false;
			}
		used[l]=true;
		maxr[a/5]=maxc[a%5]=l;
	}
	printf("%d\n",N);
}
int main(){
	freopen("twofive.in","r",stdin);
    freopen("twofive.out","w",stdout);
	char c;
	scanf("%c\n",&c);
	if(c=='N')
		solve_n();
	else if(c=='W')
		solve_w();
}
