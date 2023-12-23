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

    void Insert_At_Any_Index(int pos, int value){
        if(pos == 0){
            Insert_At_Head(value);
            return;
        }

        node *a = Create_new_node(value);
        node *current = head;
        int go = 0;

        while(go < pos-1){
            current = current->next;
            go++;
        }

        a->prev = current;
        a->next = current->next;
        current->next = a;
        if(a->next != NULL) a->next->prev = a;

        if(pos == sz){
            tail = a;
        }
        sz++;
    }

    void Traverse(){
        node *a = head;

        while(a != NULL){
            cout << a->data << ' ';
            a = a->next;
        }
        cout << endl;
    }

    void Reverse_Traverse(){
        node *a = tail;

        while(a != NULL){
            cout << a->data << ' ';
            a = a->prev;
        }
        cout << endl;
    }

    int getSize(){
        return sz;
    }
};

int main(){
    Doubly_linked_list dl;
    dl.Insert_At_Head(15);
    dl.Insert_At_Head(150);
    dl.Insert_At_Head(10);
    dl.Insert_At_Head(5);
    dl.Traverse();
    dl.Reverse_Traverse();
    dl.Insert_At_Any_Index(1, 7);
    dl.Insert_At_Any_Index(0, 2);
    dl.Insert_At_Any_Index(6, 20);
    dl.Traverse();
    dl.Reverse_Traverse();
}