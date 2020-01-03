#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
const int MAX_CHAR = 26;
int main()
{
	string res;
	string line;
	ifstream myfile("input.txt");
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			res += line;
		}
		myfile.close();
	}
    int a[res.length()];
    for(int i = 0; i < res.length(); i++)
    {
        stringstream geek(res);
        geek >> a[i];
    }
       
	ofstream file("output.txt");
	if(file.is_open())
	{
		int i = 0;
		while(res[i] != '\0')	
		{
			file << res[i];
			file << "\n";
			i++;
		}
		file.close();
	}
	return 0;
}
