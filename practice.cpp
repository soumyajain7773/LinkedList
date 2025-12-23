#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class list{
    public:
    Node *head;
    Node *tail;

    list(){
        head=NULL;
        tail=NULL;
    }

    void add_front(int val){
        Node *newnode = new Node(val);
        if(head==NULL){
            head=newnode;
            tail=newnode;
            return;
        }
        newnode->next=head;
        head=newnode;
    }

    void add_back(int val){
        Node *newnode = new Node(val);
        if(tail==NULL){
            tail=newnode;
            head=newnode;
            return ;
        }
        tail->next=newnode;
        tail=newnode;
    }

    void pop_front(){
        Node *temp=head;
        if(head==NULL){
            cout<<"linklist not exist";
            return;
        }
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    void pop_back(){
        Node *temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
    }

    void display(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }


};
int main(){

    list l1;
    
    l1.add_front(1);
    l1.add_front(2);
    l1.add_front(3);
    l1.add_front(4);
    l1.add_front(5);
    l1.add_front(6);

    l1.display();
    cout<<endl;

    l1.add_back(0);
    l1.add_back(-1);
    l1.add_back(-2);
    l1.add_back(-3);

    l1.display();
    cout<<endl;

    l1.pop_back();
    l1.pop_front();

    l1.display();
    cout<<endl;
   

return 0;
}