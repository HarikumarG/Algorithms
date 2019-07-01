#include<bits/stdc++.h>
#define ASCII_SIZE 256
using namespace std;
 
char getsecondMaxOccuringChar(char* str)
{
    // Create array to keep the count of individual
    // characters and initialize the array as 0
    int count[ASCII_SIZE] = {0};
 	int first=INT_MIN,second=INT_MIN;
    // Construct character count array from the input
    // string.
    int len = strlen(str);
    char result;
    for (int i=0; i<len; i++)
        count[str[i]]++;
    for(int i=0;i<len;i++)
    {
    	if(count[str[i]] > first)
    	{
    		second=first;
            result=str[i-1];
    		first=count[str[i]];
    	}
    	else if(count[str[i]] > second && count[str[i]] != first)
    	{
    		second=count[str[i]];
            result=str[i];
       	}
    }
 	return result;
}
int main()
{
    char str[] = "geeksforgeeks";
    cout <<"Second Max occurring character is "
         << getsecondMaxOccuringChar(str);
}