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

    int Searching_Distinct_Value(int value){
        node *a = head;
        int index = 0;
        while(a != NULL){
            if(a->data == value){
                return index;
            }
            a = a->next;
            index++;
        }
        return -1;
    }
};

int main(){
    Linked_List list;

    int x;
    cin >> x;
    
    list.Insert_At_Head(36);
    list.Insert_At_Head(27);
    list.Insert_At_Head(18);
    list.Insert_At_Head(9);

    list.Traverse();

    int res = list.Searching_Distinct_Value(x);
    if(res == -1)
        cout << "Value is not found\n";
    else
        cout << "Value is found at index: " << res;
}