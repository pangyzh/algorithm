#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int map[201][201];
int dis[201];
bool found[201];
int start,en;
int n,m;
void dij()
{

		int u,w;
		int min;
		for(int v=0;v<n;v++)//chu shi hua
		{
			
			found[v]=false;
			dis[v]=map[start][v];
		}
		
		found[start]=true;
		dis[start]=0;		
		
		for(int i = 0; i < n;i++)
		{
			min=1000000;
			u=start;
			for(int j=0;j<n;j++)
			if(!found[j]&&dis[j]<min)
			{
				u=j;
				min=dis[j];
			}
			found[u]=true;
			
			for(w=0;w<n;w++)
			if(!found[w]&&dis[u]+map[u][w]<dis[w]&&map[u][w]<1000000)
			dis[w]=dis[u]+map[u][w];
		
		}
}
int main()
{

	

	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i = 0; i < 201; i++){
			for(int j =0 ;j <201;j++)
			map[i][j]=1000000;
		}
		for(int i = 0;i < m;i++)
		{
			int a,b,x;
			scanf("%d%d%d",&a,&b,&x);
			if(x<map[a][b])
			map[a][b]=map[b][a]=x;
		}
		
		scanf("%d%d",&start,&en);
		
		dij();
		if(dis[en]==1000000)cout<<"-1"<<endl;
		else
		cout<<dis[en]<<endl;
		
	}
}