#include<iostream>
#include<string>
#include<queue>
using namespace std;
int numofrow[100];
int numofcolumn[100];
int count=0;
string map[100];
bool visited[100][100]; 


int step[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

struct index{
	int x;
	int y;
	int c;
	index()
	{
		x=y=0;
		c=1;
	 } 
	 index(int x_,int y_,int c0)
	 {
	 	x=x_;
	 	y=y_;
	 	c=c0;
	 }
};

void intial()
{
	count=0;
	for(int i = 0;i<100;i++)
	{
		map[i]="";
		numofrow[i]=numofcolumn[i]=0;
		for(int j=0;j<100;j++)
		visited[i][j]=0;
	}
}

bool BFS(int i,int j,const int row,const int column,const string& str)
{
	queue<index> q;
	index first(i,j,1);
	q.push(first);

	while(!q.empty())
	{
		index cur=q.front();
		q.pop();
		
		for(int k =0 ;k < 4;k++)
		{
			index next;
			next.x=cur.x+step[k][0];
			next.y=cur.y+step[k][1];
			next.c=cur.c;
			if(next.x<row&&next.x>=0&&next.y<column&&next.y>=0){
			if(map[next.x][next.y]==str[next.c]&&visited[next.x][next.y]==0)
			{
				visited[next.x][next.y]==1;
				next.c=cur.c+1;
				if(next.c==str.length())
				{
					return 1;
				}

			 	q.push(next);
			}
			}
		}
	
	} 
	return 0;
} 

bool findRoad(const string& matrix,const string& str,const int row,const int column)
{
	for(int i = 0 ;i < row; i++)
	{
		string s(matrix,i*(column),column);
		map[i]=s;
		//cout<<map[i]<<endl;
	}
	for(int i = 0; i < row;i++)
	{
		for(int j = 0 ; j < column;j++)
		{
			if(map[i][j]==str[0])
			{
				if(BFS(i,j,row,column,str))//wrong
				return 1;
			}
		}
	 }
	 return 0; 
	
}

bool have_path(const string& matrix,const string& str)
{
	int length=matrix.length();
	for(int i = 1 ; i <= length/2 ; i++)
	{
		if(length%i==0)
		{
			numofrow[count]=i;
			numofcolumn[count]=length/i;
			count++;
		}
	}
	for(int i = 0 ;i < count ;i++)
		if(findRoad(matrix,str,numofrow[i],numofcolumn[i]))
			return 1;
	return 0;
	
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string Matrix,Str;
		cin>>Matrix>>Str;
		if(have_path(Matrix,Str))
		cout<<"true"<<endl;
		else cout<<"false"<<endl;
	}
}
