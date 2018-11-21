/*
ID: dd.ener1
PROG: barn1
LANG: C++
*/
#include <fstream>
using namespace std;


int main(){
	long m,s,c;
	ifstream cin("barn1.in");
	cin>>m>>s>>c;
	bool barn[s+1];
	memset(barn,false,sizeof(barn));
	for(long i=0;i<c;++i){
		long num;
		cin>>num;
		barn[num-1]=true;
	}
	barn[s]=true;
	long space[c+1];
	memset(space,0,sizeof(space));
	for(long now=0,pre=-1,i=0;i<=s;++i)
		if(barn[i]){
			space[now]=i-pre-1;
			pre=i;
			++now;
		}
	long res=s-space[0];
	if(c!=0)res-=space[c];
	space[0]=space[c]=0;
	bool used[c+1];
	memset(used,false,sizeof(used));
	for(long i=1;i<m;++i){
		long big=0,num=-1;
		for(long j=0;j<=c;++j){
			if(used[j])continue;
			if(space[j]>big){
				big=space[j];
				num=j;
			}
		}
		if(num==-1)break;
		used[num]=true;
		res-=space[num];
	}
	ofstream cout("barn1.out");
	cout<<res<<endl;
}
