
#include<stdio.h>
#include<string.h>

int arr[100000];
int main()

{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(arr,0,sizeof(arr));
		int n;
		int count=0;
		char c;
		scanf("%d",&n);
		arr[n]++;
		count++;
		while((scanf("%c",&c))&&c!='\n')
		{
			scanf("%d",&n);
			arr[n]++;
			count++;
			
		}
		int flag=0;
		for(int i = 1;i < 100000;i++)
		{
			if(arr[i]!=0)
			if(arr[i]>count/2)
			{
			printf("%d\n",i);
			flag=1;
			break;
			}
			
		}
		if(flag==0)
		printf("0\n");
		
	}
}