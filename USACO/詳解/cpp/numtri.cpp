/*
ID: dd.ener1
PROG: numtri
LANG: C++
*/
#include <fstream>
using namespace std;

//D[i,j]=max{D[i-1,j-1],D[i-1,j]}+S[i,j];
int main(){
	long n;
	ifstream cin("numtri.in");
	cin>>n;
	long *nums=new long[n];
	long *s1=new long[n],*s2=new long[n];
	for(long i=1;i<=n;++i){
		for(long j=0;j<i;++j)cin>>nums[j];
		if(i==1)s2[0]=nums[0];
		else{
			s2[0]=s1[0]+nums[0];
			for(long j=1;j<i-1;++j)s2[j]=max(s1[j-1],s1[j])+nums[j];
			s2[i-1]=s1[i-2]+nums[i-1];
		}
		{
			long* t=s1;
			s1=s2;
			s2=t;
		}
	}
	long best=-1;
	for(long i=0;i<n;++i)if(s1[i]>best)best=s1[i];
	ofstream cout("numtri.out");
	cout<<best<<endl;
	return 0;
}
