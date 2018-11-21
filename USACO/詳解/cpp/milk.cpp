/*
ID: dd.ener1
PROG: milk
LANG: C++
*/
#include <fstream>
using namespace std;

int main(){
	long n,m;
	ifstream cin("milk.in");
	cin>>n>>m;
	long P[m],A[m];
	for(long i=0;i<m;++i)cin>>P[i]>>A[i];
	bool used[m];
	memset(used,false,sizeof(used));
	long res=0;
	while(n>0){
		long low=100000000;
		long num=-1;
		for(long i=0;i<m;++i){
			if(used[i])continue;
			if(P[i]<low){
				low=P[i];
				num=i;
			}
		}
		used[num]=true;
		if(A[num]<n){
			n-=A[num];
			res+=A[num]*P[num];
		}
		else{
			res+=n*P[num];
			n=0;
		}
	}
	ofstream cout("milk.out");
	cout<<res<<endl;
}
