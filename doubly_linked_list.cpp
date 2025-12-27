#include<iostream>
using namespace std;
class Node{
    public:

    int data;
    Node *next;
    Node *prev;
    Node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};


class Doublylist{
    public:
    Node *head = NULL;
    Node *tail = NULL;

    void push_front(int val){
        Node *newnode = new Node(val);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
    }

    void push_back(int val){
        Node *newnode = new Node(val);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }

    void pop_front(){
        if(head==NULL){
            return;
        }

        //only in doublt linked list 
        if(head == tail){
        delete head;
        head = NULL;
        tail = NULL;
        return;
        }

        Node *del = head;
        head = head->next;
        head->prev = NULL;
        delete del;
    }

    void display_L_R(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
     void display_R_L(){
        Node *temp=tail;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
    }


};



int main(){

    Doublylist list1;
    list1.push_front(10);
    list1.push_front(20);
    list1.push_front(30);
    list1.push_front(40);

    list1.push_back(5);
    list1.push_back(4);
    list1.push_back(3);
    list1.push_back(2);
    list1.push_back(1);

    list1.display_L_R();
    cout<<endl;
    list1.display_R_L();
    
   

return 0;
}