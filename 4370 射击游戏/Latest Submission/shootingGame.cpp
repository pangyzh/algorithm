#include<iostream>  
using namespace std;  
int main()  
{  
    int s[11]={0};  
    int t,temp,rem=0,flag=0;  
    cin>>t;  
 	while(t--){
        for(int j=0;j<10;j++)  
        {  
            cin>>temp;  
            s[temp]=1;  
            if(j>=1&&temp<rem-1)  
            {  
                for(int k=temp+1;k<rem;k++)  
                {  
                    if(s[k]==0)  
                    {  
                        flag=1;  
                        break;  
                    }  
                }  
            }  
            rem=temp;  
        }  
        if(flag==1)cout<<"No"<<endl;  
        else cout<<"Yes"<<endl;  
        for(int l=0;l<10;l++)  
        s[l]=0;  
        flag=0;  
    }  
}            