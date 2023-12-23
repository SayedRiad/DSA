#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *prev;
};

class Doubly_linked_list{
    public:
    node *head;
    node *tail;
    int sz;

    Doubly_linked_list(){
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    node* Create_new_node(int value){
        node *newnode = new node;
        newnode->prev = NULL;
        newnode->data = value;
        newnode->next = NULL;
        return newnode;
    }

    void Insert_At_Head(int value){
        node *a = Create_new_node(value);
        sz++;

        if(head == NULL){
            head = a;
            tail = a;
            return;
        }

        a->next = head;
        head->prev = a;
        head = a;
    }

    void Reverse(){
        if(head == NULL){
            return;
        }

        node *a = head;
        while(a != NULL){
            swap(a->next, a->prev);
            a = a->prev;
        }
        head = tail;
    }

    void Traverse(){
        node *a = head;

        while(a != NULL){
            cout << a->data << ' ';
            a = a->next;
        }
        cout << endl;
    }

};

int main(){
    Doubly_linked_list dl;
    dl.Insert_At_Head(15);
    dl.Insert_At_Head(150);
    dl.Insert_At_Head(10);
    dl.Insert_At_Head(5);
    dl.Traverse();

    dl.Reverse();
    dl.Traverse();
    //cout << dl.head->data <<" "<<dl.tail->data<<" "<<dl.sz;
    
}