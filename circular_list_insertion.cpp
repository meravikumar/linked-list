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
  ~Node(){
      int value=this->data;
      if(this->next=NULL){
          delete next;
          next=NULL;
      }
      cout<<"Memory is free for node with data:"<<value<<endl;
  }
  
};

void print(Node* &tail){
    Node*temp=tail;
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }
    while(tail!=temp);
    cout<<endl;
    
}
/*bool circularCheck(Node*head){
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


// check wether linked list is circular or not  #using map
bool circularCheck(Node*head){
    if(head==NULL){
        return false;
    }
    map<Node*,bool>visited;
    Node*temp=head;
    while(temp!=NULL){
        if(visited[temp]==true){
            return true;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    
    return false;
    
    
}







void insertNode(Node* &tail,int element,int d){
    if(tail==NULL){
        Node *newNode=new Node(d);
        tail=newNode;
        newNode->next=newNode;
    }
    else {
        Node *curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        Node*temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}
int main()
{
   Node*tail=NULL;
   insertNode(tail,5,3);
   print(tail);
   insertNode(tail,3,5);
   print(tail);
   insertNode(tail,5,7);
   print(tail);
   insertNode(tail,7,9);
   print(tail);
   insertNode(tail,5,6);
   print(tail);
   insertNode(tail,9,10);
   print(tail);
   insertNode(tail,3,4);
   print(tail);
  if(circularCheck(tail)){
      cout<<"circular"<<endl;
  }
  else{
     cout<<"Not circular"<<endl; 
  }
  //cout<<"head="<<head->data<<endl;
  cout<<"tail="<<tail->data;
    return 0;
}


 




