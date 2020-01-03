#include<bits/stdc++.h>
using namespace std;
struct student
{
	int rno;
	string name;
};
void display(student *s)
{
	cout<<s->rno<<" "<<s->name;
	(*s).name = "ravi";
}
int main()
{
	struct student v;
	v.rno = 1;
	v.name = "hari";
	struct student *s;
	s = &v;	
	display(s);
	cout<<(*s).name;
	return 0;
}
