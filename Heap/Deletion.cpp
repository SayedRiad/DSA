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

    void down_heapify(int indx){
        while(1){
            int largest = indx;
            int left = 2*indx+1;
            int right = 2*indx+2;
            if(left<nodes.size() and nodes[left] > nodes[largest]){
                largest = left;
            }
            if(right<nodes.size() and nodes[right] > nodes[largest]){
                largest = right;
            }
            if(indx == largest) 
                break;
            swap(nodes[indx], nodes[largest]);
            indx = largest;
        }
    }

    void insert(int value){
        nodes.push_back(value);
        up_heapify(nodes.size()-1);
    }

    void delete_a_node(int indx){
        swap(nodes[indx], nodes.back());
        nodes.pop_back();
        down_heapify(indx);
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
    heap.delete_a_node(0);
    heap.Print_Heap();
}