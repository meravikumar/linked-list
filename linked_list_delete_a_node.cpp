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
  ~Node(){
      int value=this->data;
      if(this->next!=NULL){
          delete next;
          next=NULL;
          
      }
      cout<<"memory is freed for data:"<<value<<endl;
  }
};

void insertAtHead(Node* &head,int d){
    Node *temp=new Node(d);
    temp->next=head;
    head=temp;
}

void insertAtTail(Node* &tail,int d){
    Node *temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void insertAtPosition(Node* &tail,Node* &head,int pos,int d){
    //insertion at poaition 1
    if(pos==1){
        insertAtHead(head,d);
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
        insertAtTail(tail,d);
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
//deleting node
void deleteNode(int position,Node* &head){
   //deletion at head 
    if(position==1){
        Node*temp=head;
        head=head->next;
        temp->next=NULL;
        delete  temp;    // destructor call to free memory
    }
    else{
        Node* curr=head;
        Node*prev=NULL;
        int cnt=1;
        while(cnt<position){
          prev=curr;
          curr=curr->next;
          cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

int main()
{
    Node *node1=new Node(10);
   // cout<<node1->data<<endl;
    Node *head=node1;
    Node *tail=node1;
    print(head);
    insertAtTail(tail,12);
    print(head);
    insertAtTail(tail,15);
    print(head);
    insertAtPosition(tail,head,4,22);
    print(head);

deleteNode(3,head);
print(head);
cout<<"head="<<head->data<<endl;
cout<<"tail="<<tail->data<<endl;;
    return 0;
}


