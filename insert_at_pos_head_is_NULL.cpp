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

void insertAtHead(Node* &tail,Node* &head,int d){
    if(head==NULL){
        Node*temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
    Node *temp=new Node(d);
    temp->next=head;
    head=temp;
    }
}

void insertAtTail(Node* &tail,Node* &head,int d){
    if(tail==NULL){
        Node *temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else{
    Node *temp=new Node(d);
    tail->next=temp;
    tail=temp;
    }
}
void insertAtPosition(Node* &tail,Node* &head,int pos,int d){
    //insertion at poaition 1
    if(pos==1){
        insertAtHead(tail,head,d);
        return ;
    }
    Node *temp=head;
    int cnt=1;
    while(cnt<pos-1){
        temp=temp->next;
        cnt++;
        
    }
    //insertion at last insertAtPosition
    if(temp->next==NULL){
        insertAtTail(tail,head,d);
        return ;
    }
    Node* nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}

void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    //Node *node1=new Node(10);
   // cout<<node1->data<<endl;
    Node *head=NULL;
    Node *tail=NULL;
    print(head);
    insertAtTail(tail,head,12);
    print(head);
     insertAtTail(tail,head,15);
    print(head);
    insertAtTail(tail,head,17);
    print(head);
    insertAtPosition(tail,head,4,22);
    print(head);
cout<<"head="<<head->data<<endl;
cout<<"tail="<<tail->data;
    return 0;
}

