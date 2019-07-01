#include<bits/stdc++.h>
using namespace std;
vector<int> leftNode, rightNode;
int swapLevel;

void traverse(int node=1){
    if (node == -1) return;
    traverse(leftNode[node]);
    cout << node << " ";
    traverse(rightNode[node]);
	//    if (node == 1) cout << endl;
}

void swap(int level=1, int node=1) {
	if (node == -1) return;
	if (level % swapLevel == 0) {
		int tmp = leftNode[node];
		leftNode[node] = rightNode[node];
		rightNode[node] = tmp;
	}
	swap(level+1, leftNode[node]);
	swap(level+1, rightNode[node]);
}

int main() {
    int count;    
    cin>>count; //5
	leftNode.push_back(0);
    rightNode.push_back(0);
    while(count--){
        int L, R;
        cin>>L>>R;   // 2 3 , -1 4 , -1 5 , -1 -1 , -1 -1, 1   2
        leftNode.push_back(L);
        rightNode.push_back(R);
    }
    cin>>count;
    while(count--){
		cin >> swapLevel;
		swap();
		traverse();
		cout<<"\n";
	}
    return 0;
}
