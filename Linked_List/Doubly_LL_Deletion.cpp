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

    void Delete_At_Head(){
        if(head == NULL){
            return;
        }
        sz--;
        node *b = head;
        head = b->next;
        head->prev = NULL;
        delete b;
        
    }

    void Delete_At_Any_Index(int pos){
        if(pos == 0){
            Delete_At_Head();
            return;
        }

        node *a = head;
        int go = 0;

        while(go < pos-1){
            a = a->next;
            go++;
        }

        node *b = a->prev;
        node *c = a->next;
        a->next = c->next;
        if(c->next != NULL) c->next->prev = a;
        delete c;
        sz--;
        if(pos == sz){
            tail = a;
        }
        
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
    cout << dl.getSize() << endl;

    dl.Delete_At_Head();
    dl.Traverse();
    dl.Reverse_Traverse();
    cout << dl.getSize() << endl;

    dl.Delete_At_Head();
    dl.Traverse();
    dl.Reverse_Traverse();
    cout << dl.getSize() << endl;

    dl.Delete_At_Head();
    dl.Traverse();
    dl.Reverse_Traverse();
    cout << dl.getSize() << endl;

    dl.Delete_At_Head();
    dl.Traverse();
    dl.Reverse_Traverse();
    cout << dl.getSize() << endl;

    //dl.Delete_At_Any_Index(2);
    // dl.Traverse();
    // dl.Reverse_Traverse();
    // cout << dl.getSize() << endl;

}