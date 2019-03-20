#include<iostream>
#include<string.h>
using namespace std;

bool map[101][101];
bool visited[101];
int ans=0;	
int n,m;
void intial()
{
	memset(map,0,sizeof(map));
}

void dfs(int start)
{		
	visited[start]=true;
	for(int i = 0; i <n ; i++)
	{
		if(!visited[i]&&map[start][i]==1)
		{
			visited[i]=1;
			dfs(i);
		}
	}
}

int main()
{

	cin>>n>>m;		
	intial();
	while(m--)
	{
		int u,v;

		cin>>u>>v;
		map[u-1][v-1]=1;
		map[v-1][u-1]=1;
	}
	for(int i = 0; i <n ;i++)
	{
		if(!visited[i])
		{
			ans++;
			dfs(i);
		}
	}
	cout<<ans<<endl;
}