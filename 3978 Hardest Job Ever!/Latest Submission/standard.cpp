#include<iostream>

using namespace std;

int map[201][201];
bool found[201];
int dis[201];

int cross;
void djik()
{
	int u=0;
	int min;
	for(int i = 0;i < cross; i++)
	{
		found[i]=0;
		dis[i]=map[u][i];
	}
	found[0]=1;
	dis[0]=0;
	for(int i = 1 ; i < cross; i++)
	{
		min = 10000000;
		for(int j = 0; j < cross; j++)
		{
			if(!found[j]&&dis[j]<min)
			{
			min=dis[j];
			u=j;
			}
		}
		found[u]=1;
		for(int k = 0; k < cross; k++)
		{
			if(!found[k]&&dis[u]+map[u][k]<dis[k])
			dis[k]=dis[u]+map[u][k];
		}
	}
} 
void intial()
{
	for(int i = 0; i < 201; i++)
	{
		for(int j = 0;j < 201;j++)
		map[i][j]=10000000; 
		map[i][i]=0;
	} 
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int road;
		cin>>cross>>road;
		intial();
		for(int i = 0;i < road;i++){
			int cityi,cityj,length;
			cin>>cityi>>cityj>>length;
			if(length<map[cityi-1][cityj-1]) {
			map[cityi-1][cityj-1]=length;
			map[cityj-1][cityi-1]=length;
			}
		}

		djik();
		if(dis[cross-1]==10000000)cout<<"-1"<<endl; 
		else cout<<dis[cross-1]<<endl;
	}
}