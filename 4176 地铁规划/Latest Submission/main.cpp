#include<iostream>
#include<string.h>
using namespace std;

int map[101][101];
bool visited[101];
int low[101];
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n; 
		cin>>n;
		memset(map,0,sizeof(map));
		memset(visited,0,sizeof(visited));
		memset(low,0,sizeof(low));
		for(int i = 0; i < n ; i++)
		{
			for(int j = 0;j<n;j++)
			{
				cin>>map[i][j];
			}
			low[i]=map[0][i];
		}
		int num=0;
		int pos=0;
		visited[0]=0;
		for(int i = 0;i<n;i++)
		{
			int min=10000;
			for(int j = 0; j < n ;j++)
			{
				if(visited[j]==0&&min>low[j])
				{
					min=low[j];
					pos=j;
				}
			}
			num+=min;
			visited[pos]=1;
			for(int j =0;j<n;j++)
			{
				if(visited[j]==0&&low[j]>map[pos][j])
				low[j]=map[pos][j];
			}
		}
		cout<<num<<endl;
		
	}
} 