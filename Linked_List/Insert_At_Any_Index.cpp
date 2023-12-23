#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *next;
};

class Linked_List{
    public:
    node *head;

    Linked_List(){
        head = NULL;
    }

    node* Create_new_node(int value){
        node *newnode = new node;
        newnode->data = value;
        newnode->next = NULL;
        return newnode;
    }

    void Insert_At_Head(int value){
        node *a = Create_new_node(value);

        if(head == NULL){
            head = a;
            return;
        }

        a->next = head;
        head = a;
    }

    void Insert_At_Any_Index(int pos, int value){
        if(pos == 0){
            Insert_At_Head(value);
            return;
        }

        node *b = Create_new_node(value);
        node *a = head;
        int go = 0;

        while(go < pos-1){
            a = a->next;
            go++;
        }

        b->next = a->next;
        a->next = b;
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
    Linked_List list;

    // list.Insert_At_Head(36);
    // list.Insert_At_Head(27);
    // list.Insert_At_Head(18);
    // list.Insert_At_Head(9);
    // list.Traverse();
    // list.Insert_At_Any_Index(1,10);
    // list.Traverse();
    // list.Insert_At_Any_Index(2,15);
    // list.Traverse();
    // list.Insert_At_Any_Index(5,150);
    // list.Traverse();
    // list.Insert_At_Any_Index(4,115);
    // list.Traverse();
    // list.Insert_At_Any_Index(0,15);
    // list.Traverse();
    // list.Insert_At_Any_Index(8,360);
    // list.Traverse();
    // list.Insert_At_Any_Index(10,1800);
    // list.Traverse();
    
    list.Insert_At_Head(15);
    list.Insert_At_Head(10);
    list.Insert_At_Head(5);
    //list.Traverse();
    list.Insert_At_Any_Index(3,20);
    list.Traverse();
}