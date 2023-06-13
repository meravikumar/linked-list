
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

void insertAtHead(Node* &tail,Node* &head,int d){
    if(head==NULL){
        Node *temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
    Node* temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
    temp->prev=NULL;
    }
}


void insertAtTail(Node* &tail,Node* &head,int d){
    if(tail==NULL){
        Node*temp=new Node(d);
        tail=temp;
        head=temp;
    }
    else{
    Node*temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    temp->next=NULL;
    }
}

void insetAtPosition(Node* &tail,Node* &head,int position,int d){
    if(position==1){
        insertAtHead(tail,head,d);
        return ;
    }
    Node *temp=head;
    int cnt=1;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(tail,head,d);
        return ;
    }
    
    Node *nodeToInsert=new Node(d);
    nodeToInsert->next=temp->next;
    temp->next->prev=nodeToInsert;
    temp->next=nodeToInsert;
    nodeToInsert->prev=temp;
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
  // Node*node1=new Node(10);
   /*Node *head=node1;
   Node *tail=node1;
   */
   Node *head=NULL;
   Node *tail=NULL;
   
   print(head);
   //cout<<"length="<<getLength(head)<<endl;
   insertAtHead(tail,head,12);
   print(head);
   insertAtHead(tail,head,23);
   print(head);
   insertAtHead(tail,head,9);
   print(head);
   insertAtTail(tail,head,100);
   print(head);
   insetAtPosition(tail,head,5,500);
   print(head);
   cout<<"tail="<<tail->data<<endl;
   cout<<"head="<<head->data;
    return 0;
}





