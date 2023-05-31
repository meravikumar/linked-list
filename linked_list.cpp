#include <bits/stdc++.h>

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

// to check circular or not
/*bool check(Node*head){
    if(head==NULL){
        return true;
    }
    
    Node*temp=head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    
    if(temp==head){
        return true;
    }
    else{
        return false;
    }
}
*/



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
    
    // to check whether ll is circular or not 
    
   /* if(check(tail)){
      cout<<"circular"<<endl;
  }
  else{
     cout<<"Not circular"<<endl; 
  }
  */
cout<<head->data<<endl;
cout<<tail->data;
    return 0;
}



