#include<iostream>
using namespace std;
int main()
{
    int test, n, num;
    int max, count;
    cin>>test;
    while (test--)
    {
        count = 0;
        cin>>n>>max;
        
        for (int i = 1; i < n; i++){
            cin>>num;
            if (max < num)
                 max = num;  
            else
                 count += 5;                
        }  
        printf("%d\n", count);   
    }
    
}