#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int main()
{
	int pval=1;
	int star=0;
	int in=3;
	for(int i=0;i<in;i++)
	{
		string pstr;
		star=i;
		for(int j=0;j<=i;j++)
		{
			pval++;
			char *intr=itoa(pval,NULL,NULL);
			pstr=string(intr);
			if(star>0)
			{
				//pstr=pstr+"*";
				star--;
			}
		}
		cout<<"\n"<<pstr;
	}
	return 0;
}
