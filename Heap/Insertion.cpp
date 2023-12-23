#include<bits/stdc++.h>
using namespace std;

class Max_Heap{
    public:
    vector<int> nodes;

    Max_Heap(){

    }

    void up_heapify(int indx){
        while(indx > 0 and nodes[indx] > nodes[(indx-1)/2]){
            swap(nodes[indx], nodes[(indx-1)/2]);
            indx = (indx-1)/2;
        }
    }

    void insert(int value){
        nodes.push_back(value);
        up_heapify(nodes.size()-1);
    }

    void Print_Heap(){
        for(auto val: nodes){
            cout << val << ' ';
        }
        cout << endl;
    }
};

int main(){
    Max_Heap heap;
    heap.insert(5);
    heap.insert(5);
    heap.insert(7);
    heap.insert(50);
    heap.insert(15);
    heap.insert(5);
    heap.insert(2);

    heap.Print_Heap();
}