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

    list.Insert_At_Head(36);
    list.Insert_At_Head(27);
    list.Insert_At_Head(18);
    list.Insert_At_Head(9);

    list.Traverse();

}