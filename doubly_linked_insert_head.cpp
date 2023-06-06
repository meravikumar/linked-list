
#include <iostream>

using namespace std;
class Node{
    public:
    int data;
    Node*prev;
    Node*next;
    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
};
void print(Node* head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void insertAtHead(Node* &head,int d){
    
    Node* temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
}

int getLength(Node*head){
    Node*temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}

int main()
{
   Node*node1=new Node(10);
   Node *head=node1;
   print(head);
   //cout<<"length="<<getLength(head)<<endl;
   insertAtHead(head,12);
   print(head);
   insertAtHead(head,23);
   print(head);
   insertAtHead(head,9);
   print(head);
    return 0;
}
