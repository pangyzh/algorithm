#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct node{
	int time;
	int index;
};

node arr[1001];

bool cmp(node a,node b)
{
	return a.time<b.time;
}

int main()
{
	int n;
	scanf("%d",&n);
	memset(arr,0,sizeof(arr));
	for(int i = 0; i < n;i++)
	{
		scanf("%d",&arr[i].time);
		arr[i].index=i;
	}
	stable_sort(arr,arr+n,cmp);
	double count=0;

	for(int i = 0; i < n ; i++)
	{
		if(i<n-1)
		printf("%d ",arr[i].index+1);
		else printf("%d",arr[i].index+1);
		count+=arr[i].time*(n-i-1);
	}
	double result;
	result=(double)count/n;
	printf("\n%.2f\n",result);
	
}