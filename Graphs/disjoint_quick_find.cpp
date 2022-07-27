#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
    private:
        vector<int> root;
        int size = 0;
    public:
        UnionFind(int size) {
            this->size = size;
            root.resize(size);
            root.shrink_to_fit();
            for(int i = 0; i < size; i++) {
                root[i] = i;
            }
        }
        int find(int vertex) {
            return root[vertex];
        }
        bool isConnected(int vertexA, int vertexB) {
            return root[vertexA] == root[vertexB];
        }
        void setUnion(int vertexA, int vertexB) {
            int rootA = find(vertexA);
            int rootB = find(vertexB);

            if(rootA != rootB) {
                for(int i = 0; i < this->size; i++) {
                    if(root[i] == rootB) {
                        root[i] = rootA;
                    }
                }
            }
        }
};

int main() {
    UnionFind uf(10);
    // 1-2-5-6-7 3-8-9 4
    uf.setUnion(1, 2);
    uf.setUnion(2, 5);
    uf.setUnion(5, 6);
    uf.setUnion(6, 7);
    uf.setUnion(3, 8);
    uf.setUnion(8, 9);
    cout << uf.isConnected(1, 5) << endl;  // true
    cout << uf.isConnected(5, 7) << endl;  // true
    cout << uf.isConnected(4, 9) << endl;  // false
    // 1-2-5-6-7 3-8-9-4
    uf.setUnion(9, 4);
    cout << uf.isConnected(4, 9) << endl;  // true

    return 0;
}