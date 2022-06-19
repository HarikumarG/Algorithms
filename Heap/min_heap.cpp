// Min Heap implementation using arrays
#include <iostream>
#include <vector>

using namespace std;

struct MinHeap {
    
    int heapSize = 0;
    int noOfElements = 0;
    vector<int> heap;
    
    MinHeap(int size) {    
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

        while(heap[currIndex] < heap[parentIndex] && currIndex > 1) {
            swap(heap[currIndex], heap[parentIndex]);
            currIndex = parentIndex;
            parentIndex = currIndex / 2;
        }

        return true;
    }

    bool pop() {

        if(noOfElements < 1) {
            return false;
        }

        heap[1] = heap[noOfElements];

        noOfElements--;

        int currIndex = 1;

        while(currIndex <= noOfElements/2) {
            int left = currIndex * 2;
            int right = (currIndex * 2) + 1;
            
            if(heap[currIndex] > heap[left] || heap[currIndex] > heap[right]) {
                if(heap[left] < heap[right]) {
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
    
    MinHeap *minHeap = new MinHeap(3);

    cout<<"[add]: "<<minHeap->add(3)<<endl;
    cout<<"[add]: "<<minHeap->add(1)<<endl;
    cout<<"[add]: "<<minHeap->add(2)<<endl;

    cout<<"[top]: "<<minHeap->peek()<<endl;

    cout<<"[pop]: "<<minHeap->pop()<<endl;

    cout<<"[top]: "<<minHeap->peek()<<endl;

    cout<<"[size]: "<<minHeap->size()<<endl;

    return 0;
}