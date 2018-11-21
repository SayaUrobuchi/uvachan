#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define PI (2*acos(0.0))
using namespace std;
struct P{
    double x,y,slp;
    int val;
}ori[10000],p[10000];
double ABS(double a){
    if(a>0) return a;
    else return -a;
}
bool eq(double a,double b){
    if(ABS(a-b)<(double)(1e-10)) return 1;
    else return 0;
}
int ans;
double slope(P a){
    if(eq(a.y,p[0].y)){
    if(a.x>0) return 0.0;
    else return PI;
    }else if(eq(a.x,p[0].x)){
    if(a.y>0) return PI/2;
    else return 3*PI/2;
    }
    double tmp=atan((a.y-p[0].y)/(a.x-p[0].x));
    if(a.x<p[0].x)
    {
    tmp+=PI;
    }
    if(a.x>p[0].x && a.y<p[0].y)
    {
    tmp+=2*PI;
    }

    return tmp;
}
bool cmp(P a,P b){
    return a.slp<b.slp;
}
    void Relax(int x){
    if(x>ans)
        ans=x;
    }
int n;
int main(){
    int cc;
    int L,R,RR;
    int Lsum,Rsum;
    while(scanf("%d",&n)!=EOF){
    if(n==0)
        break;
    for(int i=0;i<n;i++){
        scanf("%d%lf%lf",&ori[i].val,&ori[i].x,&ori[i].y);
    }
    ans=0;
    for(int cho=0;cho<n;cho++){
        cc=0;
        p[cc++]=ori[cho];
        for(int i=0;i<n;i++){
        if(i!=cho){
            p[cc]=ori[i];
            p[cc].slp = slope(p[cc]);
            cc++;
        }
        }
        sort(p+1,p+n,cmp);
//      puts("$#######$");
//      for(int i=1;i<n;i++){
//      printf("QQ %.3lf %d\n",p[i].slp,p[i].val);
//      }

        Lsum = Rsum = 0;
        L=R=1;
        for(;R<n && p[R].slp<PI;R++)
        Lsum = Lsum + p[R].val;
        for(int i=R;i<n;i++)
        Rsum = Rsum + p[i].val;    
        double deg = 0.0;   
        while(L<n && deg<=PI){          
//      printf("deg = %.3lf L=%d ,R=%d, %d %d %d\n",deg,L,R,Lsum,Rsum,p[0].val);        
        Relax((Lsum+p[0].val)*(Rsum));
        Relax((Lsum)*(Rsum+p[0].val));          
        if(R==n || (ABS(deg-p[L].slp) < ABS(p[R].slp - (deg + PI))) ){
            int tmp = L;
            while(L<n && eq(p[tmp].slp,p[L].slp)){
            Lsum = Lsum - p[L].val;
            Rsum = Rsum + p[L].val;
            deg = p[L].slp;
            L++;            
            }
            while(R<n && eq(p[tmp].slp+PI,p[R].slp)){
            Lsum = Lsum + p[R].val;
            Rsum = Rsum - p[R].val;
            deg = p[R].slp - PI;
            R++;
            }
        }else{
            int tmp = R;
            while(R<n && eq(p[tmp].slp,p[R].slp)){
            Lsum = Lsum + p[R].val;
            Rsum = Rsum - p[R].val;
            deg = p[R].slp - PI;
            R++;
            }
            while(L<n && eq(p[tmp].slp-PI,p[L].slp)){
            Lsum = Lsum - p[L].val;
            Rsum = Rsum + p[L].val;
            deg = p[L].slp;
            L++;
            }
        }
        }
    }
    printf("%d\n",ans);
    }



}
