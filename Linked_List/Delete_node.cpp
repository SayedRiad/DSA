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

    void Delete_At_Head(){
        if(head == NULL) 
            return;

        node *a = head;
        head = a->next;
        delete a;
    }

    void Delete_At_Any_Index(int pos){
        if(pos == 0){
            Delete_At_Head();
            return;
        }

        int cur_indx = 0;
        node *a = head;
        while(cur_indx < pos-1){
            a = a->next;
            cur_indx++;
        }

        node *b = a->next;
        a->next = b->next;
        delete b;
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
    list.Insert_At_Head(25);
    list.Insert_At_Head(20);
    list.Insert_At_Head(15);
    list.Insert_At_Head(10);
    list.Insert_At_Head(5);
    list.Traverse();
    list.Delete_At_Head();
    list.Traverse();
    list.Delete_At_Any_Index(0);
    list.Traverse();
    list.Delete_At_Any_Index(2);
    list.Traverse();
}