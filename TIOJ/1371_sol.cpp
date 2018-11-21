
      /* 1371 Judge Code by akira */
      #include<algorithm>
      using namespace std;

      struct point {int x,y,z;};
      int n; point base[100000];
      bool inhull[100000];
      int m,order[100000];

      namespace S
      {
      	int data[100000],size;

      	void push(int x){data[size++]=x;}
      	void pop(){size--;}
      	int top(){return data[size-1];}
      	bool empty(){return !size;}

      	int cmp(const point& c)
      	{
      		long long x1,y1,x2,y2;
      		x1=(long long)base[data[size-1]].x-base[data[size-2]].x;
      		y1=(long long)base[data[size-1]].y-base[data[size-2]].y;
      		x2=(long long)c.x-base[data[size-2]].x;
      		y2=(long long)c.y-base[data[size-2]].y;
      		x1=x1*y2-x2*y1;
      		if(x1>0)return 1;
      		if(x1<0)return-1;
      		return 0;
      	}
      }

      bool cmp(const point& p,const point& q)
      {
      	return p.x<q.x;
      }

      void upper_hull()
      {
      	int i,j,k;
      	for(i=0;i<n;i=j)
      	{
      		k=i;
      		for(j=i+1;j<n;j++)
      		{
      			if(base[j].x!=base[i].x)break;
      			if(base[j].y>base[k].y)k=j;
      		}
      		while(S::size>=2&&S::cmp(base[k])>=0)S::pop();
      		S::push(k);
      	}
      	while(!S::empty())
      	{
      		inhull[S::top()]=1;
      		S::pop();
      	}
      }

      void lower_hull()
      {
      	int i,j,k;
      	for(i=0;i<n;i=j)
      	{
      		k=i;
      		for(j=i+1;j<n;j++)
      		{
      			if(base[j].x!=base[i].x)break;
      			if(base[j].y<base[k].y)k=j;
      		}
      		while(S::size>=2&&S::cmp(base[k])<=0)S::pop();
      		S::push(k);
      	}
      	while(!S::empty())
      	{
      		inhull[S::top()]=1;
      		S::pop();
      	}
      }

      void solve()
      {
      	sort(base,base+n,cmp);
      	upper_hull();
      	lower_hull();
      	int i,j=0;
      	for(i=0;i<n;i++)if(inhull[i])j++;
      	printf("%d\n",j);
      	for(i=0;i<n;i++)if(inhull[i])order[m++]=base[i].z;
      	sort(order,order+m);
      	for(i=0;i<m;i++)printf("%d\n",order[i]);
      }

      void input()
      {
      	scanf("%d",&n);
      	for(int i=0;i<n;i++)
      	{
      		scanf("%d%d",&base[i].x,&base[i].y);
      		base[i].z=i+1;
      	}
      }

      int main()
      {
      	input();
      	solve();
      	for(; ; );
      	return 0;
      }

