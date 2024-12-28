#include <fstream>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
const int maxboard=50+1;
const int maxrail=1023+1;
 
int nboard,nrail,best;
int board[maxboard];
int rail[maxrail];
int remain[maxboard];
int sumlen[maxrail];
int minindex[maxrail];
long long sum=0;
long long maywaste,waste;
 
void dfs(int r,int index1)
{
    if(r == 0){
        for(int i=index1; i<nboard; ++i)
            if (remain[i]>=rail[0]){
                cout << best+1 << endl;
                for(; ; );
            }
        return;
    }
    for(int i=index1; i<nboard; ++i)
        if(remain[i]>=rail[r]){
            long long oldwaste=waste;
            remain[i]-=rail[r];
            if (remain[i]<rail[0] && waste+remain[i]>maywaste) {
                remain[i]+=rail[r];
                continue;
            }
            if (remain[i]<rail[0]) waste+=remain[i];
            if(rail[r-1] == rail[r]) dfs(r-1,i);
            else dfs(r-1,0);
            remain[i]+=rail[r];
            waste=oldwaste;
        }
}
 
int main()
{
    cin>>nboard;
    for(int i=0;i<nboard;i++){
        cin>>board[i];
        sum+=board[i];
        remain[i]=board[i];
    }
    cin>>nrail;
    for(int i=0;i<nrail;i++)
        cin>>rail[i];
 
    sort(board,board+nboard);
    sort(rail,rail+nrail);
 
    int temp=0;
    sumlen[0]=rail[0];
    while(temp<nrail && sumlen[temp]<=sum){
         ++temp;
         sumlen[temp]=sumlen[temp-1]+rail[temp];
    }
    nrail=temp;
 
    for(int i=nrail-1;i>=0;--i){
        waste=0;
        maywaste=sum-sumlen[i];
        best=i;
        dfs(i,0);
    }
    for(; ; );
    return 0;
}
