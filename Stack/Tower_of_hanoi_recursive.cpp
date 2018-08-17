#include<bits/stdc++.h>
using namespace std;
void tower(int n,char from,char to,char aux)
{
	if(n==1)
	{
		cout<<"\nMove disk 1 from "<<from<<" to "<<to;
	}
	else
	{
		tower(n-1,from,aux,to);
		cout<<"\nMove disk "<<n<<" from "<<from<<" to "<<to;
		tower(n-1,aux,from,to);
	}
}
int main()
{
	int n=3;
	tower(n,'A','C','B');
	return 0;
}