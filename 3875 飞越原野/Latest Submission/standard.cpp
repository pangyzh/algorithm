#include<iostream>
#include<deque>
#include<string>
#include<stdio.h>
#include<memory.h>
using namespace std;

struct Node{
	int x,y;
	int d;
	Node(int x_,int y_,int d_)
	{
		x=x_;
		y=y_;
		d=d_;
	}
	Node()
	{
		x=y=d=0;
	}
}; 
int m,n,D;
bool visited[101][101][101];
char map[101][101];
int mov[4][2]={{0,1},{0,-1},{-1,0},{1,0}}; 
deque<Node> q;

bool can_vis(int x, int y, int p){  
    if (x >= 0 && x < m && y >= 0 && y < n && map[x][y] == 'P' && visited[x][y][p] == false) {  
        return true;  
    }  
    else return false;  
}  
int main()
{
	int size;
	cin>>m>>n>>D;
	Node tmp(0,0,D);
	int result=0;
	int flag=0;
	for(int i = 0; i < m; i++)
	{
		scanf("%s",&map[i]);
	}
	memset(visited,0,sizeof(visited));
	visited[tmp.x][tmp.y][tmp.d]=true;
	q.clear();
	q.push_back(tmp);
	while(!q.empty())
	{
		size=q.size();
		while(size--)
		{
			tmp=q.front();
			q.pop_front();
			if(tmp.x==(m-1)&&tmp.y==(n-1))
			{
				flag=1;
				break;
			}
			for(int i = 0; i < 4 ;i++)
			{
				if(can_vis(tmp.x+mov[i][0],tmp.y+mov[i][1],tmp.d)==true){
					Node tmp1;
					tmp1.x=tmp.x+mov[i][0];
					tmp1.y=tmp.y+mov[i][1];
					tmp1.d=tmp.d;
					visited[tmp1.x][tmp1.y][tmp1.d]=true;
					q.push_back(tmp1);
				}
			}
			for(int i = 0; i < 4;i++)
			{
				for(int j = 0;j <= tmp.d; j++)
				{
					Node tmp2;
					tmp2.x=tmp.x+mov[i][0]*j;
					tmp2.y=tmp.y+mov[i][1]*j;
					tmp2.d=tmp.d-j;
					if(can_vis(tmp2.x,tmp2.y,tmp2.d)==true)
					{
						visited[tmp2.x][tmp2.y][tmp2.d]=true;
						q.push_back(tmp2);
					}
				}
			}
		}
		if(flag==1)break;
		result++;
	}
	if(flag==1)cout<<result<<endl;
	else cout<<"impossible"<<endl;

}