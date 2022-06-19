//(Round B 2021) https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435a5b/000000000077a3a5

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int from, to, diff;
    Node(int f, int t, int d) {
        from = f;
        to = t;
        diff = d;
    }
};

int longProg(vector<int>arr, int n) {
    vector<Node*> store;
    int prev, curr, from, to;
    bool isFirst = true;
    for(int i = 1; i <= n; i++) {
        if(i == n) {
            store.push_back(new Node(from, to, prev));
            break;
        }
        if(isFirst) {
            from = i-1;
            to = i;
            prev = arr[i-1] - arr[i];
            isFirst = false;
            continue;
        }
        curr = arr[i-1] - arr[i];
        if(prev == curr) {
            to = i;
        } else {
            store.push_back(new Node(from, to, prev));
            prev = curr;
            from = i-1;
            to = i;
        }
    }

    int result = 0, currLen = 0, i, c, temp;
    for(auto st : store) {
        currLen = st->to - st->from + 1;
        i = st->from-1;
        // for(int i = st->from-1; i >= 0; i--) {
        if(i >= 0) {
            temp = arr[i];
            arr[i] = arr[st->from] + st->diff;
            c = 1;
            for(int j = i-1; j >= 0; j--) {
                if(arr[j] - arr[j+1] != st->diff) {
                    break;
                }
                c++;
            }
            currLen += c;
            arr[i] = temp;
        }
        // }
        result = max(result, currLen);
        // cout<<endl<<"Left "<<st->from<<" "<<st->to<<" "<<st->diff<<" "<<currLen<<" "<<result<<endl;
        currLen = st->to - st->from + 1;
        i = st->to+1;
        // for(int i = st->to+1; i < n; i++) {
        if(i < n) {
            temp = arr[i];
            arr[i] = arr[st->to] - st->diff;
            c = 1;
            for(int j = i+1; j < n; j++) {
                if(arr[j-1] - arr[j] != st->diff) {
                    break;
                }
                c++;
            }
            currLen += c;
            arr[i] = temp;
        }
        // }
        result = max(result, currLen);
        // cout<<endl<<"Right "<<st->from<<" "<<st->to<<" "<<st->diff<<" "<<currLen<<" "<<result<<endl;
        currLen = 0;
    }
    return result;
}

int main() {
    int t, ct = 1;
    cin>>t;
    while(ct <= t) {
        int n, v;
        vector<int>arr;
        cin>>n;
        for(int i = 0; i < n; i++) {
            cin>>v;
            arr.push_back(v);
        }
        cout<<"Case #"<<ct<<": "<<longProg(arr, n)<<endl;
        ct++;
    }
    return 0;
}
