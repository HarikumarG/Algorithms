#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[]={ -12, 11, -13, -5, 6, -7, 5, -3, -6 };
	int n=sizeof(a)/sizeof(a[0]);
	int key,j;
	for(int i=1;i<n;i++)
	{
		key=a[i];    //assigning negative to key value from the array
		if(key>0)
			continue;
		j=i-1;       //assigning positive value (ie) Before the key value it must be positive since 
						//all positive are continued  
		while(j>=0 && a[j]>0)
		{
			a[j+1]=a[j];	//Copying postive to negative value
			j=j-1;
		}
		a[j+1]=key;			//copying the negative value at the place of positive 
	}
	for(int j=0;j<n;j++)
	{
		cout<<" "<<a[j];
	}
	return 0;
}
