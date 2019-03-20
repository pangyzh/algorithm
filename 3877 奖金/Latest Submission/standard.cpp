#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> neigh[10001];
int in[10001]={0};
int vis[10001]={0};

int pay[10001]={0};

int main()
{
	int n,m;
	cin>>n>>m;
		for(int i = 0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;
			neigh[b].push_back(a);
			in[a]++;
		}
		queue<int> q;
		int money=0;
		int note=0;
		
		while(1)
		{
			bool flag=1;
			for(int i = 1; i<=n;i++)
			{
				if(vis[i]==0&&in[i]==0)
				{
					q.push(i);
					vis[i]=1;
					flag=0;
				}
				
			}
			if(flag==1)break;
			while(!q.empty())
			{
				int temp=q.front();
				note++;
				q.pop();
				pay[temp]+=money;
				
				for(int x=0;x<neigh[temp].size();x++)
				{
					int next=neigh[temp][x];
					in[next]--;
				}
			}
			money++;
			
		}
		if(note==n)
		{
			int result=n*100;
			for(int i = 1; i <= n;i++)
			{
				result+=pay[i];
			}
			cout<<result<<endl;
			
		}
		else
		cout<<"Poor Xed"<<endl;
}