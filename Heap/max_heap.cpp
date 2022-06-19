// Max Heap implementation using arrays
#include <iostream>
#include <vector>

using namespace std;

struct MaxHeap {
    
    int heapSize = 0;
    int noOfElements = 0;
    vector<int> heap;
    
    MaxHeap(int size) {    
        heapSize = size;
        heap.resize(heapSize+1);
        heap.shrink_to_fit();
        heap[0] = 0;
    }

    bool add(int element) {
        
        if(noOfElements + 1 > heapSize) {
            return false;
        }
        noOfElements++;

        heap[noOfElements] = element;

        int currIndex = noOfElements;
        int parentIndex = currIndex / 2;

        while(heap[currIndex] > heap[parentIndex] && currIndex > 1) {
            swap(heap[currIndex], heap[parentIndex]);
            currIndex = parentIndex;
            parentIndex = currIndex / 2;
        }

        return true;
    }

    bool pop() {

        cout<<noOfElements<<" ";
        if(noOfElements < 1) {
            return false;
        }

        heap[1] = heap[noOfElements];

        noOfElements--;

        int currIndex = 1;

        while(currIndex <= noOfElements/2) {
            int left = currIndex * 2;
            int right = (currIndex * 2) + 1;
            
            if(heap[currIndex] < heap[left] || heap[currIndex] < heap[right]) {
                if(heap[left] > heap[right]) {
                    int temp = heap[left];
                    heap[left] = heap[currIndex];
                    heap[currIndex] = temp;
                    currIndex = left;
                } else {
                    int temp = heap[right];
                    heap[right] = heap[currIndex];
                    heap[currIndex] = temp;
                    currIndex = right;
                }
            } else {
                break;
            }
        }
        return true;
    }

    int peek() {
        return heap[1];
    }

    int size() {
        return noOfElements;
    }
};

int main() {
    
    vector<int> arr = {3,2,3,1,2,4,5,5,6};
    int n = arr.size();

    MaxHeap *maxHeap = new MaxHeap(n);

    for(auto i : arr) {
        maxHeap->add(i);
    }

    maxHeap->pop();

    maxHeap->pop();

    maxHeap->pop();

    maxHeap->pop();

    cout<<maxHeap->peek()<<endl;

    return 0;
}