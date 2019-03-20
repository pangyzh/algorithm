#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int arr[10000];

void solution(int a[],int n)
{
	queue<int> q1,q2;
	for(int i = 0 ; i < n ; i++)
	{
		//printf("%d ",a[i]);
		if(a[i]%2==1)
		{
			q1.push(a[i]);
		}
		else q2.push(a[i]);
	}
	int temp;
	while(!q1.empty())
	{
		temp=q1.front();
		q1.pop();
		printf("%d ",temp);
	}
	while(!q2.empty())
	{
		temp=q2.front();
		q2.pop();
		printf("%d ",temp);
	}
	printf("\n");
}

int main()

{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		int count=0;
		char c;
		scanf("%d",&arr[0]);
		count++;
		while((scanf("%c",&c))!=EOF&&c!='\n')
		{
			scanf("%d",&arr[count]);
			count++;
		}
		solution(arr,count);
	}
}