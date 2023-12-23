#include<bits/stdc++.h>
using namespace std;

class Max_Heap{
    public:
    vector<int> nodes;

    void down_heapify(int indx){
        while(1){
            int largest = indx;
            int left = 2*indx + 1;
            int right = 2*indx + 2;

            if(left < nodes.size() && nodes[largest] < nodes[left]){
                largest = left;
            }
            if(right < nodes.size() && nodes[largest] < nodes[right]){
                largest = right;
            }
            if(indx == largest)
                break;
            swap(nodes[largest], nodes[indx]);
            indx = largest;
        }
    }

    void build_heap_from_array(vector<int> &a){
        nodes = a;
        int n = a.size();
        int last_non_leaf = n/2 - 1;
        for(int i=last_non_leaf;i>=0;i--){
            down_heapify(i);
        }
    }

    void Print_Heap(){
        for(auto val:nodes)
            cout << val << ' ';
        cout << endl;
    }
};

int main(){
    Max_Heap hp;
    vector<int> a = {1,2,3,4,10,9,8,7};
    hp.build_heap_from_array(a);
    hp.Print_Heap();
}