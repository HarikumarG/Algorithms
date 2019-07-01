/*#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=6,count=0,sum,max=-1;
    int arr[]={1, 4, 3, 3, 5, 1};
            for(int i=0;i<n-1;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    int sum = arr[i]+arr[j];       // finding sum 
                    if(sum == max)                    //checking if equal then increment 
                    {
                        count++;                   
                    }
                    if(sum > max)                   //if previous value is lesser than the new sum then 
                    {                               //assign sum value to max
                        count=1;
                        max = sum;
                    }
                }
            }
            cout<<count;   
    return 0;

}*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=6,sum,max=-1,m,y;
    int arr[]={1, 4, 3, 3, 5, 1};
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            sum = arr[i]+arr[j];
            if(sum>=max)
            {
                m=arr[i];
                y=arr[j];
                max=sum;
            }
        }
    }
    cout<<m<<","<<y;
    cout<<"\n"<<max;
    return 0;
}