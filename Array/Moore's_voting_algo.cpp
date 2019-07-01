//to find maximum occurence of a number in an array
#include<iostream>
using namespace std;
int findcanditate(int a[],int n)
{
	int maj_index=0,i,count=1;
	for(i=1;i<n;i++)
	{
		if(a[maj_index]==a[i])    //checking the maj index is equal to other 
		{							//if equal then increment the count
			count++;				//if not then decrement the count
		}
		else
		{
			count--;
		}
		if(count==0)    		//if equal to 0 then shift the value of i to 
		{						//majority index and continue checking 
			maj_index=i;
			count=1;			//assign count 1 ie start from begining to check again
		}			
	}							//Like this  cancel out each occurrence of an element e with all  
	return a[maj_index];		// the other elements that are different from e then e will exist till 
}								//end if it is a majority element.
bool ismajority(int a[],int n,int key)
{
	int count=0,i;
	for(i=0;i<n;i++)
	{
		if(a[i]==key)
		{
			count++;
		}
	}
	if(count>=n/2)    //to find majority incase of even number eg 8 to find majority n/2 ie 8/2 is 4 then 
	{				//that majority element occurrence times will be greater than 4 
		return 1;   //incase of odd elements eg 7 then 7/2 is 3 then that majority element occurrence 
	}				//times will be greater than 3 so obivously out of 7 elements minimum 4 times 
 	else 			//occurence is the majority element 
	{
		return 0;
	}
}
int printmajority(int a[],int n)
{
	int cand;
	cand=findcanditate(a,n);   //calling the function find canditate 
	if(ismajority(a,n,cand))
	{
		cout<<cand;
	}
	else
	{
		cout<<"No majority element found";
	}
	return 0;
}
int main()
{
	int a[]={1,3,1,3,2,1};
	int n=sizeof(a)/sizeof(a[0]);
	printmajority(a,n);
	return 0;
}