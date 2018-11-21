
      /* 1381 Judge Code by akira */
      #include<algorithm>
      using namespace std;

      #define NMAX 50
      typedef unsigned long long uint64;
      const uint64 one=1;
      int N,M,Answer;
      int Rank[NMAX],Degree[NMAX];
      bool Matrix[NMAX][NMAX];
      uint64 Mask[NMAX],Pick[NMAX],Nice;

      bool cmp(int p,int q)
      {
      	return Degree[p]>Degree[q];
      }

      void DFS(int dep,uint64 SeKai,int cost)
      {
      	if(cost>=Answer)return;
      	if(SeKai==Nice){Answer=cost;return;}
      	if(dep==N)return;
      	if((SeKai|Pick[dep])!=Nice)return;
      	if((SeKai|Mask[dep])!=SeKai)DFS(dep+1,(SeKai|Mask[dep]),cost+1);
      	DFS(dep+1,SeKai,cost);
      }

      bool Input()
      {
      	int i,j,k;
      	scanf("%d%d",&N,&M);
      	if(!N)return 0;
      	memset(Matrix,0,sizeof(Matrix));
      	for(k=0;k<M;k++)
      	{
      		scanf("%d%d",&i,&j);
      		Matrix[i-1][j-1]=1;
      		Matrix[j-1][i-1]=1;
      	}
      	for(i=0;i<N;i++)
      	{
      		Matrix[i][i]=1;
      		Degree[i]=0;
      		for(j=0;j<N;j++)if(Matrix[i][j])Degree[i]++;
      	}
      	return 1;
      }

      void Solve()
      {
      	int i,j; uint64 SeKai;
      	for(i=0;i<N;i++)Rank[i]=i;
      	sort(Rank,Rank+N,cmp);
      	for(i=N-1;i>=0;i--)
      	{
      		SeKai=0;
      		for(j=0;j<N;j++)if(Matrix[Rank[i]][j])SeKai|=(one<<j);
      		Mask[i]=SeKai;
      	}
      	Pick[N-1]=Mask[N-1];
      	for(i=N-2;i>=0;i--)Pick[i]=(Pick[i+1]|Mask[i]);
      	Nice=(one<<N)-1;
      	Answer=N;
      	printf("XD\n");
      	DFS(0,0,0);
      }

      int main()
      {
      	while(Input())
      	{
      		Solve();
      		printf("%d\n",Answer);
      	}
      	return 0;
      }

