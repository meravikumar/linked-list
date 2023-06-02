#include <iostream>
using namespace std;
class Node{
  public:
  int data;
  Node*next;
  Node(int data){
      this->data=data;
      this->next=NULL;
  }
};
void insertAtTail(Node* &tail,int d){
   //creating new node
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}


void insertAthead(Node* &head,int d){
    Node *temp=new Node(d);
    temp->next=head;
    head=temp;
}

void print(Node* &head){
    Node *temp=head;
    while(temp!=0){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node *node1=new Node(10);
   // cout<<node1->data<<endl;
   // cout<<node1->next<<endl;
    Node *head=node1;
     Node *tail=node1;
    print(head);
    insertAtTail(tail,12);
    print(head);
    insertAtTail(tail,15);
    print(head);
    
    return 0;
}
