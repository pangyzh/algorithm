#include<iostream>
#include<queue>
using namespace std;
bool map[30][30];
bool visited[30][30];

int n;
struct step{
	int x;
	int y;
	int shortest; 
	step(int x_,int y_)
	{
		x=x_;
		y=y_;
		shortest=1;
	}
	step(){
		x=y=0;
		shortest=1;
	}
};
int movex[4]={1,0,-1,0};
int movey[4]={0,1,0,-1};

void intial()
{
	for(int i = 0; i < 30 ;i++)
		for(int j = 0 ; j < 30 ; j++)
			{
			map[i][j]=0;
			visited[i][j]=0;
			}
	
}

bool can_visit(step cur)
{
	if(cur.x>=0&&cur.x<n&&cur.y>=0&&cur.y<n&&visited[cur.x][cur.y]==0&&map[cur.x][cur.y]==0||cur.x==n-1&&cur.y==n-1)
	return 1;
	return 0;
}

void BFS()
{
	if(n==1)
	{
		cout<<1<<endl;
		return ;
	}
	queue<step> q;
	visited[0][0]=1;
	step first(0,0);
	q.push(first);

	while(!q.empty())
	{
		step cur=q.front();
		q.pop();
		//cout<<cur.x<<cur.y<<endl;
		for(int i = 0 ;i < 4; i++)
		{
			step next; 
			next.x=cur.x+movex[i];
			next.y=cur.y+movey[i];
			next.shortest=cur.shortest;
			if(can_visit(next)){
				visited[next.x][next.y]=1;
				next.shortest++;
				if(next.x==n-1&&next.y==n-1)
				{
					cout<<next.shortest<<endl;
					return ;
				}
				q.push(next);
				
				}
		}
	}
	cout<<0<<endl;
}

int main()
{
	while((scanf("%d",&n))&&n!=0)
	{
		intial();
		for(int i = 0; i < n;i++)
			for(int j = 0; j < n;j++)
				cin>>map[i][j];
		BFS();
	}
}