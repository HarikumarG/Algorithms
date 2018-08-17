#include<bits/stdc++.h>
using namespace std;
class kStacks
{
    int *arr;   //Array of size n to store actual content to be stored in stacks
    int *top;   //Array of size k to store indexes of top elements of stacks
    int *next;  //Array of size n to store next entry in all stacks and free lists
    int n,k;
    int free;   // To store beginning index of free list
public:

    kStacks(int k,int n);   //constructor to create k stacks in an array of size n
    void push(int item,int sn);  // To push an item in stack number 'sn' where sn is from 0 to k-1
    int pop(int sn);             // To pop an item in stack number 'sn' where sn is from 0 to k-1
    bool isFull()          // A utility function to check if there is space available
    {
        return(free==-1);
    }
    bool isEmpty(int sn)     // To check whether stack number 'sn' is empty or not
    {
        return(top[sn]==-1);
    }
};
kStacks :: kStacks(int k1,int n1)
    {
        k=k1;
        n=n1;
        arr= new int[n];
        top= new int[k];
        next= new int[n];
        free=0;
        for(int i=0;i<k;i++)    // Initialize all stacks as empty
        {
            top[i]=-1;
        }
        for(int j=0;j<n-1;j++)  // Initialize all spaces as free
        {
            next[j]=j+1;
        }
        next[n-1]=-1;           // -1 is used to indicate end of free list
    }
void kStacks :: push(int item,int sn)
{   
    if(isFull())
    {
        cout<<"Stack overflow";
        return;
    }

    int i = free;   // Store index of first free slot
    free = next[i];  // Update index of free slot to index of next slot in free list

     // Update next of top and then top for stack number 'sn'
    next[i] = top[sn];
    top[sn] = i;
    arr[i] = item;

}   
int kStacks :: pop(int sn)
{
    if(isEmpty(sn))
    {
        cout<<"Stack underflow";
        return -1;
        exit(0);
    }

    int i = top[sn];    // Find index of top item in stack number 'sn'
    top[sn] = next[i];  // Change top to store next of previous top

     // Attach the previous top to the beginning of free list
    next[i] = free;     
    free = i;

    return arr[i];
} 
int main()
{
    // Let us create 3 stacks in an array of size 10
    int k = 3, n = 10;
    kStacks ks(k, n);
 
    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);
 
    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
 
    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);
 
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
 
    return 0;
}