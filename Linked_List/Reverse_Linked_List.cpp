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

    void Reverse_Linked_List(){
        node *current = head;
        node *prev = NULL;
        node *next = NULL;

        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
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
    
    list.Insert_At_Head(15);
    list.Insert_At_Head(10);
    list.Insert_At_Head(5);
    list.Insert_At_Head(50);
    
    list.Traverse();
    list.Reverse_Linked_List();
    list.Traverse();
}